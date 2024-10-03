#!/bin/bash

rm -rf bin
rm -rf obj
mkdir -p bin
mkdir -p obj
g++ -Wall -g -O0 -c -Iinclude -o obj/BankAccount.o src/BankAccount.cpp
g++ -Wall -g -O0 -c -Iinclude -o obj/main.o src/main.cpp
g++ -g -O0 -o bin/main obj/BankAccount.o obj/main.o
