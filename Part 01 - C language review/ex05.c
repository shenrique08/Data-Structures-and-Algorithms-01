#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qtd_numeros, *numeros, soma_maiores_que10 = 0, qtd_menores_que10 = 0;

    printf("\nDigite a quantidade de numeros inteiros que deseja informar: ");
    scanf("%d", &qtd_numeros);

    numeros = (int *) calloc(qtd_numeros, sizeof(int));

    for (int i = 0; i < qtd_numeros; i ++) {
        printf("Informe o [%do] valor (Digite '10' para encerrar): ", i + 1);
        scanf("%d", &numeros[i]);
        if (numeros[i] == 10)
            break;


        if (numeros[i] > 10)
            soma_maiores_que10 += numeros[i];
        if (numeros[i] < 10)
            qtd_menores_que10 += 1;
    }

    printf("\nSoma dos maiores do que 10 = %d\n", soma_maiores_que10);
    printf("Quantidade dos menores do que 10 = %d\n\n", qtd_menores_que10);

    free(numeros);
    
    return 0;
}