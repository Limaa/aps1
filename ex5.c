#include <stdio.h>
#include "filaDinamica.h"

void separaFilas(FilaDinamica *pf, FilaDinamica *normal, FilaDinamica *prioridade)
{
	struct elementoFila *aux = pf->pPrim;
	while(aux != NULL)
	{
		if( (aux->prioridade == 's') || (aux->prioridade == 'S') )
			enfileira(prioridade, aux->nome, aux->prioridade);
		else
			enfileira(normal, aux->nome, aux->prioridade);
		aux = aux->pProx;
	}
}
void imprime(FilaDinamica *pf)
{
	printf("COMECO da fila.\n");
	struct elementoFila *aux = pf->pPrim;
	while(aux != NULL)
	{
		printf("%s\n", aux->nome);
		aux = aux->pProx;
	}
	printf("FIM da fila.\n");
}

// -------BUFFER----------
#define bufferSize 100
char buffer[bufferSize];
void esvaziaBuffer()
{
	buffer[0] = '\0';
}
int bufferVazio()
{
	if(buffer[0] == '\0')
		return 1;
	return 0;
}
// -----------------------

char prioridade = '\0';

// -------MENU------------
char menu()
{
	char saida = '\0';
	printf("-------------------------------------------\n");
	printf("   Gerenciamento de filas com prioridade   \n");
	printf("-------------------------------------------\n");
	printf("\n");
	printf("0 - Sair.\n");
	printf("1 - Inserir pessoas na fila.\n");
	printf("2 - Retirar pessoas da fila.\n");
	printf("3 - Separar lista entre: com prioridade e sem prioridade.\n");
	printf("4 - Retirar pessoas da fila COM prioridade.\n");
	printf("5 - Retirar pessoas da fila SEM prioridade.\n");
	printf("6 - Exibir lista.\n");
	printf("7 - Exibir lista COM prioridade.\n");
	printf("8 - Exibir lista SEM prioridade.\n");
	printf("\t> ");
	scanf("%c", &saida);
	return saida;
}

void getNome(char *s)
{
	printf("Nome: ");
	scanf("%s", s);
}
void getPrioridade(char *c)
{
	char aux;
	printf("Prioridade (s) ou (n): ");
	while((aux = getchar()) != '\n' && aux != EOF) ; // alternativa para fflush()
	scanf("%c", &aux);
	*c = aux;
}
// -----------------------

int main(int argc, char *argv[])
{
	FilaDinamica fila;
	FilaDinamica preferencial;
	FilaDinamica normal;
	
	inicializa(&fila);
	inicializa(&preferencial);
	inicializa(&normal);

	int fim = 0;
	while(fim != 1)
	{
		switch(menu())
		{
		case '0': // Sair
			fim = 1;
			break;
		case '1': // Inserir pessoas na fila
			getNome(buffer);
			getPrioridade(&prioridade);
			enfileira(&fila, buffer, prioridade);
			esvaziaBuffer();
			break;
		case '2': // Retirar pessoas da fila
			desenfileira(&fila, buffer);
			if(bufferVazio() == 1)
				printf("Nenhuma pessoa na fila.\n");
			else
			{
				printf("A pessoa retirada: %s\n", buffer);
				esvaziaBuffer();
			}
			break;
		case '3': // Separar lista entre: com prioridade e sem prioridade
			separaFilas(&fila, &normal, &preferencial);
			printf("Filas separadas...\n");
			break;
		case '4': // Retirar pessoas da fila COM prioridade
			desenfileira(&preferencial, buffer);
			if(bufferVazio() == 1)
				printf("Nenhuma pessoa na fila.\n");
			else
			{
				printf("A pessoa retirada da fila preferencial: %s\n", buffer);
				esvaziaBuffer();
			}
			break;
		case '5': // Retirar pessoas da fila SEM prioridade
			desenfileira(&normal, buffer);
			if(bufferVazio() == 1)
				printf("Nenhuma pessoa na fila.\n");
			else
			{
				printf("A pessoa retirada da fila normal: %s\n", buffer);
				esvaziaBuffer();
			}
			break;
		case '6': // Exibir lista
			imprime(&fila);
			break;
		case '7': // Exibir lista COM prioridade
			imprime(&preferencial);
			break;
		case '8': // Exibir lista SEM prioridade
			imprime(&normal);
			break;
		default:
			printf("Digite um numero valido.\n");
			break;
		}
	}

	destroy(&fila);
	destroy(&preferencial);
	destroy(&normal);

	return 0;
}
