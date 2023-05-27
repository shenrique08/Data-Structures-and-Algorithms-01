#include "pilhaDin.h"
#include <stdio.h>
#include <stdlib.h>





typedef struct no {
    Aluno dados;
    struct no *prox;
} No;




typedef struct pilha {
    No *topo;
    int tam_pilha;
} Pilha;





Pilha* cria_pilha() 
{
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    if (p != NULL)
        p->topo = NULL;
    p->tam_pilha = 0;
    return p;
}




int pilha_vazia(Pilha* pilha)
{
    if (pilha == NULL)
        return -1;
    return pilha->tam_pilha == 0;
}




int pilha_cheia(Pilha* pilha)
{
    return 0;
}




void limpar_pilha(Pilha* pilha)
{
    if (pilha != NULL) {
        No *no;
        while (pilha->topo != NULL) {
            no = pilha->topo;
            pilha->topo = pilha->topo->prox;
            free(no);
        }
        free(pilha);
    }
    pilha = NULL;
}




int push(Pilha* pilha, Aluno aluno)
{
    // Verifica se a pilha existe
    if (pilha == NULL)
        return -1;

    // Cria um novo nó para armazenar o aluno
    No *novo_no = (No*) calloc(1, sizeof(No));

    // Verifica se a alocação de memória foi bem-sucedida
    if (novo_no == NULL)
        return -2;

    // Configura o novo nó para apontar para o topo da pilha
    novo_no->dados = aluno;
    novo_no->prox = pilha->topo;

    // Atualiza o topo da pilha para apontar para o novo nó
    pilha->topo = novo_no;
    pilha->tam_pilha++;

    return 0;
}





int pop(Pilha* pilha, Aluno *aluno_removido)
{
    if (pilha == NULL)
        return -1;

    // Verifica se a pilha está vazia
    if (pilha_vazia(pilha))
        return -2;

    // Armazena o topo da pilha em um ponteiro auxiliar
    No *no_aux = pilha->topo;

    // Armazena o aluno removido
    *aluno_removido = no_aux->dados;

    // Atualiza o topo da pilha para apontar para o próximo nó
    pilha->topo = no_aux->prox;

    // Libera a memória alocada para o nó removido
    free(no_aux);
    pilha->tam_pilha--;

    return 0;
}





int consultar(Pilha* pilha, Aluno *aluno_consultado)
{
    if (pilha == NULL)
        return -1;

    // Verifica se a pilha está vazia
    if (pilha_vazia(pilha))
        return -2;

    // Armazena o topo da pilha em um ponteiro auxiliar
    No *no_aux = pilha->topo;

    // Armazena o aluno removido
    *aluno_consultado = no_aux->dados;

    return 0;
}





int mostrar_pilha(Pilha* pilha)
{
    if (pilha == NULL)
        return -1;

    // Verifica se a pilha está vazia
    if (pilha_vazia(pilha))
        return -2;

    // Armazena o topo da pilha em um ponteiro auxiliar
    No *no_aux = pilha->topo;

    // Percorre a pilha do topo até o fim
    while (no_aux != NULL) {
        printf("\nMatricula: [%d]\n", no_aux->dados.matricula);
        printf("Nome: [%s]\n", no_aux->dados.nome);
        printf("Nota: [%.2f]\n", no_aux->dados.nota);
        printf("\n");
        no_aux = no_aux->prox;
    }

    return 0;
}




// função que retira, caso exista, todoas as aparições de determinado aluno de matrícula x em uma pilha
// a função realoca todos os elementos em qualquer caso
int pop_item(Pilha *pilha, int matricula)
{
    if (pilha == NULL)
        return -1; 

    if (pilha_vazia(pilha))
        return -2; 

    int tam_pilha = pilha->tam_pilha;
    Aluno aluno_testado;
    Aluno alunos_retirados[tam_pilha];
    int i = 0;
    int achou_aluno = 0;

    // Percorre a pilha do topo ao início, removendo cada elemento e verificando-o
    while (tam_pilha > 0) {
        consultar(pilha, &aluno_testado);
        if (aluno_testado.matricula == matricula) {
            achou_aluno = 1;
            // Se encontrou o aluno, retira-o da pilha 
            pop(pilha, &alunos_retirados[i]);
        } else {
            pop(pilha, &alunos_retirados[i]);
            i++;
        }
        tam_pilha--;
    }

    if (achou_aluno) {
        while (i > 0) {
            i--;
            // Recoloca os alunos retirados de volta na pilha, do último para o primeiro
            push(pilha, alunos_retirados[i]);
        }
        return 1; // Achou o aluno e realocou toda a pilha
    } else {
        for (int j = tam_pilha; j > 0; j--) {
            // Recoloca todos os alunos retirados de volta na pilha, na ordem correta
            push(pilha, alunos_retirados[j - 1]);
        }
        return 0; // Não achou nenhum aluno
    }
}
