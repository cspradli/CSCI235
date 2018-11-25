CC = gcc

CFLAGS = -std=c99 -Wpedantic -Og -g

all:          recursiveSearch

print_all:    recursiveSearch.o
	gcc $(CFLAGS) -o recursiveSearch recursiveSearch.o

clean:
	rm -f recursiveSearch *.o *~

