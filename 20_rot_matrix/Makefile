CC = gcc
CFLAGS = -pedantic -std=gnu99 -Wall -Werror -ggdb3 -no-pie
rotate-matrix: read-matrix.o rotate.o
	$(CC) $(CFLAGS) -o rotate-matrix read-matrix.o rotate.o

rotate.o: rotate.c
	$(CC) $(CFLAGS) -c rotate.c

