#include "fila.h"
#include <stdio.h>



int main()
{
    Fila *fila = criar_fila();
    printf("\n========= APOS CRIACAO DA FILA =========\n");
    print(fila);

    insere_na_fila(fila, 10);
    printf("\n========= APOS INSERCAO DO [10] NA FILA =========\n");
    print(fila);
    insere_na_fila(fila, 20);
    printf("\n========= APOS INSERCAO DO [20] NA FILA =========\n");
    print(fila);

    int valor_removido;
    remove_da_fila(fila, &valor_removido);
    printf("\n========= APOS REMOCAO DO PRIMEIRO ELEMENTO DA FILA =========\n");
    print(fila);

    insere_na_fila(fila, 30);
    printf("\n========= APOS INSERCAO DO [30] NA FILA =========\n");
    print(fila);
    insere_na_fila(fila, 45);
    printf("\n========= APOS INSERCAO DO [45] NA FILA =========\n");
    print(fila);
    insere_na_fila(fila, 21);
    printf("\n========= APOS INSERCAO DO [21] NA FILA =========\n");
    print(fila);

    remove_da_fila(fila, &valor_removido);
    printf("\n========= APOS REMOCAO DO PRIMEIRO ELEMENTO DA FILA =========\n");
    print(fila);
    remove_da_fila(fila, &valor_removido);
    printf("\n========= APOS REMOCAO DO PRIMEIRO ELEMENTO DA FILA =========\n");
    print(fila);

    int valor_consultado;
    consultar(fila, &valor_consultado);
    printf("\nValor consultado na fila: [%d]\n\n", valor_consultado);

    return 0;
}