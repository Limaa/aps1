#include <stdlib.h>

struct elementoLista
{
	char info;
	struct elementoLista *next;
	struct elementoLista*prev;
};

struct lista
{
	int n; // numero de elementos na lista;
	struct elementoLista *inicio;
	struct elementoLista *fim;
};

typedef struct lista Lista;

void iniciaLista(struct lista *l);
void destroyLista(struct lista *l);

int sizeLista(struct lista *l);
int emptyLista(struct lista *l);

void pushBackLista(struct lista *l, char c);
void pushFrontLista(struct lista *l, char c);

char popBackLista(struct lista *l);
char popFrontLista(struct lista *l);
