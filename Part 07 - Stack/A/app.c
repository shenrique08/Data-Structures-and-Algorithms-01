#include "pilha.h"
#include <stdio.h>



int main()
{
    Pilha *pilha = cria_pilha();

    push(pilha, 11);
    push(pilha, 34);

    int valor_removido[5];

    pop(pilha, &valor_removido[0]);
    pop(pilha, &valor_removido[1]);
    push(pilha, 23);
    push(pilha, 45);
    pop(pilha, &valor_removido[2]);
    push(pilha, 121);
    push(pilha, 22);
    pop(pilha, &valor_removido[3]);
    pop(pilha, &valor_removido[4]);

    mostrar_pilha(pilha);;;

    limpar_pilha(pilha);

    return 0;
}