#include "ListaSequencial.h"
#include <stdio.h>
#include <stdlib.h>



Lista *cria_lista()
{
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    if (lista != NULL)
        lista->qtd = 0;
    return lista;
}



void libera_lista(Lista *lista)
{
    free(lista);
}



int tamanho_lista(Lista *lista)
{
    if (lista == NULL)
        return -1;
    else 
        return lista->qtd;
}



int lista_cheia(Lista *lista)
{
    if (lista == NULL)
        return -1;
    return (lista->qtd == MAX);
}



int lista_vazia(Lista *lista)
{
    if (lista == NULL)
        return -1;
    else 
        return (lista->qtd == 0);
}



int insere_lista_inicio(Lista *lista, struct aluno aluno)
{
    if (lista == NULL) return 0;
    if (lista_cheia(lista)) return 0;

    for (int i = lista->qtd - 1; i >= 0; i--) 
        lista->dados[i + 1] = lista->dados[i];
    
    lista->dados[0] = aluno;
    lista->qtd += 1;

    return 1;
}



int remove_inicio(Lista *lista)
{
    if (lista == NULL) 
        return 0;
    if (lista->qtd == 0)
        return 0;
    
    for (int k = 0; k < lista->qtd - 1; k++)
        lista->dados[k] = lista->dados[k + 1];
    lista->qtd -= 1;

    return 1;
}