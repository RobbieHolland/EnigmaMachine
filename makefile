# edit this makefile so that running make compiles your enigma program
all: enigma

CC = g++
version = -std=c++11
flags = $(version) -c
command = $(CC) $(flags)

enigma: Main.o util.o segment.o rotor.o plugboard.o reflector.o machine.o
	$(CC) -o enigma $(version) Main.o util.o segment.o rotor.o plugboard.o reflector.o machine.o

Main.o: Main.cpp util.cpp *.cpp *.hpp
	$(command) Main.cpp util.cpp

util.o: util.cpp
	$(command) util.cpp

segment.o: segment.cpp util.cpp
	$(command) segment.cpp util.cpp

rotor.o: rotor.cpp util.cpp segment.cpp
	$(command) rotor.cpp util.cpp segment.cpp

plugboard.o: plugboard.cpp util.cpp
	$(command) plugboard.cpp util.cpp

reflector.o: reflector.cpp util.cpp
	$(command) reflector.cpp util.cpp

machine.o: machine.cpp
	$(command) machine.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
