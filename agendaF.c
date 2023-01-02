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
	
	printf("\t\t\t OBS: Para terminar de inserir tarefas aperte enter sem nenhuma string! \n");

	do
	{	 
		printf(" Digite a tarefa %d : ",prox_posicao+1);
		gets(string);
		
		if ( *string == 0 )
		{
			break;
		}
		else
		{
			tarefa = (char*) malloc (strlen(string) + sizeof(char));
			
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
	
	system("cls");
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
		printf(" Tarefa %d. -> %s \n",i+1,t[i]);
	}
	
	printf("\n\n\n");
	system("pause");
	
	system("cls");
}

char * recuperaTarefa(void)
{
	if ( posicao_ant == prox_posicao )
	{
		printf(" Sem Tarefas! \n");
		system("pause");
		system("cls");
		
		return NULL;
	}
	else
	{
		posicao_ant++;
		return t[posicao_ant-1];
	}
}

void deletarTarefa(void)
{
	char *tarefa;
	
	if ( (tarefa = recuperaTarefa()) == NULL )
	{
		return;
	}
	else
	{
		printf(" Tarefa deletada -> %s\n",tarefa);
	}
	
	printf("\n\n\n");
	system("pause");
	
	system("cls");
}
