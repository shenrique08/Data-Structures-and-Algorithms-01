#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 5
#define COLUNAS 10

int main() 
{
    int matriz[LINHAS][COLUNAS];
    int vetor[LINHAS];
    int i, j;

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    // Preenche a matriz com números aleatórios entre 0 e 10
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            matriz[i][j] = rand() % 11;
        }
    }

    // Soma as linhas da matriz e armazena os resultados no vetor
    for (i = 0; i < LINHAS; i++) {
        int soma = 0;
        for (j = 0; j < COLUNAS; j++) 
            soma += matriz[i][j];
        vetor[i] = soma;
    }

    // Imprime a matriz e o vetor resultante
    printf("Matriz:\n");
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) 
            printf("[%2d] ", matriz[i][j]);
        printf("\n");
    }

    printf("\nVetor de somas:\n");
    for (i = 0; i < LINHAS; i++) 
        printf("Soma linha [%d] = [%d] \n", i, vetor[i]);
    printf("\n");


    return 0;
}