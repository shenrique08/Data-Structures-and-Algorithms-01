#include <stdio.h>
#include <stdlib.h>

#define QTD_SORTEADOS 5
#define QTD_APOSTADOS 5


int main()
{
    int num_sorteados[QTD_SORTEADOS], num_apostados[QTD_APOSTADOS];
    int qtd_acertados = 0, acertos = 0;

    int *num_corretos;


    for (int i = 0; i < QTD_SORTEADOS; i++) {
        printf("Digite o [%do] valor sorteado: ", i + 1);
        scanf("%d", &num_sorteados[i]);
    }

    printf("\n");
    for (int i = 0; i < QTD_APOSTADOS; i++) {
        printf("Digite o [%do] valor apostado: ", i + 1);
        scanf("%d", &num_apostados[i]);
    }


    // contando quantos números o usuário acertou
    for (int i = 0; i < QTD_APOSTADOS; i++) {
        for (int j = 0; j < QTD_SORTEADOS; j++) {
            if (num_apostados[i] == num_sorteados[j])
                qtd_acertados += 1;
        }
    }  

    // alocando o vetor com o tamnho da quantidade de acertos
    num_corretos = (int *) calloc(qtd_acertados, sizeof(int));
    if (num_corretos == NULL) {
        printf("Falha ao alocar o vetor\n");
        exit(1);
    }


    // preenchendo o vetor com os números que o usuário acertou
    for (int i = 0; i < QTD_APOSTADOS; i++) {
        for (int j = 0; j < QTD_SORTEADOS; j++) {
            if (num_apostados[i] == num_sorteados[j]) {
                num_corretos[acertos] = num_apostados[i];
                acertos += 1;
            }
        }
    }


    printf("\nNumeros sorteados: \n");
    for (int i = 0; i < QTD_SORTEADOS; i++) {
        printf("[%d] ", num_sorteados[i]);
    }

    printf("\n\nNumeros acertados: \n");
    for (int i = 0; i < qtd_acertados; i++) {
        printf("[%d] ", num_corretos[i]);
    }

    float porcentagem_acertos = ((float) qtd_acertados / QTD_APOSTADOS) * 100;
    printf("\nPorcentagem de acerto: %.3f%%\n\n", porcentagem_acertos);

    free(num_corretos);

    return 0;
}