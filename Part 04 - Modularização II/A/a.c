#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void calcula_media (int *vetor, int tamanho_vetor, float *media, int *maior)
{
    float soma_vetor = 0;
    *maior = vetor[0];

    for (int i = 0; i < tamanho_vetor; i++) {
        soma_vetor += vetor[i];

        if (vetor[i] > *maior)
            *maior = vetor[i];
    }

    *media = (soma_vetor / tamanho_vetor);
}

int main()
{
    int tamanho, *vetor, maior;
    float media;
    srand(time(NULL));

    printf("Informe a quantidade de valores que deseja colocar no vetor: ");
    scanf("%d", &tamanho);

    vetor = (int *) calloc(tamanho, sizeof(int));
     if (vetor == NULL) {
        printf("Falha ao alocar o vetor:\n");
        exit(1);
    }
    
    // preenchendo o vetor com números pseudoaleatorios  
    for (int i = 0; i < tamanho; i++) 
        vetor[i] = (rand() % 10) + 1;
    
    printf("\nVALORES GERADOS:\n");
    for (int i = 0; i < tamanho; i++)
        printf("[%d] ", vetor[i]);

    calcula_media(vetor, tamanho, &media, &maior);

    printf("\nA media foi %.3f\n", media);
    printf("O maior numero dentro do vetor foi %d\n\n", maior);

    free(vetor);
    
    return 0;
}