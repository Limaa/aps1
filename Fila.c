#include "Fila.h"

void iniciaFila(FilaDinamica *pf)
{
	pf->inicio = NULL;
	pf->fim = NULL;
	pf->n = 0;
}

int sizeFila(FilaDinamica *pf)
{
	return pf->n;
}

int emptyFila(FilaDinamica *pf)
{
	if(pf->n == 0)
		return 1;
	return 0;
}

void enfileira(FilaDinamica *pf, char x)
{
	struct elementoFila *pNovo = (struct elementoFila *)malloc(sizeof(struct elementoFila));
	if(pNovo == NULL)
	{
		printf("Sem memoria suficiente...Saindo do programa.\n");
		exit(-1);
	}
	pNovo->info = x;
	pNovo->next = NULL;

	if(pf->n == 0)
	{
		pf->inicio = pNovo;
		pf->fim = pNovo;
	}
	else
	{
		pf->fim->next = pNovo;
		pf->fim = pNovo;
	}
	pf->n++;
}

char desenfileira(FilaDinamica *pf)
{
	char saida = -1;
	if(pf->n != 0)
	{
		struct elementoFila *aux = pf->inicio->next;
		saida = pf->inicio->info;
		free(pf->inicio);
		pf->inicio = aux;
		pf->n--;
	}
	return saida;
}
void destroyFila(FilaDinamica *pf)
{
	if(pf->n != 0)
	{
		struct elementoFila *aux = pf->inicio;
		while(aux != NULL)
		{
			aux = aux->next;
			free(pf->inicio);
			pf->inicio = aux;
			pf->n--;
		}
	}
}
