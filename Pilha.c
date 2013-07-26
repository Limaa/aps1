#include "Pilha.h"

void iniciaPilha(struct pilha *p)
{
	p->n = 0;
	p->pTopo = NULL;
}
void destroyPilha(struct pilha *p)
{
	if(p->n != 0)
	{
		struct elementoPilha *aux = p->pTopo;
		while(aux != NULL)
		{
			struct elementoPilha *auxAnt = aux->prev;
			free(aux);
			aux = auxAnt;
		}

		p->n = 0;
		p->pTopo = NULL;
	}
}

int sizePilha(struct pilha *p)
{
	return p->n;
}
int emptyPilha(struct pilha *p)
{
	if (p->n == 0)
		return 1;
	return 0;
}

void empilha(struct pilha *p, char c)
{
	struct elementoPilha *pNovo = (struct elementoPilha *)malloc(sizeof(struct elementoPilha));
	if (pNovo == NULL)
	{
		printf("Nao foi possivel alocar memoria para a informacao (%c).\n",c);
		exit(-1);
	}

	pNovo->info = c;
	pNovo->prev = p->pTopo;

	p->pTopo = pNovo;
	p->n++;
}
char desempilha(struct pilha *p)
{
	if (p->n != 0)
	{
		char saida;
		struct elementoPilha *paux = p->pTopo;

		saida = paux->info;
		p->pTopo = paux->prev;
		p->n--;

		free(paux);

		return saida;
	}
	return '\0';
}
