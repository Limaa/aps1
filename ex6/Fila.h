#include <stdlib.h>
#include <stdio.h>

struct elementoFila
{
	char info;
	struct elementoFila *next;
};

struct filaDinamica
{
	struct elementoFila *inicio;
	struct elementoFila *fim;
	int n;
};

typedef struct elementoFila elemento;
typedef struct filaDinamica FilaDinamica;
typedef FilaDinamica Fila;

void iniciaFila(FilaDinamica *pf);
int sizeFila(FilaDinamica *pf);
int emptyFila(FilaDinamica *pf);
void enfileira(FilaDinamica *pf, char x);
char desenfileira(FilaDinamica *pf);
void destroyFila(FilaDinamica *pf);
