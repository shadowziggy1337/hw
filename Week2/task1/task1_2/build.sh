#!/bin/bash

rm -rf bin
rm -rf obj
mkdir -p bin
mkdir -p obj
g++ -Wall -g -O0 -c -Iinclude -o obj/Octagon.o src/Octagon.cpp
g++ -Wall -g -O0 -c -Iinclude -o obj/main.o src/main.cpp
g++ -g -O0 -o bin/main.p obj/Octagon.o obj/main.o