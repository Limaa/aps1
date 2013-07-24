#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"

//utilizado para inicializar as listas A e B com os valores adequados
int i = 0;

void crialista(struct elemento **lista)
{
	*lista = NULL;

	if(i == 0)
	{
		adiciona(lista, 4);
		adiciona(lista, 6);
		adiciona(lista, 7);
		adiciona(lista, 10);
		
		i++;
	}
	else if(i == 1)
	{
		adiciona(lista, 2);
		adiciona(lista, 5);
		adiciona(lista, 8);
		adiciona(lista, 9);
		adiciona(lista, 12);
		i++;
	}
}

void concatena(struct elemento *a, struct elemento *b, struct elemento **c)
{
	struct elemento *pauxA = a;
	struct elemento *pauxB = b;
	
	while((pauxA != NULL) || (pauxB != NULL))
	{
		if(pauxA != NULL) // se tiver numeros em a
		{
			if(pauxB != NULL) // se tiver numeros em b
			{
				if(pauxA->info < pauxB->info)
				{
					adiciona(c, pauxA->info);
					pauxA = pauxA->next;
				}
				else
				{
					adiciona(c, pauxB->info);
					pauxB = pauxB->next;
				}
			}
			else // se nao tiver numeros em b
			{
				adiciona(c, pauxA->info);
				pauxA = pauxA->next;
			}

		}
		else // se nao tiver numeros em a
		{
			adiciona(c, pauxB->info);
			pauxB = pauxB->next;
		}
	}
}

int main()
{
	struct elemento *A, *B, *C;
	crialista(&A);
	crialista(&B);
	crialista(&C);
	concatena(A, B, &C);
	imprime(A);
	imprime(B);
	imprime(C);

	clear(&A);
	clear(&B);
	clear(&C);
	return 0;
}
