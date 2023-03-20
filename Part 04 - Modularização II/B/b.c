#include <stdio.h>
#include <stdlib.h>

int retorna_qtd_substituicoes (char *palavra, int qtd_palavras, char caractere)
{
    int qtd_substuicoes = 0;

    for (int i = 0; i < qtd_palavras; i++) {
        if (palavra[i] == caractere) {
            palavra[i] = '*';
            qtd_substuicoes += 1;
        }
    }

    return qtd_substuicoes;
}

int main()
{
    char *palavra, caractere;
    int tam_palavra;

    printf("Digite a quantidade de caracteres para a palavra: ");
    scanf("%d", &tam_palavra);
    getchar();

    palavra = (char *) calloc(tam_palavra, sizeof(char));
     if (palavra == NULL) {
        printf("Falha ao alocar o vetor:\n");
        exit(1);
    }

    printf("Digite a palavra: ");
    fgets(palavra, tam_palavra, stdin);

    printf("Digite qual caractere desja trocar por '*':");
    scanf("%c", &caractere);

    printf("\nPalavra ANTES da substituicao: %s", palavra);
    int qtd_substuicoes = retorna_qtd_substituicoes(palavra, tam_palavra, caractere);

    printf("\nPalavra DEPOIS da substituicao: %s", palavra);
    printf("\nQuantidade de substituicoes: %d\n\n", qtd_substuicoes);

    free(palavra);
    
    return 0;
}