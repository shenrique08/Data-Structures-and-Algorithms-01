#include "lista.h"
#include <stdio.h>



int main()
{
    Lista *lista = criar_lista();

    insere_inicio(lista, 10);
    insere_final(lista, 67);
    insere_inicio(lista, 25);
    insere_final(lista, 99);
    inserir_pos(lista, 34, 2);
    inserir_pos(lista, 78, 4);
    insere_ordenado(lista, 5);
    insere_ordenado(lista, 28);
    insere_final(lista, 99);
    insere_final(lista, 99);
    printf("\n========== LISTA APOS AS INSERCOES ============\n\n");
    imprime(lista);



    remove_inicio(lista);
    remove_final(lista);
    printf("\n========== LISTA APOS AS REMOCOES ============\n\n");
    imprime(lista);

    remove_pos(lista, 3);
    printf("\n========== LISTA APOS REMOCAO DO VALOR DE POSICAO 3 ============\n\n");
    imprime(lista);


    printf("Tamanho da lista = [%d]\n\n", tam_lista(lista));
    printf("\nQuantidade de aparicoes do valor 99: [%d]\n\n", qtd_dado_numero(lista, 99));
    maior_valor(lista);


    return 0;
}