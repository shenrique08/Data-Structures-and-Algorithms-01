#include <stdio.h>
#include <stdlib.h>

int exclui_repetidos (int *vetor, int tamanho_vet)
{
    int qtd_exclusoes = 0;

    // percorre o vetor começando pela segunda posição, pois não há como compara o da primeira posição com o anterior
    for (int i = 1; i < tamanho_vet; i++) {
        // caso o valor do vetor na posição i seja igual ao valor da posição imediatamente anterior
        if (vetor[i] == vetor[i - 1]) { 
            qtd_exclusoes += 1;
            
        } else {
            vetor[i - qtd_exclusoes] = vetor[i];
        }
    }

    return qtd_exclusoes;
}

int main()
{
    int *vetor, tamanho_vet;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho_vet);

    vetor = (int *) calloc(tamanho_vet, sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    for (int i = 0; i < tamanho_vet; i++) {
        printf("Digite o [%do] valor: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\n\nValores digitados: \n");
    for (int i = 0; i < tamanho_vet; i++) 
        printf("[%d] ", vetor[i]);
        

    int qtd_exclusoes = exclui_repetidos(vetor, tamanho_vet);

    vetor = (int*) realloc(vetor, (tamanho_vet - qtd_exclusoes) * sizeof(int));
    
    printf("\nVetor apos a exclusao dos valores repetidos: ");
    for (int i = 0; i < (tamanho_vet - qtd_exclusoes); i++) {
        printf("[%d] ", vetor[i]);
    }

    printf("\n\nQuantidade de valores excluidos: [%d]\n\n", qtd_exclusoes);
    
    free(vetor);
    
    return 0;
}