#include<stdio.h> 
#include<stdlib.h> 
#include<locale.h> 
#include<ctype.h>
#include<string.h>
#include<stdbool.h> 
#define MAX_TAREFAS 100

char *t[MAX_TAREFAS];

int prox_posicao = 0;
int posicao_ant = 0;

void adicionarTarefa (void);
void verFila (void);
void armazenaTarefa (void);
void recuperaTarefa (void);

int main(void)
{
	setlocale(LC_ALL,"Portuguese");
	
	printf("\n\n\n");
	system("pause");
	
	return 0;
}