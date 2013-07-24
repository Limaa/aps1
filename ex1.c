#include <stdio.h>
#include <stdlib.h>

struct elemento
{
	int info;
	struct elemento *next;
};

void adiciona(struct elemento *inicio, int i)
{
	struct elemento *novo = (struct elemento *)malloc(sizeof(struct elemento));
	novo->info = i;
	novo->next = NULL;

	if(inicio == NULL)
	{
		inicio = novo;
	}
	else
	{
		struct elemento *paux = inicio;
		while(paux->next != NULL)
		{
			paux = paux->next;
		}
		paux->next = novo;
	}
}

void crialista(struct elemento **lista)
{
	struct elemento *inicio = *lista;

	inicio = NULL;
	adiciona(inicio, 4);
	adiciona(inicio, 6);
	adiciona(inicio, 7);
	adiciona(inicio, 2);
	adiciona(inicio, 13);
	adiciona(inicio, 8);
	adiciona(inicio, 20);
	adiciona(inicio, 9);
}

void clear(struct elemento *inicio)
{
	if(inicio != NULL)
	{
		struct elemento *paux = inicio;
		while(paux != NULL)
		{
			struct elemento *prox = paux->next;
			free(paux);
			paux = prox;
		}
	}
	inicio = NULL;
}

void imprime(struct elemento *inicio)
{
	if(inicio != NULL)
	{
		struct elemento *paux = inicio;
		while(paux != NULL)
		{
			printf("%d\n", paux->info);
			paux = paux->next;
		}
	}
}

void separa(struct elemento *source, struct elemento **listaPar, struct elemento **listaImpar)
{
	struct elemento *par = *listaPar;
	struct elemento *impar = *listaImpar;

	if(source != NULL)
	{
		struct elemento *paux = source;
		while(paux != NULL)
		{
			if((paux->info)%2 == 0)
				adiciona(par, paux->info);
			else
				adiciona(impar, paux->info);

			paux = paux->next;
		}
	}
}

int main(int argc, char *argv[])
{
	struct elemento *A, *PAR, *IMPAR;
	crialista(&A);
	separa(A, &PAR, &IMPAR);
	imprime(A);
	imprime(PAR);
	imprime(IMPAR);
	
	return 0;
}
