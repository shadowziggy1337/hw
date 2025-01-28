cmake_minimum_required(VERSION 3.10)
project(PasswordCrackerServer)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenSSL REQUIRED)

add_executable(server
    src/main.cpp
    src/server.cpp
)

target_include_directories(server PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(server PRIVATE 
    OpenSSL::SSL 
    OpenSSL::Crypto
)