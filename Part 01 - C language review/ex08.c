#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char titulo[50];
    int ano_edicao;
    float num_pags;
    float preco;

} Livros;

int main()
{
    int qtd_cadastro;

    printf("Quantos livros deseja cadastrar? ");
    scanf("%d", &qtd_cadastro);
    fflush(stdin);

    Livros *livros = (Livros *) calloc(qtd_cadastro, sizeof(*livros));

    if (livros == NULL) {
        printf("Falha ao alocar memoria!\n");
        exit(1);
    }

    printf("\n----- CADASTRO DOS LIVROS -----\n\n");
    for (int i = 0; i < qtd_cadastro; i++) {
        printf("\nInforme o titulo do [%do] livro: ", i+1);
        fgets(livros[i].titulo, 100, stdin);

        printf("Informe o ano de edicao do [%do] livro: ", i+1);
        scanf("%d", &livros[i].ano_edicao);

        printf("Informe o numero de paginas do [%do] livro: ", i+1);
        scanf("%f", &livros[i].num_pags);

        printf("Informe o preco do [%do] livro: R$", i+1);
        scanf("%f", &livros[i].preco);
        fflush(stdin);
    }

    float soma_paginas = 0;
    for (int i = 0; i < qtd_cadastro; i++)
        soma_paginas += livros[i].num_pags;
        
    float media_paginas = soma_paginas / qtd_cadastro;

    printf("\nA media do numero de paginas por livro eh %.3f\n\n", media_paginas);

    free(livros);
    
    return 0;
}