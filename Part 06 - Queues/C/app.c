#include "fila.h"
#include <stdio.h>



int main()
{
    Fila *fila1 = criar_fila();
    
    printf("\n========= APOS CRIACAO DA [FILA1] =========\n");
    insere_na_fila(fila1, 10);
    insere_na_fila(fila1, -20);
    insere_na_fila(fila1, 30);
    insere_na_fila(fila1, -45);
    insere_na_fila(fila1, 21);
    print(fila1);
    remove_negativos(fila1);

    printf("\n========= FILA1 APOS REMOCAO DOS VALORES NEGATIVOS =========\n");
    print(fila1);


    return 0;
}