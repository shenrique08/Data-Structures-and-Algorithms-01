#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIA_h
#define MAX 100



typedef struct aluno {
    int matricula;
    char nome[30];
    float nota1;

} Aluno;



typedef struct lista {
    int qtd;
    struct aluno dados[MAX];
} Lista;



Lista *cria_lista();
void libera_lista(Lista *lista);
int tamanho_lista(Lista *lista);
int lista_cheia(Lista *lista);
int lista_vazia(Lista *lista);
int insere_lista_inicio(Lista *lista, struct aluno aluno);
int remove_inicio(Lista *lista);


#endif