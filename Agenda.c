#include<stdio.h> 
#include<stdlib.h> 
#include<locale.h> 
#include<ctype.h>
#include<string.h>
#include<stdbool.h> 
#include"agenda.h"
#include"agendaF.c"

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
		
		system("cls");
		
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