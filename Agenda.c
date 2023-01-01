#include<stdio.h> 
#include<stdlib.h> 
#include<locale.h> 
#include<ctype.h>
#include<string.h>
#include<stdbool.h> 
#define MAX_TAREFAS 100
#define ADICIONAR_TAREFA 'I'
#define VER_FILA 'V'
#define DELETAR_TAREFA 'D'
#define SAIR 'S'


char *t[MAX_TAREFAS];

int prox_posicao = 0;
int posicao_ant = 0;

void mostraMenu (void);
void adicionarTarefa (void);
void verFila (void);
void armazenaTarefa ( char * tarefa);
char *recuperaTarefa (void);
void deletarTarefa (void);

int main(void)
{
	setlocale(LC_ALL,"Portuguese");

	char opcao[10];
	int i;
	
	for ( i = 0; i < MAX_TAREFAS; i++ )
	{
		t[i] = NULL;
	}
	
	fflush(stdin);
	
	while ( true )
	{
		mostraMenu();
		gets(opcao);
		
		*opcao = toupper(*opcao);
		
		switch ( *opcao )
		{
			case ADICIONAR_TAREFA:
				adicionarTarefa();
				break;
			case VER_FILA:
				verFila();
				break;
			case DELETAR_TAREFA:
				deletarTarefa();
				break;
			case SAIR:
				exit(EXIT_SUCCESS);
		}
	}
	printf("\n\n\n");
	system("pause");
	
	return 0;
}

void mostraMenu(void)
{	
	printf("-----------------------\n");
	printf("--  OPÇÕS DA AGENDA  --\n ");
	printf("-----------------------\n");
	printf(" I -> Inserir tarefa \n");
	printf(" V -> Ver tarefa na fila\n");
	printf(" D -> Deletar tarefa na fila\n");
	printf(" S -> Sair\n");
	printf(" : ");
}

void adicionarTarefa(void)
{
	char string[256];
	char * tarefa;
	
	do
	{
		printf(" Digite a tarefa %d : ",prox_posicao++);
		gets(s);
		
		if ( *string == 0 )
		{
			break;
		}
		else
		{
			tarefa = (char*) malloc (strlen(s) + sizeof(char));
			
			if ( tarefa == NULL )
			{
				printf(" Erro na alocação de memória! \n");
				return;
			}
			
			strcpy (tarefa,string);
			
			if ( *string )
			{
				armazenaTarefa(tarefa);
			}
		}
	}
	while ( * string );
}

void armazenaTarefa( char * tarefa )
{
	if ( prox_posicao == MAX_TAREFAS )
	{
		printf(" A lista de tarefas está cheia !\n");
		return;
	}
	else
	{
		t[prox_posicao] = tarefa;
		prox_posicao++;
	}
}

void verFila(void)
{
	int i;
	
	for ( i = posicao_ant; i < prox_posicao; i++ )
	{
		printf(" Tarefa %d. -> %s \n",i++,t[i]);
	}
}