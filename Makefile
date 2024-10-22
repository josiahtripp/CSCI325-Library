#Makefile used to build a test executible for CSCI325 Assignment: Library

#Define compilation variables
CC = g++
CFLAGS = -Wall -Wextra
BINARY = library

default: Library

Library:
	$(CC) $(CFLAGS) -c main.cpp Library.cpp
	$(CC) $(CFLAGS) -o $(BINARY) main.o Library.o

clean:
	$(RM) *.o *~ test