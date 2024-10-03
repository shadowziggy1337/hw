#!/bin/bash

rm -rf bin
rm -rf obj
mkdir -p bin
mkdir -p obj
g++ -Wall -g -O0 -c -Iinclude -o obj/Engine.o src/Engine.cpp
g++ -Wall -g -O0 -c -Iinclude -o obj/Passenger.o src/Passenger.cpp
g++ -Wall -g -O0 -c -Iinclude -o obj/Car.o src/Car.cpp
g++ -g -O0 -o bin/main obj/Engine.o obj/Passenger.o obj/Car.o obj/main.o
