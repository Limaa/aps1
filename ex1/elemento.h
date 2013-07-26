#include <stdio.h>
#include <stdlib.h>

struct elemento
{
    int info;
    struct elemento *next;
};

void adiciona(struct elemento **lista, int i);

void clear(struct elemento **lista);

void imprime(struct elemento *inicio);
