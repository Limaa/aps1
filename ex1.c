#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"

void crialista(struct elemento **lista)
{
    *lista = NULL;
    adiciona(lista, 4);
    adiciona(lista, 6);
    adiciona(lista, 7);
    adiciona(lista, 2);
    adiciona(lista, 13);
    adiciona(lista, 8);
    adiciona(lista, 20);
    adiciona(lista, 9);
}

void separa(struct elemento *source, struct elemento **listaPar, struct elemento **listaImpar)
{
	// inicia as listas
    *listaPar = NULL;
    *listaImpar = NULL;

    if(source != NULL)
    {
        struct elemento *paux = source;
        while(paux != NULL)
        {
            if((paux->info)%2 == 0)
                adiciona(listaPar, paux->info);
            else
                adiciona(listaImpar, paux->info);

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

	clear(&A);
	clear(&PAR);
	clear(&IMPAR);

    return 0;
}


