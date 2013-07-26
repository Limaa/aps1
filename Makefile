all: clean exs

clean:
	rm -f ex1
	rm -f ex2
	rm -f ex3
	rm -f ex5
exs: exs1 exs2 exs3 exs5

exs1: ex1.c elemento.c
	gcc -o ex1 ex1.c elemento.c -I. -g -Wall -std=c99
exs2: ex2.c elemento.c
	gcc -o ex2 ex2.c elemento.c -I. -g -Wall -std=c99
exs3:
	gcc -o ex3 ex3.c elemento.c -I. -g -Wall -std=c99

exs5:
	gcc -o ex5 ex5.c filaDinamica.c -I. -g -Wall -std=c99
