
# reg1 makefile

CC = g++

reg1: naped.o reghister2.o reg1.o
	$(CC) naped.o reghister2.o reg1.o -o reg1 -lncurses

naped.o: naped.cpp naped.h
	$(CC) naped.cpp -c -o naped.o

reghister2.o: reghister2.cpp reghister2.h
	$(CC) reghister2.cpp -c -o reghister2.o

reg1.o: reg1.cpp naped.h reghister2.h
	$(CC) reg1.cpp -c -o reg1.o
