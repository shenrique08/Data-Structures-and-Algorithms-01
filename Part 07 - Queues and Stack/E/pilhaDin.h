


typedef struct aluno {
    int matricula;
    char nome[50];
    float nota;
} Aluno;


typedef struct pilha Pilha;



Pilha* cria_pilha();
void limpar_pilha(Pilha* pilha);
int pilha_vazia(Pilha* pilha);
int pilha_cheia(Pilha* pilha);

int push(Pilha* pilha, Aluno aluno);
int pop(Pilha* pilha, Aluno *aluno_removido);

int consultar(Pilha* pilha, Aluno *aluno_consultado);
int mostrar_pilha(Pilha* pilha);
int pop_item(Pilha *pilha, int matricula);

