#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>



struct no {
    int valor;
    struct no *prox;
};



typedef struct no No;



Lista *criar_lista() {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    if (lista != NULL)
        *lista = NULL;
    
    return lista;
}


int limpar_lista(Lista *lista)
{
    while (lista_vazia(lista) != 1)
        remove_inicio(lista);
    free(lista);
    *lista = NULL;
}



int lista_vazia(Lista *lista)
{
    if ((*lista) == NULL)
        return 1;
    return 0;
}



int tam_lista(Lista *lista)
{
    if (lista == NULL) return -1;
    if (lista_vazia(lista) == 1)
        return 0;

    No *no = (*lista);

    int contador = 0;

    while (no != NULL) {
        contador += 1;
        no = no->prox;
    }

    return contador;
}



int insere_inicio(Lista *lista, int valor)
{
    // Verifica se a lista existe
    if (lista == NULL)
        return 2;

    // Cria um novo nó, que será inserido no início da lista
    No *novo_no = (No *) calloc(1, sizeof(No));
    novo_no->valor = valor;

    novo_no->prox = (*lista);

    // Atualiza o ponteiro de início da lista, que agora apontará para o nó inserido
    (*lista) = novo_no;

    return 0;
}




int insere_final(Lista *lista, int valor)
{
    if (lista == NULL) return 2;

    if (lista_vazia(lista) == 1)
        return insere_inicio(lista, valor);
    
    No *ultimo_no = (*lista);

    while (ultimo_no->prox != NULL)
        ultimo_no = ultimo_no->prox;

    // criando o nó a ser inserido
    No *novo_no = (No *) calloc(1, sizeof(No));
    novo_no->valor = valor;
    novo_no->prox = NULL;
    ultimo_no->prox = novo_no; // o nó prox do que antes era o último nó, agora apontará para o nó inserido

    return 0;
}




int inserir_pos(Lista *lista, int valor, int pos)
{
    // Verifica se a lista existe
    if (lista == NULL) {
        fprintf(stderr, "\nA lista nao existe!!!\n\n");
        return -1;
    }
    
    // Verifica se a lista está vazia
    if (lista_vazia(lista) == 1) 
        return insere_inicio(lista, valor);
    
    // Cria um novo nó e atribui os dados do aluno
    No *novo_no = (No *) malloc(sizeof(No));
    novo_no->valor = valor;

    // Obtém o nó de início da lista
    No *ant = NULL;
    No *atual = (*lista);

    int i = 1;

    // Percorre a lista até a posição desejada ou até o final da lista
    while (i < pos && atual != NULL) {
        ant = atual;
        atual = atual->prox;
        i += 1;
    }

    // Se a posição for a última (após o último elemento), insere no final
    if (pos == tam_lista(lista) + 1) {
        return insere_final(lista, valor);
    }
    // Se a posição for a primeira, insere no início
    else if (pos == 1) {
        return insere_inicio(lista, valor);
    }
    else {        
        // Insere o novo nó na posição desejada
        ant->prox = novo_no;
        novo_no->prox = atual;
    }

    return 0;
}




int insere_ordenado(Lista *lista, int valor)
{
    // Verifica se a lista existe
    if (lista == NULL) {
        fprintf(stderr, "\nA lista nao existe!!!\n\n");
        return -1;
    }
    
    // Verifica se a lista está vazia
    if (lista_vazia(lista) == 1) 
        return insere_inicio(lista, valor);

    // criando o aluno a ser inserido
    No *novo_aluno = (No *) malloc(sizeof(No));
    novo_aluno->valor = valor;

    No *aux = (*lista);
    int posicao = 1; // vai ser a posição em que vou inserir o aluno
    // percorrendo a lista até encontrar o primeiro valor
    while (((aux->valor) < (valor)) && (aux->prox != NULL)) {
        posicao += 1;
        aux = aux->prox;
    } // ao final do looping chegarei à posição desejada

    inserir_pos(lista, novo_aluno->valor, posicao);

    return 0;
}





int remove_inicio(Lista *lista)
{
    // Verifica se a lista existe
    if (lista == NULL) {
        fprintf(stderr, "\nA lista nao existe!!!\n\n");
        return -1;
    }
    
    // Verifica se a lista está vazia
    if (lista_vazia(lista) == 1) {
        fprintf(stderr, "\nA lista esta vazia!!!\n\n");
        return -1;
    }

    // Cria um ponteiro auxiliar para o nó inicial da lista
    No *no_aux = (*lista);

    // Verifica se a lista tem apenas um elemento
    if (no_aux->prox == NULL) {
        // Define o início da lista como nulo, indicando que a lista ficará vazia
        *lista = NULL;
    } else {
        // Se houver mais de um elemento na lista, atualiza o início para o próximo nó
        *lista = no_aux->prox;
    }

    free(no_aux);

    return 0;
}




int remove_final(Lista *lista)
{
    // Verifica se a lista existe
    if (lista == NULL) {
        fprintf(stderr, "\nA lista nao existe!!!\n\n");
        return -1;
    }
    
    // Verifica se a lista está vazia
    if (lista_vazia(lista) == 1) {
        fprintf(stderr, "\nA lista esta vazia!!!\n\n");
        return -1;
    }

    No *no_ant = NULL;
    No *no_aux = (*lista);

    if (no_aux->prox == NULL) { // Verifica se a lista só tem um elemento
        return remove_inicio(lista);
    }

    // Percorre a lista até chegar ao último nó
    while (no_aux->prox != NULL) {
        no_ant = no_aux;
        no_aux = no_aux->prox;
    }

    no_ant->prox = NULL;
    
    free(no_aux); // Libera a memória alocada para o último nó removido

    return 0;
}




int remove_pos(Lista *lista, int pos)
{
    // Verifica se a lista existe
    if (lista == NULL) {
        fprintf(stderr, "\nA lista nao existe!!!\n\n");
        return -1;
    }
    
    // Verifica se a lista está vazia
    if (lista_vazia(lista) == 1) {
        fprintf(stderr, "\nA lista esta vazia!!!\n\n");
        return -1;
    }

    int tamanho_lista = tam_lista(lista);

    // Se a posição for a primeira, chama a função remove_inicio
    if (pos == 1)
        return remove_inicio(lista);
    // Se a posição for a última, chama a função remove_final
    else if (pos == tamanho_lista)
        remove_final(lista);
    else {
        No *no_ant = NULL;
        No *no_atual = (*lista);
        int i = 1;

        // Percorre a lista até a posição desejada
        while ((no_atual->prox != NULL) && (i < pos)) {
            no_ant = no_atual;
            no_atual = no_atual->prox;
            i++;
        }

        // Realiza a remoção do nó na posição desejada
        no_ant->prox = no_atual->prox;

        free(no_atual);
    }

    return 0;
}






int imprime(Lista *lista)
{
    if (lista == NULL) return -1;

    if (lista_vazia(lista) == 1) {
        printf("\n\n[]\n");
        return 1;
    }

    No *aux = *lista;

    printf("\n\nValores na lista:\n\n[");
    while (aux != NULL) {
        printf(" %d ", aux->valor);
        
        aux = aux->prox;
    }
    printf("]\n\n");

    return 0;
}




int qtd_dado_numero(Lista *lista, int numero)
{
    // Verifica se a lista existe
    if (lista == NULL) {
        fprintf(stderr, "\nA lista nao existe!!!\n\n");
        return -1;
    }
    
    // Verifica se a lista está vazia
    if ((*lista) == NULL) {
        fprintf(stderr, "\nA lista esta vazia!!!\n\n");
        return -1;
    }


    No *no_aux = (*lista);
    int qtd = 0;
    // percorrendo a lista até encontrar o aluno daquela matrícula
    while ((no_aux != NULL)) {
        if (no_aux->valor == numero) {
            qtd += 1;
        }
        no_aux = no_aux->prox;
        
    }
    
    return qtd;
}





int maior_valor(Lista *lista)
{
    // Verifica se a lista existe
    if (lista == NULL) {
        fprintf(stderr, "\nA lista nao existe!!!\n\n");
        return -1;
    }
    
    // Verifica se a lista está vazia
    if ((*lista) == NULL) {
        fprintf(stderr, "\nA lista esta vazia!!!\n\n");
        return -1;
    }
    
    No *no = (*lista);
    
    if (no->prox == NULL) {
        printf("\nMaior valor: [%d]\n\n", no->valor);
        return 0;
        
    } else {
        int pos_maior_valor = 0;
        float maior_nota = no->valor;
        int pos_atual = 0;

        while (no != NULL) {
            if (no->valor > maior_nota) {
                maior_nota = no->valor;
                pos_maior_valor = pos_atual;
            }
            no = no->prox;
            pos_atual++;
        }

        // percorre até a posição do aluno de maior nota
        int i = 0;
        No *aluno_atual = (*lista);
        while (i < pos_maior_valor && aluno_atual != NULL) {
            aluno_atual = aluno_atual->prox;
            i++;
        }

        // neste momento, aluno_atual está no nó do aluno de maior nota
        printf("\nMaior valor: [%d]\n\n", aluno_atual->valor);
        
        return 0;
    }
}