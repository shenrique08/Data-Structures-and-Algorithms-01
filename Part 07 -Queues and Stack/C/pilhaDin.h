


typedef struct aluno {
    int matricula;
    char nome[50];
    float nota;
} Aluno;


typedef struct pilha Pilha;



Pilha* cria_pilha();
void limpar_pilha(Pilha* pilha);
