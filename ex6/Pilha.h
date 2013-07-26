#include <stdlib.h>
#include <stdio.h>

struct elementoPilha
{
	char info;
	struct elementoPilha *prev;
};

struct pilha
{
	int n; // numero de elementos na pilha
	struct elementoPilha *pTopo;
};

typedef struct pilha Pilha;

void iniciaPilha(struct pilha *p);
void destroyPilha(struct pilha *p);

int sizePilha(struct pilha *p);
int emptyPilha(struct pilha *p);

void empilha(struct pilha *p, char c);
char desempilha(struct pilha *p);

