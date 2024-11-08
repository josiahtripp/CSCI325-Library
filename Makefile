#Makefile used to build a test executible for CSCI325 Assignment: Library

#Define compilation variables
CC = g++
CFLAGS = -Wall -Wextra
BINARY = library

default: Library

Library: main.o Library.o
	$(CC) $(CFLAGS) -o $(BINARY) main.o Library.o

main.o:
	$(CC) $(CFLAGS) -c main.cpp

Library.o:
	$(CC) $(CFLAGS) -c Library.cpp

clean:
	$(RM) *.o *~ test