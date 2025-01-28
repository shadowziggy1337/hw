#include "client.hpp"
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <openssl/evp.h>

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
    if(inet_pton(AF_INET, master_ip.c_str(), &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Установка соединения
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection Failed" << std::endl;
        exit(EXIT_FAILURE);
    }
}

std::string compute_md5(const std::string& input) {
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digest_len;
    
    EVP_DigestInit_ex(context, EVP_md5(), NULL);
    EVP_DigestUpdate(context, input.c_str(), input.size());
    EVP_DigestFinal_ex(context, digest, &digest_len);
    EVP_MD_CTX_free(context);

    char mdString[33];
    for(unsigned int i = 0; i < digest_len; i++)
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
    
    return std::string(mdString);
}

void WorkerClient::start_working() {
    // Реализация логики работы воркера
    while(true) {
        // Получение задач от сервера
        // Обработка задач
        // Отправка результатов
    }
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <master_ip> <port>" << std::endl;
        return 1;
    }

    WorkerClient client(argv[1], std::stoi(argv[2]));
    client.connect_to_master();
    client.start_working();
    
    return 0;
}