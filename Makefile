all: clean exs
CFLAGS=-Wall -g -std=c99
clean:
	rm -f ex1
	rm -f ex2
exs: exs1 exs2
exs1: ex1.c elemento.c
	gcc -o ex1 ex1.c elemento.c -I. -g
exs2: ex2.c elemento.c
	gcc -o ex2 ex2.c elemento.c -I. -g
