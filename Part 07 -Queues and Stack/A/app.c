#include "pilha.h"
#include <stdio.h>



int main()
{
    Pilha *pilha = cria_pilha();

    push(pilha, 11);
    push(pilha, 34);

    int valor_removido;

    pop(pilha, &valor_removido);
    pop(pilha, &valor_removido);
    push(pilha, 23);
    push(pilha, 45);
    pop(pilha, &valor_removido);
    push(pilha, 121);
    push(pilha, 22);
    pop(pilha, &valor_removido);
    pop(pilha, &valor_removido);

    mostrar_pilha(pilha);

    return 0;
}