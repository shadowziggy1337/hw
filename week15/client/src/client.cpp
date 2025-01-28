#include "client.hpp"
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <openssl/evp.h>
#include <atomic>
#include <string>
#include <sstream>
#include <iomanip>

WorkerClient::WorkerClient(const std::string& master_ip, int port) 
    : master_ip(master_ip), master_port(port) {}

void WorkerClient::connect_to_master() {
    struct sockaddr_in serv_addr;

    // Создание сокета
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Socket creation error" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Настройка адреса сервера
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(master_port);

    // Преобразование IP-адреса
    if (inet_pton(AF_INET, master_ip.c_str(), &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Установка соединения
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection Failed" << std::endl;
        exit(EXIT_FAILURE);
    }
}

std::string WorkerClient::compute_md5(const std::string& input) {
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digest_len;

    EVP_DigestInit_ex(context, EVP_md5(), nullptr);
    EVP_DigestUpdate(context, input.c_str(), input.size());
    EVP_DigestFinal_ex(context, digest, &digest_len);
    EVP_MD_CTX_free(context);

    std::ostringstream oss;
    for (unsigned int i = 0; i < digest_len; i++) {
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)digest[i];
    }
    return oss.str();
}

bool WorkerClient::increment_password(std::string& password) {
    for (int i = password.size() - 1; i >= 0; --i) {
        if (password[i] < 'z') {
            password[i]++;
            return true;
        }
        password[i] = 'a'; // Сброс к 'a' если достигли 'z'
    }
    return false; // Все символы были 'z'
}

void WorkerClient::start_working() {
    char buffer[1024] = {0};

    // Получение хеша от сервера
    ssize_t bytes_read = recv(sock, buffer, sizeof(buffer), 0);
    if (bytes_read <= 0) {
        std::cerr << "Server disconnected or error receiving data" << std::endl;
        return;
    }

    std::string target_hash(buffer, bytes_read);
    std::cout << "Target MD5 hash received: " << target_hash << std::endl;

    while (true) {
        // Получение диапазона от сервера
        memset(buffer, 0, sizeof(buffer));
        bytes_read = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes_read <= 0) {
            std::cerr << "Server disconnected or error receiving range" << std::endl;
            break;
        }

        int range = std::stoi(std::string(buffer, bytes_read));
        std::cout << "Received password range: " << range << std::endl;

        // Перебор паролей заданной длины
        if (range > 8) {
            std::cout << "Maximum range reached. Disconnecting client." << std::endl;
            break;
        }

        // Перебор паролей длиной `range` символов
        std::string password;
        for (int i = 0; i < range; ++i) {
            password += 'a'; // Начинаем с 'aaaa...'
        }

        while (true) {
            std::string hashed_password = compute_md5(password);
            // Убрали вывод текущего пароля
            // std::cout << "Trying password: " << password << " -> " << hashed_password << std::endl;

            // Проверка на совпадение с хешем
            if (hashed_password == target_hash) {
                std::cout << "Password found: " << password << std::endl;
                send(sock, password.c_str(), password.size(), 0); // Отправка найденного пароля на сервер
                return;
            }

            // Генерация следующего пароля (алгоритм инкремента)
            if (!increment_password(password)) break; // Если не удалось увеличить, выходим из цикла
        }

        // Если не нашли пароль, сообщаем серверу
        send(sock, "NOTFOUND", 8, 0);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <master_ip> <port>" << std::endl;
        return 1;
    }

    WorkerClient client(argv[1], std::stoi(argv[2]));
    client.connect_to_master();
    client.start_working();

    return 0;
}
