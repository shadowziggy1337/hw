#!/bin/bash

rm -rf bin
rm -rf obj
mkdir -p bin
mkdir -p obj
g++ -Wall -g -O0 -c -Iinclude -o obj/Author.o src/Author.cpp
g++ -Wall -g -O0 -c -Iinclude -o obj/Book.o src/Book.cpp
g++ -Wall -g -O0 -c -Iinclude -o obj/main.o src/main.cpp
g++ -g -O0 -o bin/main.p obj/Author.o obj/Book.o obj/main.o
