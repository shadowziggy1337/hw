#!/bin/bash

rm -rf bin
rm -rf obj
mkdir -p bin
mkdir -p obj
g++ -Wall -g -O0 -c -Iinc -o obj/Keyboard.o src/Keyboard.cpp
g++ -Wall -g -O0 -c -Iinc -o obj/main.o src/main.cpp
g++ -g -O0 -o bin/main.p obj/Keyboard.o obj/main.o