#include <stdio.h>
#include "string.h"

int main() 
{
    String* str = cria_string(20);

    associa_valor_string(str, "Hello World");
    exibe_string(str);

    printf("Tamanho: %d\n", retorna_tamanho_string(str));
    printf("Número de ocorrências de 'l': %d\n", conta_caractere_string(str, 'l'));
    
    return 0;
}
