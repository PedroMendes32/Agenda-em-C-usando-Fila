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