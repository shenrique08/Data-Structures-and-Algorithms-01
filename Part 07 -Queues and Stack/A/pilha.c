#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>




typedef struct pilha {
    int valores[MAX];
    int index_topo;

} Pilha;





Pilha *cria_pilha() 
{
    Pilha *pilha = (Pilha *) calloc(1, sizeof(Pilha));
    pilha->index_topo = 0;

    return pilha;
}



void limpar_pilha(Pilha *pilha) 
{
    free(pilha);
    pilha = NULL;
}



int pilha_vazia(Pilha *pilha) 
{
    if (pilha == NULL) 
        return -1;

    return pilha->index_topo == 0;
}



int pilha_cheia(Pilha *pilha) 
{
    if (pilha == NULL) 
        return -1;

    return pilha->index_topo == MAX;
}



int tamanho_pilha(Pilha *pilha)
{
    if (pilha == NULL) 
        return -1;

    return pilha->index_topo;
}




int push(Pilha *pilha, int valor)
{
    if (pilha == NULL) 
        return -1;

    if (pilha_cheia(pilha)) 
        return -2;

    pilha->valores[pilha->index_topo] = valor;
    pilha->index_topo++;

    return 0;
}




int pop(Pilha *pilha, int *valor)
{
    if (pilha == NULL) 
        return -1;

    if (pilha_vazia(pilha)) 
        return -2;

    pilha->index_topo--;
    *valor = pilha->valores[pilha->index_topo - 1];

    return 0;
}




void mostrar_pilha(Pilha *pilha)
{
    if (pilha == NULL) 
        return;

    printf("[");
    for (int i = 0; i < pilha->index_topo; i++) 
        printf(" %d", pilha->valores[i]);
    printf(" ]\n\n");
}





int consultar_pilha(Pilha *pilha, int *valor_consultado)
{
    if (pilha == NULL) 
        return -1;

    if (pilha_vazia(pilha)) 
        return -2;

    *valor_consultado = pilha->valores[pilha->index_topo - 1];

    return 0;
}