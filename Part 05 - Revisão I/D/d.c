#include <stdio.h>
#include <stdlib.h>


int main()
{
    char texto[401];
    int qtd_caracteres = 0;

    printf("Enter a text: (max = 400 caracteres) ");
    fgets(texto, sizeof(texto), stdin);

    // contando quantos caracteres foram digitados
    for (int i = 0; texto[i] != '\0'; i++) 
        qtd_caracteres += 1; 
        
    // criando um vetor de char com a quantidade dos caracteres ditigados
    char *c_digitados = (char *) calloc(qtd_caracteres, sizeof(char));     

    if (c_digitados == NULL) {
        printf("Erro ao alocar memoria");
        exit(1);
    }

    // realizando a cópia dos caractéres digitados
    for (int i = 0; i < qtd_caracteres; i++) {
            c_digitados[i] = texto[i];    

            // adiciona o '\0' ao final do vetor char 
            if (i == (qtd_caracteres - 1)) 
                c_digitados[i] = '\0';      
    }

    printf("\nCaracteres digitados: [%s]", c_digitados);

    // criando um vetor de contadores
    int alfabet[256] = {0};

    // contando a quantidade de vezes que cada caractere aparece no texto
    for (int i = 0; i < qtd_caracteres; i++) 
        alfabet[c_digitados[i]] += 1;


    // mostrando a quantidade de vezes que cada caractere aparece no texto
    printf("\nQuantidade de vezes que cada caractere aparece no texto:\n");
    for (int i = 0; i < 256; i++) {
        if (alfabet[i] > 0) 
            printf("'%c' aparece %d vez(es)\n", i, alfabet[i]);
    }

    return 0;
}