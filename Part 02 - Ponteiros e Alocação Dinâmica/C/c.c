#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int **matriz1, **matriz2, **matriz_soma;
    int i, j;
    srand(time(NULL));

    matriz1 = (int **) calloc(3, sizeof(int*)); // alocando o vetor linha
    for (i = 0; i < 3; i++)
        matriz1[i] = (int *) calloc(3, sizeof(int)); // alocando o vetor coluna

    if (matriz1 == NULL) {
        printf("Falha ao alocar a matriz1!\n");
        exit(1);
    }

    matriz2 = (int **) calloc(3, sizeof(int *)); // alocando o vetor linha
    for (i = 0; i < 3; i++)
        matriz2[i] = (int *) calloc(3, sizeof(int)); // alocando o vetor coluna

    if (matriz2 == NULL) {
        printf("Falha ao alocar a matriz2!\n");
        exit(1);
    }

    // preenchendo a primeira matriz com números pseudo-aleatórios
    for (i = 0; i < 3; i++) 
        for (j = 0; j < 3; j++) 
            matriz1[i][j] = rand() % 100;

    // preenchendo a segunda matriz com números pseudo-aleatórios
    for (i = 0; i < 3; i++) 
        for (j = 0; j < 3; j++) 
            matriz2[i][j] = rand() % 100;


    matriz_soma = (int **) calloc(3, sizeof(int*)); // alocando o vetor linha da matriz soma
    for (i = 0; i < 3; i++)
        matriz_soma[i] = (int *) calloc(3, sizeof(int)); // alocando o vetor coluna da matriz soma
    
    if (matriz_soma == NULL) {
        printf("Falha ao alocar a matriz soma!\n");
        exit(1);
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz_soma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }



    printf("\nMATRIZ1:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("[%2d] ", matriz1[i][j]);
        }
        printf("\n");
    }

    printf("\n\nMATRIZ2:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("[%2d] ", matriz2[i][j]);
        }
        printf("\n");
    }

    printf("\n\nMATRIZ_SOMA:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("[%3d] ", matriz_soma[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++)
        free(matriz1[i]);
    free(matriz1);

    for (i = 0; i < 3; i++) 
        free(matriz2[i]);
    free(matriz2);

    for (i = 0; i < 3; i++)
        free(matriz_soma[i]);
    free(matriz_soma);

    
    return 0;
}