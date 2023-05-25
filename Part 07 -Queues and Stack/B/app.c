#include "pilha.h"
#include <stdio.h>



int main()
{
    Pilha *pilha1 = cria_pilha();
    Pilha *pilha2 = cria_pilha();

    // push na pilha 1
    push(pilha1, 5);
    push(pilha1, 90);
    push(pilha1, 12);

    // push na pilha 2
    push(pilha2, 78);
    push(pilha2, 90);
    push(pilha2, 12);

    printf("\nPilha 1: ");
    mostrar_pilha(pilha1);

    printf("Pilha 2: ");
    mostrar_pilha(pilha2);

    int result = pilhas_iguais(pilha1, pilha2);
    if (result == 1)
        printf("\nAs duas pilhas [sao iguais]\n\n");
    else 
        printf("\nAs duas pilhas [sao diferentes]\n\n");


    limpar_pilha(pilha1);
    limpar_pilha(pilha2);

    return 0;
}