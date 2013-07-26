#include <stdio.h> // printf() e scanf()
#include <ctype.h> // isdigit() e isalhpa()
#include "Lista.h"
#include "Pilha.h"
#include "Fila.h"

void imprimeLista(Lista *l)
{
	printf("COMECO da lista\n");
	struct elementoLista *aux = l->inicio;
	while(aux != NULL)
	{
		printf("%c\n", aux->info);
		aux = aux->next;
	}
	printf("FIM da lista\n");
}

#define bufferSize 100

// --------MENU--------
char menu(char *orig, char *alterada)
{
	char saida = -1;
	printf("----------------------------------------\n");
	printf("              Exercicio 6               \n");
	printf("----------------------------------------\n");
	printf("\n");
	printf("\tString original: %s\n", orig);
	printf("\tString alterada: %s\n", alterada);
	printf("0 - Sair.\n");
	printf("1 - Informacoes.\n");
	printf("2 - Mudar string.\n");
	printf("\t> ");
	scanf("%c", &saida);
	return saida;
}
void showInfo()
{
	printf("6) Dada uma lista encadeada de caracteres formada por uma seqüência\nalternada de letras e dígitos, construa um método que retorne uma lista na qual\nas letras são mantidas  na seqüência original e os dígitos são colocados na \nordem inversa. Exemplos:\n\tA 1 E 5 T 7 W 8 G torna-se A E T W G 8 7 5 1\n\t3 C 9 H 4 Q 6 torna-se C H Q 6 4 9 3\nComo mostram os exemplos, as letras devem ser\nmostradas primeiro,  seguidas dos dígitos. Sugestões:\n\tusar uma fila e uma pilha;\n\tsupor um método ehDigito() retorna booleano que retorna verdadeiro \ncaso um caractere seja um dígito.\n");
}
void getString(char* buff)
{
	printf("String: ");
	fflush(stdin);
	scanf("%s", buff);
}
// --------------------

void alteraLista(Lista *original, Lista *alterada)
{
	destroyLista(alterada);

	Fila letras;
	iniciaFila(&letras);

	Pilha numeros;
	iniciaPilha(&numeros);

	// analisa os elementos da lista original
	struct elementoLista *aux = original->inicio;
	while(aux != NULL)
	{
		if(isalpha(aux->info))
			enfileira(&letras, aux->info);
		else if(isdigit(aux->info))
			empilha(&numeros, aux->info);
		else
			printf("Invalid character (%c).\n", aux->info);
		
		aux = aux->next;
	}
	
	//adiciona os valores a lista alterada
	while(emptyFila(&letras) != 1)
		pushBackLista(alterada, desenfileira(&letras));
	while(sizePilha(&numeros) != 0)
		pushBackLista(alterada, desempilha(&numeros));
	
	destroyFila(&letras);
	destroyPilha(&numeros);
}
void stringToLista(char *s, Lista *l)
{
	destroyLista(l);
	
	int i = 0;
	for(i = 0; s[i] != '\0'; i++)
		pushBackLista(l, s[i]);
}
void listaToString(Lista *l, char *s)
{
	int i = 0;
	struct elementoLista *aux = l->inicio;
	while(aux != NULL)
	{
		s[i] = aux->info;
		aux = aux->next;
		i++;
	}
	s[i] = '\0';
}

int main(int argc, char *argv[])
{
	char original[bufferSize] = "Digite uma string.";
	char alterada[bufferSize] = {'\0'};
	
	Lista listaOrig;
	Lista listaAlter;
	
	iniciaLista(&listaOrig);
	iniciaLista(&listaAlter);
	
	int fim = 0;
	while(fim != 1)
	{
		switch(menu(original, alterada))
		{
		case '0':
			fim = 1;
			break;
		case '1':
			showInfo();
			break;
		case '2':
			getString(original);
			stringToLista(original, &listaOrig);
			alteraLista(&listaOrig, &listaAlter);
			listaToString(&listaAlter, alterada);
			break;
		default:
			printf("Digito Invalido...\n");
			break;
		}
		char aux = '\0';
		while((aux = getchar()) != '\n' && aux != EOF) ; // alternativa para fflush()
	}

	destroyLista(&listaOrig);
	destroyLista(&listaAlter);
	return 0;
}
