#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"

int i = 0; // utilizado para preencher as listas

void cria_lista(struct elemento **lista)
{
	*lista = NULL;

	if(i == 0)
	{
		adiciona(lista, 2);
		adiciona(lista, 5);
		adiciona(lista, 9);
		adiciona(lista, 7);
		adiciona(lista, 3);

		i++;
	}
	else if(i == 1)
	{
		adiciona(lista, 1);
		adiciona(lista, 2);
		adiciona(lista, 6);
		adiciona(lista, 3);
		adiciona(lista, 9);
		adiciona(lista, 15);
	}
}

void intersecao_listas(struct elemento *a, struct elemento *b, struct elemento **c)
{
	*c = NULL; // a terceira lista tem que ser iniciada;
	struct elemento *pauxA = a;
	struct elemento *pauxB = b;
	
	while(pauxA != NULL)
	{
		while(pauxB != NULL)
		{
			if(pauxA->info == pauxB->info)
				adiciona(c,pauxA->info);
			pauxB = pauxB->next;
		}
		pauxB = b; // volta o ponteiro para o inicio da lista;
		pauxA = pauxA->next;
	}
}

int main(int argc, char *argv[])
{
	struct elemento *A, *B, *C;

	cria_lista(&A);
	imprime(A);

	cria_lista(&B);
	imprime(B);

	intersecao_listas(A, B, &C);
	imprime(C);
	
	clear(&A);
	clear(&B);
	clear(&C);
	return 0;
}
