#include "lista_circular.h"
#include <stdio.h>
#include <stdlib.h>



typedef struct no
{
    Aluno dados_aluno;
    struct no *prox;

} No;



typedef struct lista
{
    No *inicio;
    No *prox;

} Lista_Circular;



Lista_Circular *cria_lista()
{
    Lista_Circular *lista = (Lista_Circular *) calloc(1, sizeof(Lista_Circular ));

    return lista;
}



int imprime_lista(Lista_Circular *lista)
{
    if (lista == NULL) {
        fprintf(stderr, "\nERRO!!! A lista nao existe.\n");
        exit(EXIT_FAILURE);
    }
        
    if (lista_vazia(lista) == 1) {
        fprintf(stderr, "\nA lista esta vazia!!!\n");
        exit(EXIT_FAILURE);
    }
        
    
    No *no_lista = lista->inicio;

    do {
        printf("\n\nMatricula: [%d]\n", no_lista->dados_aluno.matricula);
        printf("Nome: [%s]\n", no_lista->dados_aluno.nome);
        printf("Nota: [%.3f]\n\n", no_lista->dados_aluno.nota);

        no_lista = no_lista->prox;

    } while (no_lista != lista->inicio);
}




int lista_vazia(Lista_Circular *lista)
{
    if (lista->inicio->prox == lista->inicio)
        return 1;
    return 0;
}



int limpar_lista(Lista_Circular *lista)
{
    if (lista == NULL) {
        fprintf(stderr, "Erro!!\n");
        exit(EXIT_FAILURE);
    }

    // enquanto ela não for vazia
        
}