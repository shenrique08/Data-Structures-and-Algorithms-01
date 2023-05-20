#define MAX 100


typedef struct fila Fila;



Fila *criar_fila();
void limpar_fila(Fila *fila);
int fila_cheia(Fila *fila);
int fila_vazia(Fila *fila);

void print(Fila *fila);
int consultar(Fila *fila, int *valor);

int insere_na_fila(Fila *fila, int valor);
int remove_da_fila(Fila *fila, int *valor_removido);
int remove_negativos(Fila *fila);
