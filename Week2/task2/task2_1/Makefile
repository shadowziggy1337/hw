SHELL=/bin/bash
INC=-Iinclude
CC=g++

all: clean prepare build

clean:
	rm -rf bin/*
	rm -rf obj/*

prepare:
	mkdir -p bin
	mkdir -p obj

build:
	$(CC) -Wall -g -O0 -c $(INC) -o obj/Student.o src/Student.cpp
	$(CC) -Wall -g -O0 -c $(INC) -o obj/main.o src/main.cpp
	$(CC) -g -O0 -o bin/main.p obj/Student.o obj/main.o

run: all
	./bin/main

.PHONY: all clean prepare build run
