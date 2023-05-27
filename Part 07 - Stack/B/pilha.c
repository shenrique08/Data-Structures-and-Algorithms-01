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

    // se esta afirmação for verdadeira, então será retornado 1, caso contrário, 0
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

    // como a lista existe e não está cheia, adicionaremos o valor na posição index_topo
    pilha->valores[pilha->index_topo] = valor;
    // e incrementaremos o index_topo
    pilha->index_topo++;

    return 0;
}




int pop(Pilha *pilha, int *valor_retirado)
{
    if (pilha == NULL) 
        return -1;

    if (pilha_vazia(pilha)) 
        return -2;

    // como a lista existe e não está vazia, retiraremos o valor na posição index_topo - 1
    *valor_retirado = pilha->valores[pilha->index_topo - 1];
    // e decrementaremos o index_topo
    pilha->index_topo--;

    return 0;
}




void mostrar_pilha(Pilha *pilha)
{
    if (pilha == NULL) 
        return;

    printf("[");
    for (int i = (pilha->index_topo - 1); i >= 0 ; i--) 
        printf(" %3d", pilha->valores[i]);
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




// função que verifica se duas pilhas são iguais, ou seja, se possuem os mesmos elementos na mesma ordem
int pilhas_iguais(Pilha *pilha1, Pilha *pilha2)
{
    if (pilha1 == NULL || pilha2 == NULL) 
        return -1;

    if (tamanho_pilha(pilha1) != tamanho_pilha(pilha2)) 
        return 0; // as pilhas não são iguais, caso o tamanho seja diferente
    int valor1, valor2; 
    // looping que começa no topo da pilha, vai retirando os valores e comparando-os
    for (int i = (pilha1->index_topo - 1); i >= 0; i--) {
        pop(pilha1, &valor1);
        pop(pilha2, &valor2);

        // neste momento, tenho os dois valores do atual topo das duas pilhas
        // então, basta compará-los
        if (valor1 != valor2) 
            return 0; // as pilhas não são iguais
    }

    return 1;

    // agora, irei inserir os valores de volta nas pilhas, para que elas fiquem como estavam antes
}