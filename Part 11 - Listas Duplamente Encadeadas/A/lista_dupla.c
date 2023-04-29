#include "lista_dupla.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>



typedef struct no {
    Aluno dados;
    struct no *prox;
    struct no *ant;

} No;

typedef struct lista {
    No *inicio;        

} Lista_dupla;



Lista_dupla *criar_lista()
{
    Lista_dupla *lista = (Lista_dupla *) calloc(1, sizeof(Lista_dupla));
    lista->inicio = NULL;

    return lista;
}



int lista_vazia(Lista_dupla *lista)
{
    if (lista == NULL) return -1;
    if (lista->inicio == NULL)
        return 1;
    else 
        return 0;
}




void remover_alunos(Lista_dupla *lista)
{
    while (lista_vazia(lista) != 1)
        remove_inicio(lista);
    free(lista);

    lista = NULL;
}



int tam_lista(Lista_dupla *lista)
{
    if (lista == NULL) return -1;

    if (lista->inicio == NULL)
        return 0;
    
    No *no = lista->inicio;
    int contador = 0;
    while (no != NULL) {
        contador ++;
        no = no->prox;
    }

    return contador;
}



void imprime(Lista_dupla *lista)
{
    if (lista == NULL) {
        fprintf(stderr, "\nA lista nao existe!!!\n\n");
        exit(EXIT_FAILURE);
    }
    if (lista_vazia(lista) == 1) {
        fprintf(stderr, "\nA lista esta vazia!!!\n\n");
        exit(EXIT_FAILURE);
    }

    No *aux = lista->inicio;

    while (aux != NULL) {
        printf("\nMatricula: [%d]\n", aux->dados.matricula);
        printf("\nNome: [%s]\n", aux->dados.nome);
        printf("\nNota: [%.3f]\n\n", aux->dados.nota);

        aux = aux->prox;
    }
}



// inserir uma struct em uma lista duplamente encadeada
int insere_inicio(Lista_dupla *lista, Aluno aluno)
{
    // Verifica se a lista existe
    if (lista == NULL)
        return 2;

    // Cria um novo nó, que será inserido no início da lista
    No *novo_no = (No *) calloc(1, sizeof(No));
    novo_no->dados = aluno;

    // Atualiza os ponteiros do novo nó
    novo_no->prox = lista->inicio; // novo_no->prox agora apontará onde o lista->inicio apontava, que era o primeiro elemento
    novo_no->ant = NULL; // como se trata de uma lista duplamente encadeada, então o novo_no->ant apontará para NULL

    // Atualiza os ponteiros dos nós adjacentes
    if (lista->inicio != NULL)
        lista->inicio->ant = novo_no; //o nó anterior daquele que era o primeiro elemento, agora apontará para o novo_no

    // Atualiza o ponteiro de início da lista, que agora apontará para o nó inserido
    lista->inicio = novo_no;

    return 0;
}





int insere_final(Lista_dupla *lista, Aluno aluno)
{
    if (lista == NULL) return 2;

    if (lista_vazia(lista) == 1)
        return insere_inicio(lista, aluno);
    
    No *ultimo_no = lista->inicio;

    while (ultimo_no->prox != NULL)
        ultimo_no = ultimo_no->prox;

    // criando o nó a ser inserido
    No *novo_no = (No *) calloc(1, sizeof(No));
    novo_no->dados = aluno;
    novo_no->prox = NULL;
    novo_no->ant = ultimo_no; // o nó anterior do novo nó apontará para o que, anteriormente, era o último nó
    ultimo_no->prox = novo_no; // o nó prox do que antes era o último nó, agora apontará para o nó inserido

    return 0;
}




int inserir_pos(Lista_dupla *lista, Aluno aluno, int pos)
{
    // Verifica se a lista existe
    if (lista == NULL) {
        fprintf(stderr, "\nA lista nao existe!!!\n\n");
        exit(EXIT_FAILURE);
    }
    
    // Verifica se a lista está vazia
    if (lista_vazia(lista) == 1) 
        return insere_inicio(lista, aluno);
    
    // Cria um novo nó e atribui os dados do aluno
    No *novo_no = (No *) malloc(sizeof(No));
    novo_no->dados = aluno;
    novo_no->prox = NULL;
    novo_no->ant = NULL;

    // Obtém o nó de início da lista
    No *aux = lista->inicio;

    int i = 1;

    // Percorre a lista até a posição desejada ou até o final da lista
    while (i < pos && aux != NULL) {
        aux = aux->prox;
        i += 1;
    }

    // Se a posição for a última (após o último elemento), insere no final
    if (pos == tam_lista(lista) + 1) {
        return insere_final(lista, aluno);
    }
    // Se a posição for a primeira, insere no início
    else if (pos == 1) {
        return insere_inicio(lista, aluno);
    }
    else {        
        // Insere o novo nó na posição desejada
        novo_no->prox = aux;        // Define o próximo nó do novo nó como o nó atual na posição desejada
        novo_no->ant = aux->ant;    // Define o nó anterior do novo nó como o nó anterior ao nó atual na posição desejada
        aux->ant->prox = novo_no;   // Define o próximo nó do nó anterior ao nó atual como o novo nó
        aux->ant = novo_no;         // Define o nó anterior do nó atual como o novo nó
    }

    return 0;
}





int insere_ordenado(Lista_dupla *lista, Aluno aluno)
{
    // Verifica se a lista existe
    if (lista == NULL) {
        fprintf(stderr, "\nA lista nao existe!!!\n\n");
        exit(EXIT_FAILURE);
    }
    
    // Verifica se a lista está vazia
    if (lista_vazia(lista) == 1) 
        return insere_inicio(lista, aluno);

    // criando o aluno a ser inserido
    No *novo_aluno = (No *) malloc(sizeof(No));
    novo_aluno->dados = aluno;
    novo_aluno->ant = NULL;
    novo_aluno->prox = NULL;

    No *aux = lista->inicio;
    int posicao = 1; // vai ser a posição em que vou inserir o aluno
    // percorrendo a lista até encontrar o primeiro número de matrícula que seja maior do que o nº que desejo inserir
    while (((aux->dados.matricula) < (aluno.matricula)) && (aux->prox != NULL)) {
        posicao += 1;
        aux = aux->prox;
    } // ao final do looping chegarei à posição desejada

    inserir_pos(lista, novo_aluno->dados, posicao);

    
}








int remove_inicio(Lista_dupla *lista)
{
    // Verifica se a lista existe
    if (lista == NULL) {
        fprintf(stderr, "\nA lista nao existe!!!\n\n");
        exit(EXIT_FAILURE);
    }
    
    // Verifica se a lista está vazia
    if (lista_vazia(lista) == 1) {
        fprintf(stderr, "\nA lista esta vazia!!!\n\n");
        exit(EXIT_FAILURE);
    }

    // Cria um ponteiro auxiliar para o nó inicial da lista
    No *no_aux = lista->inicio;

    // Verifica se a lista tem apenas um elemento
    if (lista->inicio->prox == NULL) {
        // Define o início da lista como nulo, indicando que a lista ficará vazia
        lista->inicio = NULL;
    } else {
        // Se houver mais de um elemento na lista, atualiza o início para o próximo nó
        lista->inicio = lista->inicio->prox;
        // Define o ponteiro anterior do novo nó inicial como nulo, pois é o novo início da lista
        lista->inicio->ant = NULL;
    }

    free(no_aux);

    return 0;
}




int remove_final(Lista_dupla *lista)
{
    // Verifica se a lista existe
    if (lista == NULL) {
        fprintf(stderr, "\nA lista nao existe!!!\n\n");
        exit(EXIT_FAILURE);
    }
    
    // Verifica se a lista está vazia
    if (lista_vazia(lista) == 1) {
        fprintf(stderr, "\nA lista esta vazia!!!\n\n");
        exit(EXIT_FAILURE);
    }

    No *no_aux = lista->inicio;

    // Percorre a lista até chegar ao último nó
    while (no_aux->prox != NULL)
        no_aux = no_aux->prox;

    if (no_aux->ant == NULL) // Verifica se a lista só tem um elemento
        lista->inicio = NULL;
    else 
        no_aux->ant->prox = NULL; // o penúltimo nó agora apontará para NULL
    
    free(no_aux); // Libera a memória alocada para o último nó removido
}




int remove_pos(Lista_dupla *lista, int pos)
{
    // Verifica se a lista existe
    if (lista == NULL) {
        fprintf(stderr, "\nA lista nao existe!!!\n\n");
        exit(EXIT_FAILURE);
    }
    
    // Verifica se a lista está vazia
    if (lista_vazia(lista) == 1) {
        fprintf(stderr, "\nA lista esta vazia!!!\n\n");
        exit(EXIT_FAILURE);
    }

    int tamanho_lista = tam_lista(lista);

    // Se a posição for a primeira, chama a função remove_inicio
    if (pos == 1)
        return remove_inicio(lista);
    // Se a posição for a última, chama a função remove_final
    else if (pos == tamanho_lista)
        remove_final(lista);
    else {
        No *no_atual = lista->inicio;
        int i = 1;

        // Percorre a lista até a posição desejada
        while ((no_atual->prox != NULL) && (i < pos)) {
            no_atual = no_atual->prox;
            i++;
        }

        // Realiza a remoção do nó na posição desejada
        no_atual->ant->prox = no_atual->prox;
        no_atual->prox->ant = no_atual->ant;
        free(no_atual);
    }

    return 0;
}






int remove_aluno(Lista_dupla *lista, int matricula)
{
    // Verifica se a lista existe
    if (lista == NULL) {
        fprintf(stderr, "\nA lista nao existe!!!\n\n");
        exit(EXIT_FAILURE);
    }
    
    // Verifica se a lista está vazia
    if (lista_vazia(lista) == 1) {
        fprintf(stderr, "\nA lista esta vazia!!!\n\n");
        exit(EXIT_FAILURE);
    }


    No *aux = lista->inicio;
    int tamanho_lista = tam_lista(lista);
    int pos_remocao = 1;

    if (tamanho_lista == 1)
        return remove_inicio(lista);
    
    
    while ((aux->prox != NULL) && (aux->dados.matricula != matricula)) {
        aux = aux->prox;
        pos_remocao += 1;
    }
    // neste ponto, o aux está na posição de remoção
    remove_pos(lista, pos_remocao);

    return 0;
}




int aluno_maior_nota(Lista_dupla *lista)
{
    // Verifica se a lista existe
    if (lista == NULL) {
        fprintf(stderr, "\nA lista nao existe!!!\n\n");
        exit(EXIT_FAILURE);
    }
    
    // Verifica se a lista está vazia
    if (lista->inicio == NULL) {
        fprintf(stderr, "\nA lista esta vazia!!!\n\n");
        exit(EXIT_FAILURE);
    }
    
    No *no_aluno = lista->inicio;
    
    if (lista->inicio->prox == NULL) {
        printf("\nNome: [%s]\n", no_aluno->dados.nome);
        printf("Matricula: [%d]\n", no_aluno->dados.matricula);
        printf("Nota: [%.3f]\n\n", no_aluno->dados.nota);
        return 0;
        
    } else {
        int pos_maior_nota = 0;
        float maior_nota = no_aluno->dados.nota;
        int pos_atual = 0;

        // fazendo a busca pelo aluno de maior nota e guardando sua posição
        while (no_aluno != NULL) {
            if (no_aluno->dados.nota > maior_nota) {
                maior_nota = no_aluno->dados.nota;
                pos_maior_nota = pos_atual;
            }
            no_aluno = no_aluno->prox;
            pos_atual++;
        }

        // percorre até a posição do aluno de maior nota
        int i = 0;
        No *aluno_atual = lista->inicio;
        while (i < pos_maior_nota && aluno_atual != NULL) {
            aluno_atual = aluno_atual->prox;
            i++;
        }

        // neste momento, aluno_atual está no nó do aluno de maior nota
        printf("\nNome: [%s]\n", aluno_atual->dados.nome);
        printf("Matricula: [%d]\n", aluno_atual->dados.matricula);
        printf("Nota: [%.3f]\n\n", aluno_atual->dados.nota);
        
        return 0;
    }
}
