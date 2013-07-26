#include <stdio.h>
#include "Lista.h"
#include "Pilha.h"

void imprimeLista(Lista *l)
{
	struct elementoLista *aux = l->inicio;
	while(aux != NULL)
	{
		printf("%d", aux->info);
		aux = aux->next;
	}
	printf("\n");
}

void pilhaToLista(Pilha *p, Lista *l)
{
	while(emptyPilha(&p) != 1)
	{
		pushBackLista(l, desempilha(p));
	}
}

void decToBin(int n, Lista *l)
{
	Pilha aux;
	iniciaPilha(&aux);

	while(n != 0)
	{
		empilha(&aux, n%2); // empilha o resto da divisao
		n = n/2;
	}
	pilhaToLista(&aux, l);
	destroyPilha(&aux);
}

// ------------------MENU------------------------
char menu(int dec, Lista *bin)
{
	char saida = '\0';
	printf("--------------------\n");
	printf("     Exercicio 7    \n");
	printf("--------------------\n");
	printf("\n");
	printf("\tNumero decimal: %d\n", dec);
	printf("\tNumero binario: "); imprimeLista(bin);
	printf("\n");
	printf("0 - Sair.\n");
	printf("1 - Mudar numero decimal.\n");
	printf("\t> ");
	scanf("%c", &saida);
	return saida;
}
// ----------------------------------------------


int main(int argc, char *argv[])
{
	int bin = 0;
	Lista l;
	iniciaLista(&l);

	int fim = 0;
	while(fim != 1)
	{
		switch(menu(bin, &l))
		{
			case 0:
				fim = 1;
				break;
			case 1:
				printf("Numero: ");
				scanf("%d", bin);
				decToBin(bin,&l);
				break;
			default:
				break;
		}
	}
	destroyLista(&l);

	return 0;
}

	return 0;
}
