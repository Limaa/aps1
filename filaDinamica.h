#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct elementoFila
{
	char *nome;
	char prioridade;
	struct elementoFila *pProx;
};

struct filaDinamica
{
	struct elementoFila *pPrim;
	struct elementoFila *pFim;
	int n;
};

typedef struct elementoFila elemento;
typedef struct filaDinamica FilaDinamica;

void inicializa(FilaDinamica *pf);
int size(FilaDinamica *pf);
int empty(FilaDinamica *pf);
void enfileira(FilaDinamica *pf, char *s, char preferencial);
void desenfileira(FilaDinamica *pf, char *s);
void destroy(FilaDinamica *pf);
