#define MAX 100



typedef struct pilha Pilha;



Pilha *cria_pilha();
void limpar_pilha(Pilha *pilha);
int pilha_vazia(Pilha *pilha);
int pilha_cheia(Pilha *pilha);
int tamanho_pilha(Pilha *pilha);


int push(Pilha *pilha, int valor);
int pop(Pilha *pilha, int *valor);

void mostrar_pilha(Pilha *pilha);
int consultar_pilha(Pilha *pilha, int *valor_consultado);

int pilhas_iguais(Pilha *pilha1, Pilha *pilha2);
