#include "elemento.h"

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
