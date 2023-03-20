#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplica_por_escalar (int *vetor, int tam_vetor, int multiplicador)
{
    for (int i = 0; i < tam_vetor; i++) 
        vetor[i] = vetor[i] * multiplicador;
}


int main()
{
    int *vetor, tamanho_vetor, multiplicador;
    srand(time(NULL));

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho_vetor);

    vetor = (int *) calloc(tamanho_vetor, sizeof(int));

    if (vetor == NULL) {
        printf("Falha ao alocar o vetor:\n");
        exit(1);
    }

    printf("Digite o valor inteiro que deseja multiplicar o vetor: ");
    scanf("%d", &multiplicador);

    printf("\nVetor ANTES da multiplicacao por [%d]\n", multiplicador);
    for (int i = 0; i < tamanho_vetor; i++) {
        vetor[i] = rand() % 100;
        printf("[%2d] ", vetor[i]);
    }
    multiplica_por_escalar(vetor, tamanho_vetor, multiplicador);

    printf("\n\nVetor DEPOIS da multiplicacao por [%d]\n", multiplicador);
    for (int i = 0; i < tamanho_vetor; i++) 
        printf("[%2d] ", vetor[i]);

    free(vetor);

    return 0;
}