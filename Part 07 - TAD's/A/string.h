#ifndef STRING_H
#define STRING_H

typedef struct string String;

String* cria_string(int tamanho_maximo);
void associa_valor_string(String* str, char* valor);
int retorna_tamanho_string(String* str);
int conta_caractere_string(String* str, char caractere);
void exibe_string(String* str);


#endif /* STRING_H */