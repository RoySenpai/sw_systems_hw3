CC = gcc
CFLAGS = -Wall -g

.PHONY: all clean

all: isort txtfind

isort: isort.o
	$(CC) $(CFLAGS) $^ -o $@

txtfind: txtfind.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o txtfind isort