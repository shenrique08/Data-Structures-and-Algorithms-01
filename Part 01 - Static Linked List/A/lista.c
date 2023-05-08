#include "lista.h"
#include <stdio.h>
#include <stdlib.h>



typedef struct lista {
    int tamanho_lista;
    Aluno dados[MAX];
} Lista;






Lista *criar_lista()
{
    Lista *lista = (Lista *) calloc(1, sizeof(Lista));
    if (lista != NULL)
        lista->tamanho_lista = 0;
    return lista;
}



void limpar_lista(Lista *lista)
{
    if (lista != NULL) lista->tamanho_lista = 0;
}



int lista_vazia(Lista *lista)
{
    if (lista->tamanho_lista == 0)
        return 1;
    return 0;
}


int lista_cheia(Lista *lista)
{
    if (lista->tamanho_lista == MAX)
        return 1;
    return 0;
}



int imprime(Lista *lista)
{
    if (lista == NULL) {
        printf("\nA lista nao existe!!!\n");
        return -1;
    }
    if (lista_vazia(lista) == 1) {
        printf("\nA lista esta vazia!!!\n");
        return -1;
    }
    int tam_lista = lista->tamanho_lista;

    printf("\n========== [Conteudo da Lista] =========\n\n");
    // percorre toda a lista a partir da posição [0] até o último elemento
    for (int i = 0; i < tam_lista; i++) {
        printf("\nMatricula: [%d]\n", lista->dados[i].matricula);
        printf("\nNota: [%.3f]\n", lista->dados[i].nota);
        printf("\nNome: [%s]\n\n", lista->dados[i].nome);
    }

    return 0;
}



int inserirInicio(Lista *lista, Aluno aluno)
{
    if (lista == NULL) {
        printf("\nA lista nao existe!!!\n");
        return -1;
    }
    if (lista_cheia(lista) == 1) {
        printf("\nA lista esta cheia!!!\n\n");
        return -1;
    }

    // a contagem começa uma posição depois da posição em que estava o último aluno
    for (int i = lista->tamanho_lista; i > 0; i--) {
        // vamos mover cada aluno para uma posição posterior
        // esse valor posterior irá receber o logo anterior
        lista->dados[i] = lista->dados[i - 1];
    }
    // neste momento, os alunos de posição [0] e [1] são iguais

    // Assim, podemos sobrepor outro aluno na posição [0]
    lista->dados[0] = aluno;
    lista->tamanho_lista += 1;

    return 0;
}



int inserirFim(Lista *lista, Aluno aluno)
{
    if (lista == NULL) {
        printf("\nA lista nao existe!!!\n");
        return -1;
    }
    if (lista_cheia(lista) == 1) {
        printf("\nA lista esta cheia!!!\n\n");
        return -1;
    }
    // se a lista não estiver cheia
    

    // o valor do tamanho da lista é o valor seguinte a posição do último valor do vetor
    // Ex: tamanho da lista: 3. Então, o vetor vai de 0 a 2. Ou seja, a inserção será feita na posição 3
    lista->dados[lista->tamanho_lista] = aluno;
    lista->tamanho_lista += 1;
    
    return 0;
}




int inserirPosicao(Lista *lista, Aluno aluno, int pos)
{
    if (lista == NULL) {
        printf("\nA lista nao existe!!!\n");
        return -1;
    }
    if (lista_cheia(lista) == 1) {
        printf("\nA lista esta cheia!!!\n\n");
        return -1;
    }

    if (lista_vazia(lista))
        return inserirInicio(lista, aluno);

    pos = pos - 1; // será feito baseado na posição em função da visão do usuário. Ou seja, a primeira posição será 1 e não 0
    if (pos >= lista->tamanho_lista)
        return inserirFim(lista, aluno);

    else {
        // iremos, primeiramente, mover todos os elementos que estão a frente da posição dada para a posição logo adiante
        for (int i = lista->tamanho_lista; i > pos; i--) {
            lista->dados[i] = lista->dados[i - 1];
        }
        // agora, iremos inserir o aluno na posição solicitada
        lista->dados[pos] = aluno;
        lista->tamanho_lista += 1;
    }

    return 0;
}



int removerInicio(Lista *lista)
{
    // Verifica se a lista existe
    if (lista == NULL) {
        printf("\nA lista nao existe!!!\n");
        return -1;
    }

    // Verifica se a lista está vazia
    if (lista_vazia(lista) == 1) {
        printf("\nA lista esta vazia!!!\n");
        return -1;
    }

    // cada elemento de uma determinada posição receberá o outro de posição seguinte, sobrescrevendo o elemento [0]
    for (int i = 0; i < (lista->tamanho_lista - 1); i++) {
        lista->dados[i] = lista->dados[i + 1];
    }

    // Decrementa o tamanho da lista
    lista->tamanho_lista -= 1;

    return 0;
}




int removerFim(Lista *lista)
{
    // Verifica se a lista existe
    if (lista == NULL) {
        printf("\nA lista nao existe!!!\n");
        return -1;
    }

    // Verifica se a lista está vazia
    if (lista_vazia(lista) == 1) {
        printf("\nA lista esta vazia!!!\n");
        return -1;
    }

    // irei apenas "apagar" o último elemento diminuindo o tamano da lista
    lista->tamanho_lista -= 1;

    return 0;
}




int removerPosicao(Lista *lista, int pos)
{
    // Verifica se a lista existe
    if (lista == NULL) {
        printf("\nA lista nao existe!!!\n");
        return -1;
    }

    // Verifica se a lista está vazia
    if (lista_vazia(lista) == 1) {
        printf("\nA lista esta vazia!!!\n");
        return -1;
    }

    if (pos == 1)
        return removerInicio(lista);
    if (pos == lista->tamanho_lista)
        return removerFim(lista);
    
    pos -= 1; // será feito baseado na posição em função da visão do usuário. Ou seja, a primeira posição será 1 e não 0

    // o looping começa na posição de remoção e vai até o final da lista
    // movendo cada elemento para a posição imediatamente anterior
    for (int i = pos; i < lista->tamanho_lista; i++) {  
        lista->dados[i] = lista->dados[i + 1];
    }

    lista->tamanho_lista -= 1;

    return 0;
}



int removerAluno(Lista *lista, int matricula)
{
    // Verifica se a lista existe
    if (lista == NULL) {
        printf("\nA lista nao existe!!!\n");
        return -1;
    }

    // Verifica se a lista está vazia
    if (lista_vazia(lista) == 1) {
        printf("\nA lista esta vazia!!!\n");
        return -1;
    }

    int pos_remocao = 1;
    int achou = 0;
    // primeiro, iremos localizar a posição do aluno a ser removido
    for (int i = 1; i < lista->tamanho_lista; i++) {
        pos_remocao += 1;
        if (lista->dados[i].matricula == matricula) {
            achou = 1;
            break;
        }
    }

    if (!achou) {
        printf("\nAluno nao encontrado!!!\n\n");
        return -1;
    } else {
        return removerPosicao(lista, pos_remocao);
    }
}



int buscar_aluno_mat(Lista *lista, int matricula)
{
    // Verifica se a lista existe
    if (lista == NULL) {
        printf("\nA lista nao existe!!!\n");
        return -1;
    }

    // Verifica se a lista está vazia
    if (lista_vazia(lista) == 1) {
        printf("\nA lista esta vazia!!!\n");
        return -1;
    }

    int pos_aluno = 0;
    int achou = 0;
    // primeiro, iremos localizar a posição do aluno a ser removido
    for (int i = 0; i < lista->tamanho_lista; i++) {
        pos_aluno += 1;
        if (lista->dados[i].matricula == matricula) {
            achou = 1;
            break;
        }
    }

    if (!achou) {
        printf("\nAluno nao encontrado!!!\n\n");
        return -1;
    } else {
        printf("\n========== Aluno encontrado ==========\n\n");

        printf("\nMatricula: [%d]\n", lista->dados[pos_aluno - 1].matricula);
        printf("\nNota: [%.3f]\n", lista->dados[pos_aluno - 1].nota);
        printf("\nNome: [%s]\n\n", lista->dados[pos_aluno - 1].nome);
    }
}