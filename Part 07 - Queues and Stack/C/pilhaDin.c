#include "pilhaDin.h"
#include <stdio.h>
#include <stdlib.h>





typedef struct no {
    Aluno dados;
    struct no *prox;
} No;



typedef struct pilha {
    No *topo;
} Pilha;





Pilha* cria_pilha() 
{
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    if (p != NULL)
        p->topo = NULL;
    return p;
}


