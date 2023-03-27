#include <stdio.h>
#include <stdlib.h>

int *retorna_vetor_alocado (int tam_vetor, int num_preencher)
{
    int *vetor = (int *) calloc(tam_vetor, sizeof(int));

    if (vetor == NULL) {
        printf("Falha ao alocar o vetor: ");
        exit(1);
    }

    for (int i = 0; i < tam_vetor; i++)
        vetor[i] = num_preencher;
    
    return vetor;
    
}

int main()
{
    int *vetor, tam_vetor, inserir;

    printf("Digite o tamanho do vetor que deseja alocar: ");
    scanf("%d", &tam_vetor);

    printf("Digite um inteiro que deseja inserir no vetor: ");
    scanf("%d", &inserir);

    vetor = retorna_vetor_alocado(tam_vetor, inserir);

    printf("\nVetor alocado: \n");
    for (int i = 0; i < tam_vetor; i++)
        printf("[%d] ", vetor[i]);

    free(vetor);

    return 0;
}