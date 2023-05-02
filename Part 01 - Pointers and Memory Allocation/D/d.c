#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, *vetor, i, j = 0;

    printf("Informe a quantidade de valores que deseja alocar para o vetor: ");
    scanf("%d", &n);

    vetor = (int *) calloc(n, sizeof(int));

    if (vetor == NULL) {
        printf("Falha ao alocar memoria!\n");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        printf("Informe o [%do] valor: ", i + 1);
        scanf("%d", &vetor[i]);
    }


    for (i = 0; i < n; i++) {
        if (vetor[i] % 2 != 0) {
            vetor[j] = vetor[i];
            j++;
        }
    }

    vetor = (int*) realloc(vetor, j * sizeof(int));
    
    printf("\nVetor sem numeros impares: ");
    for(i = 0; i < j; i++) {
        printf("%d ", vetor[i]);
    }
    
    // liberar a memória alocada para o vetor
    free(vetor);
    
    return 0;
}