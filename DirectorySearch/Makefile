CC = gcc

CFLAGS = -std=c99 -Wpedantic -Og -g

all:          print_all

print_all:    printAll.o
	gcc $(CFLAGS) -o print_all printAll.o

clean:
	rm -f print_all *.o *~

