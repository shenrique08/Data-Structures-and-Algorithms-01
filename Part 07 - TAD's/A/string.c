#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "string.h"



struct string 
{
    char* valor;
    int tamanho_maximo;
};



String* cria_string(int tamanho_maximo) 
{
    String* str = (String*) malloc(sizeof(String));
    str->valor = (char*) malloc(sizeof(char) * (tamanho_maximo + 1));
    str->tamanho_maximo = tamanho_maximo;
    return str;
}



void associa_valor_string(String* str, char* valor) {
    strncpy(str->valor, valor, str->tamanho_maximo);
    str->valor[str->tamanho_maximo] = '\0';
}



int retorna_tamanho_string(String* str) 
{
    return strlen(str->valor);
}



int conta_caractere_string(String* str, char caractere) 
{
    int cont = 0;
    for (int i = 0; i < strlen(str->valor); i++) {
        if (str->valor[i] == caractere) {
            cont++;
        }
    }
    return cont;
}



void exibe_string(String* str) 
{
    printf("%s\n", str->valor);
}