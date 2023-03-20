#include <stdio.h>
#include <stdlib.h>
#include <time.h.>

void swap (int *valor1, int *valor2)
{
    int temp = *valor1;
    *valor1 = *valor2;
    *valor2 = temp;
}

void inverte (int *vetor, int tamanho_vetor)
{
    for (int i = 0; i < tamanho_vetor / 2; i++) 
        swap (&vetor[i], &vetor[tamanho_vetor - 1] - i);

}

int main()
{
    int *vetor, tamanho_vetor;
    srand(time(NULL));

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho_vetor);

    vetor = (int *) calloc(tamanho_vetor, sizeof(int));
    if (vetor == NULL) {
        printf("Falha ao alocar o vetor:\n");
        exit(1);
    }
    
    printf("\nVetor ANTES da troca:\n");
    for (int i = 0; i < tamanho_vetor; i++) {
        vetor[i] = rand() % 100;
        printf("[%d] ", vetor[i]);
    }
    inverte(vetor, tamanho_vetor);

    printf("\nVetor DEPOIS da troca:\n");
    for (int i = 0; i < tamanho_vetor; i++) {
        printf("[%d] ", vetor[i]);
    }

    free(vetor);

    return 0;
}