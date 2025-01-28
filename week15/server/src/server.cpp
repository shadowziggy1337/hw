#include "server.hpp"
#include <iostream>
#include <unistd.h>
#include <thread>
#include <openssl/evp.h>
#include <sstream>
#include <cstring>
#include <arpa/inet.h>
#include <iomanip>  
#include <stdexcept> 

MasterServer::MasterServer(int port, const std::string& target_hash) 
    : target_hash(target_hash) {
    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        throw std::runtime_error("Socket creation failed");
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        close(server_fd);
        throw std::runtime_error("Setsockopt failed");
    }

    // Bind socket
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        close(server_fd);
        throw std::runtime_error("Bind failed");
    }
}

void MasterServer::run() {
    // Start listening
    if (listen(server_fd, 5) < 0) {
        close(server_fd);
        throw std::runtime_error("Listen failed");
    }

    std::cout << "Server started on port " << ntohs(address.sin_port) << std::endl;

    // Main server loop
    while (!password_found) {
        sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_socket = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
        
        if (client_socket < 0) {
            if (password_found) break; // Exit on stop condition
            std::cerr << "Accept failed" << std::endl;
            continue;
        }

        // Handle client in a new thread
        std::thread([this, client_socket]() {
            this->handle_client(client_socket);
            close(client_socket);
        }).detach();
    }
    
    stop_server();
}

std::string MasterServer::generate_task() {
    std::lock_guard<std::mutex> lock(task_mutex);
    // Simple task generation logic (example)
    static char current_char = 'a';
    if (current_char > 'z') return "";
    
    std::string task(1, current_char);
    current_char++;
    return task;
}

void MasterServer::handle_client(int client_socket) {
    try {
        while (!password_found) {
            // Send task to client
            std::string task = generate_task();
            if (task.empty()) {
                send(client_socket, "STOP", 4, 0);
                break;
            }
            
            send(client_socket, task.c_str(), task.size(), 0);

            // Receive result
            char buffer[1024] = {0};
            ssize_t bytes_read = recv(client_socket, buffer, sizeof(buffer), 0);
            if (bytes_read <= 0) break;

            std::string result(buffer, bytes_read);
            if (result != "NOTFOUND") {
                std::lock_guard<std::mutex> lock(task_mutex);
                password_found = true;
                found_password = result;
                std::cout << "Password found: " << result << std::endl;
                break;
            }
        }
    } catch (...) {
        std::cerr << "Error handling client" << std::endl;
    }
}

void MasterServer::stop_server() {
    close(server_fd);
    std::cout << "Server stopped" << std::endl;
}

std::string compute_md5(const std::string& input) {
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digest_len;

    if (!context) return "";

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