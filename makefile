CC = gcc
CFLAGS = -O2

default: msolver

magic_solver.o: magic_solver.c magic_solver.h
	$(CC) $(CFLAGS) magic_solver.c -c 

matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) matrix.c -c
	
main.o: main.c main.h
	$(CC) $(CFLAGS) main.c -c
	
msolver: main.o matrix.o magic_solver.o
	$(CC) $(CFLAGS) matrix.o main.o magic_solver.o -o msolver
	
clean:
	rm *.o 
	rm msolver