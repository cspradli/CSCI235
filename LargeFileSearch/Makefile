CC = gcc

CFLAGS = -std=c99 -Wpedantic -Og -g

all:          largeFileSearch

print_all:    largeFileSearch.o
	gcc $(CFLAGS) -o largeFileSearch largeFileSearch.o

clean:
	rm -f largeFileSearch *.o *~

