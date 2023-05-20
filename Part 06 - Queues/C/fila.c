#include "fila.h"
#include <stdio.h>
#include <stdlib.h>



typedef struct fila {
    int inicio, fim, tam_fila;
    int valores[MAX];

} Fila;




Fila *criar_fila()
{
    Fila *fila = (Fila *) calloc(1, sizeof(Fila));

    fila->inicio = 0;
    fila->fim = 0;
    fila->tam_fila = 0;

    return fila;
}



void limpar_fila(Fila *fila)
{
    if (fila != NULL) {
        free(fila);
        fila = NULL;
    }
}


int fila_cheia(Fila *fila)
{
    if (fila == NULL) 
        return -1;
    if (fila->tam_fila == MAX) // a fila está cheia, pois a quantidade de elementos nela contidos é igual ao seu tamanho
        return 1;
    return 0;
}





int fila_vazia(Fila *fila)
{
    if (fila == NULL) 
        return -1;
    if (fila->tam_fila == 0)
        return 1;
    return 0;
}





void print(Fila *fila)
{
    if (fila != NULL) { // Checks if the queue is not NULL
        int i = fila->inicio; // Stores the index of the queue's start
        int qtd = fila->tam_fila; // Stores the size of the queue

        printf("\n[ ");
        while (qtd > 0) { // Iterates while there are elements in the queue
            printf("%d ", fila->valores[i]); // Prints the current value from the queue
            i = (i + 1) % MAX; // Updates the index to the next element in a circular manner
            qtd--; // Decrements the remaining elements count
        }
    }

    printf("]\n\n");
}





int insere_na_fila(Fila *fila, int valor)
{
    if (fila == NULL) // Checks if the queue doesn't exist
        return -1;
    if (fila_cheia(fila) == 1) // Checks if the queue is full
        return -2;

    fila->valores[fila->fim] = valor; // Inserts the value at the last position of the queue
    fila->fim = (fila->fim + 1) % MAX; // Updates the 'fim' position, accounting for possible "empty slots" preceding the start.
    fila->tam_fila += 1; // Increments the queue size

    return 0;
}





int remove_da_fila(Fila *fila, int *valor_removido)
{
    if (fila == NULL) // Checks if the queue doesn't exist
        return -1;
    if (fila_vazia(fila) == 1) // Checks if the queue is empty
        return -2;

    *valor_removido = fila->valores[fila->inicio]; // Retrieves the value from the queue to be returned
    fila->tam_fila -= 1; // Decrements the queue size

    fila->inicio = (fila->inicio + 1) % MAX; // Updates the start index

    return 0;
}





int remove_negativos(Fila *fila)
{
    // Verifica se a fila é nula
    if (fila == NULL)
        return -1;

    // Verifica se a fila está vazia
    if (fila_vazia(fila) == 1)
        return -2;

    // Percorre o vetor do início ao fim da fila
    for (int i = fila->inicio; i < fila->fim; i++) {
        // Verifica se o valor atual é negativo
        if (fila->valores[i] < 0) {
            // Desloca todos os elementos posteriores uma posição para trás
            for (int j = i; j < fila->fim - 1; j++) {
                fila->valores[j] = fila->valores[j + 1];
            }

            // Atualiza o tamanho da fila e o índice de fim
            fila->tam_fila--;
            fila->fim--;

            // Decrementa o índice para verificar novamente o valor na posição atual
            i--;
        }
    }
    
    return 0;
}







int consultar(Fila *fila, int *valor)
{
    if (fila == NULL) // Checks if the queue doesn't exist
        return -1;
    if (fila_vazia(fila) == 1) // Checks if the queue is empty
        return -2;
        
    *valor = fila->valores[fila->inicio]; // Retrieves the value from the start of the queue and assigns it to 'valor'

    return 0;
}
