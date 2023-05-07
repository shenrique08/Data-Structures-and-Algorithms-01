#include "lista.h"
#include <stdio.h>



int main()
{
    Lista *lista1 = criar_lista();
    Lista *lista2 = criar_lista();

    insere_inicio(lista1, 10);
    insere_final(lista1, 67);
    insere_inicio(lista1, 25);
    inserir_pos(lista1, 34, 3);
    insere_ordenado(lista1, 5);
    printf("\n========== [LISTA 1] APOS AS INSERCOES ============\n\n");
    imprime(lista1);



    insere_inicio(lista2, 5);
    insere_final(lista2, 54);
    insere_inicio(lista2, 29);
    inserir_pos(lista2, 94, 2);
    insere_ordenado(lista2, 8);
    printf("\n========== [LISTA 2] APOS AS INSERCOES ============\n\n");
    imprime(lista2);

    listas_iguais(lista1, lista2);
    

    return 0;
}