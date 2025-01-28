cmake_minimum_required(VERSION 3.10)
project(PasswordCrackerClient)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenSSL REQUIRED)

add_executable(client
    src/client.cpp
)

target_include_directories(client PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(client PRIVATE 
    OpenSSL::SSL 
    OpenSSL::Crypto 
    pthread
)