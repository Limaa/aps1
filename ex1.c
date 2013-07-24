#include <stdio.h>
#include <stdlib.h>

struct elemento
{
    int info;
    struct elemento *next;
};

void adiciona(struct elemento **lista, int i)
{
    struct elemento *novo = (struct elemento *)malloc(sizeof(struct elemento));
    novo->info = i;
    novo->next = NULL;

    if(*lista == NULL)
    {
        *lista = novo;
    }
    else
    {
        struct elemento *paux = *lista;
        while(paux->next != NULL)
        {
            paux = paux->next;
        }
        paux->next = novo;
    }
}

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

void clear(struct elemento **lista)
{
    if(*lista != NULL)
    {
        struct elemento *paux = *lista;
        while(paux != NULL)
        {
            struct elemento *prox = paux->next;
            free(paux);
            paux = prox;
        }
    }
    *lista = NULL;
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
        printf("-------------\n");
    }
}

void separa(struct elemento *source, struct elemento **listaPar, struct elemento **listaImpar)
{
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


