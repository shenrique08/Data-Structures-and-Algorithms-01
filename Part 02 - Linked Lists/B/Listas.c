#include "Listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct no
{
    Aluno valor;
    struct no *prox;

} No;



typedef struct lista 
{
    No *inicio;

} Lista;





Lista *criar_lista()
{
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    lista->inicio = NULL;

    return lista;

}


void limpar_lista(Lista *lista)
{
    while (lista_vazia(lista) != 1)
        remover_inicio(lista);
}



int lista_vazia(Lista *lista)
{
    if (lista == NULL)
        return 2;
    if (lista->inicio == NULL)
        return 1;
    return 0;
}



int inserir_no_inicio(Lista *lista, Aluno aluno)
{
    // se a lista não existe, retorne 2
    if (lista == NULL)
        return 2;
    No *no = (No *) malloc(sizeof(No));

    no->valor = aluno;
    no->prox = lista->inicio;
    lista->inicio = no;

    return 0;
}



int inserir_no_fim(Lista *lista, Aluno aluno)
{
    if (lista == NULL)
        return 0;
    if (lista_vazia(lista) == 1)
        return inserir_no_inicio(lista, aluno);

    No *noLista = lista->inicio;

    while (noLista->prox != NULL)
        noLista = noLista->prox;

    No *no = (No *) calloc(1, sizeof(No));

    no->valor = aluno;
    no->prox = noLista->prox;
    noLista->prox = no;

    return 0;
}



void imprime(const Lista *lista)
{
    No *noLista = lista->inicio;


    while (noLista != NULL) {
        printf("\nMatricula: [%d]\n", noLista->valor.matricula);
        printf("Nome: [%s]\n", noLista->valor.nome);
        printf("Nota: [%.3f]\n\n", noLista->valor.nota);

        noLista = noLista->prox;
    }
}




int inserir_pos(Lista *lista, Aluno aluno, int pos)
{
    if (lista == NULL) return 2;
    if (pos < 0) return 3;

    if ((lista_vazia(lista) == 1) || (pos == 0))
        return inserir_no_inicio(lista, aluno);
    
    No *noLista = lista->inicio;
    int p = 1;

    while ((noLista->prox != NULL) && (p != pos)) {
        p ++;
        noLista = noLista->prox;
    }

    No *no = (No*) malloc(sizeof(No));
    no->valor = aluno;
    no->prox = noLista->prox;
    noLista->prox = no;

    return 0;
}



int remover_inicio(Lista *lista)
{
    if (lista == NULL)
        return 2;
    if (lista_vazia(lista) == 1) // a lista existe mas está vazia
        return 1;

    No *noLista = lista->inicio;
    lista->inicio = noLista->prox;

    free(noLista);

    return 0;
}



int remover_fim(Lista *lista)
{
    // se a lista não existe
    if (lista == NULL)
        return 2;
    // se a lista existe, mas não tem nada lá dentro
    if (lista_vazia(lista) == 1)
        return 1;

    No *noAuxiliar = NULL;
    No *noLista = lista->inicio;

    while (noLista->prox != NULL) {
        noAuxiliar = noLista;
        noLista = noLista->prox;
    }

    if (noAuxiliar == NULL)
        lista->inicio = NULL;
    else 
        noAuxiliar->prox = NULL;
    
    free(noLista);

    return 0;
}



int tam_lista(Lista *lista)
{
    int size = 0;
    No *aux = lista->inicio;

    while (aux != NULL) {
        size += 1;
        aux = aux->prox;
    }

    return size;
}



int remover_pos(Lista *lista, int pos)
{
    // a lista não existe
    if (lista == NULL)
        return 2;
    // a lista está vazia
    if (lista_vazia(lista) == 1)
        return 1;
    // posição inválida
    if (pos < 0 || pos>= tam_lista(lista))
        return 3;

    No *anterior = NULL; // este é o nó auxiliar anterior ao atual 
    No *atual = lista->inicio;

    int i = 0;

    // percorre a lista até a posição desejada
    while (i < pos) {
        anterior = atual;
        atual = atual->prox;

        i += 1;
    }

    // remove o elemento atual da lista
    if (anterior == NULL) // É o primeiro elemento
        lista->inicio = atual->prox;

    else 
        anterior->prox = atual->prox;
    
    free(atual);

    return 0;
}



int remover_aluno(Lista *lista, Aluno aluno)
{
    if (lista == NULL)
        return 2;
    if (lista_vazia(lista) == 1)
        return 1;
    
    No *anterior = NULL;
    No *atual = lista->inicio;

    // percorrendo a lista até encontrar o aluno
    while (atual != NULL && strcmp(atual->valor.nome, aluno.nome) != 0) {
        anterior = atual;
        atual = atual ->prox;
    }

    // se o elemento não foi encontrado
    if (atual == NULL)
        return -1;
    
    // remove o elemento encontrado
    if (anterior == NULL) // é o primeiro elemento
        lista->inicio = atual->prox;
    else 
        anterior->prox = atual->prox;

    free(atual);


    return 0;
}



int buscar_pos(Lista *lista, Aluno *retorno, int pos)
{
    if (lista == NULL || pos < 0)
        return 2;
    if (lista_vazia(lista) == 1)
        return 3;
    if (pos > tam_lista(lista)) {
        printf("\nPosicao invalida!\n");
        return -1;
    }

    No *atual = lista->inicio;

    // percorre a lista para descobrir a posição desejada
    for (int i = 0; i < pos && atual != NULL; i++)
        atual = atual->prox;


    if (atual == NULL) // é o primeiro 
        return 1;
    else {
        *retorno = atual->valor;
        printf("\n================= Aluno encontrado na posicao ================= %d:\n", pos);
        printf("Matricula: %d\n", retorno->matricula);
        printf("Nome: %s\n", retorno->nome);
        printf("Nota: %.3f\n\n", retorno->nota);
        
        return 0;
    }
}



int Contem_Aluno(Lista *lista, Aluno aluno)
{
    if (lista == NULL) // lista não existe
        return 2;
    if (lista_vazia(lista) == 1)
        return 3;

    No *no_atual = (No *) calloc(1, sizeof(No));
    no_atual = lista->inicio;

    while ((no_atual != NULL) && (strcmp(no_atual->valor.nome, aluno.nome)) != 0) { // comparação feita pelo nome

        no_atual = no_atual->prox;
    }

    if (no_atual == NULL) { // aluno não está na lista
        free(no_atual);
        return 1;
    }
        
    else { // o aluno foi encontrado
        free(no_atual);
        return 0;   
    }
        
}



Lista *concatena(Lista *lista1, Lista *lista2)
{
    Lista *lista_concatenada = criar_lista();

    if (lista1 == NULL && lista2 == NULL) {
        printf("Falha!!! As listas nao existem\n");
        return NULL;
    }

    if (lista_vazia(lista1) == 1 && lista_vazia(lista2) == 1) {
        printf("Falha!!! As listas estao vazias\n");
        return NULL;
    }

    No *no_lista1 = lista1->inicio;

    while (no_lista1 != NULL) {
        inserir_no_fim(lista_concatenada, no_lista1->valor);
        no_lista1 = no_lista1->prox;
    }   

    No *no_lista2 = lista2->inicio;

    while (no_lista2 != NULL) {
        inserir_no_fim(lista_concatenada, no_lista2->valor);
        no_lista2 = no_lista2->prox;
    }

    return lista_concatenada;
}
