#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>




typedef struct _snode {
    int val;
    struct _snode *next;
} SNode;


typedef struct _linked_list {
    SNode *begin;
    Snode *end;
    int size;
} LinkedList;



Snode *Snode_create(int val)
{
    SNode *snode = (Snode *) calloc(1, sizeof(SNode));
    snode->val = val;
    snode->next = NULL;
    

    return snode;
}



void LinkedList_destroy(LinkedList **L_ref)
{
    LinkedList *L = *L_ref;

    Snode *p = L->begin;
    Snode *aux = NULL;

    while (p != NULL) {
        aux = p;
        p = p->next;
        free(aux);
    }

    free(L_ref);
    *L_ref = NULL;
}



LinkedList *LinkedList_create() {
    LinkedList *L = (LinkedList *) calloc(1, sizeof(LinkedList));

    L->begin = NULL;
    L->size = 0;

    return L;
}



void LinkedList_add_first(LinkedList *L, int val)
{
    // a lista está vazia
    if (L->begin == NULL) {
        SNode *p = Snode_create(val);
        L->begin = p;
    }
    else {
        SNode *p = Snode_create(val);
        p->next = L->begin;
        L->begin = p;
    }

    L->size += 1;
}



void LinkedList_add_last_slow(LinkedList *L, int val)
{
    SNode *q = Snode_create(val);
    // se a lista estiver vazia
    if (L->begin == NULL) 
        L->begin = q; // O L vai apontar para o começo da lista
    
    else {
        SNode *p = L->begin;
        
        // enquanto o p não é o último nó, ou seja, enquanto houver um próximo nó
        while (p->next != NULL) {
            p = p->next;
        }
        // neste momento, o ponteiro p aponta para o nó final da lista

        // corrige o encadeamento, ou seja, faz com que o próximo elemento atual do último nó aponte para o novo último nó
        p->next = q;
    }

    L->size += 1;
    
}



void LinkedList_add_last_fast(LinkedList *L, int val)
{
    SNode *q = Snode_create(val);

    // se a lista estiver cheia
    if (L->begin == NULL) {
        L->begin = q;
        L->end = q;

    }
    else {
        L->end->next = q;
        L->end = L->end->next;
    }

    L->size += 1;
}



void LinkedList_print(const LinkedList *L)
{
    SNode *p = L->begin;
    
    // enquanto p não chegou ao fim da lista, isto é, enquanto o p não estiver apontando para um nó da lista
    printf("\nL -> ");
    while (p != NULL) {
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n\n");
}



int LinkedList_remove_inicio(LinkedList *L, int val)
{
    if (L == NULL)
        return 2;
    
    // caso 1 - o elemento está na cabeça da lista
    if (L->begin->val == val) {
        SNode *pos = L->begin;
        L->begin = L->begin->next;
        free(pos);
    }

    L->size -= 1;

    return 0;
}



int LinkedList_remove_posicao(LinkedList *L, int val)
{
    if (L == NULL)
        return 2;

    // caso 1 - o elemento está na cabeça da lista
    if (L->begin->val == val) {
        SNode *pos = L->begin;
        L->begin = L->begin->next;
        free(pos);
    }

    // caso o elemento esteja no meio da lista
    else {
        Snode *prev = L->begin;
        Snode *pos = L->begin->next;

        // enquanto a lista ainda tiver elementos para percorrer/checar e o valor do nó apontado pelo ponteiro pós for diferente do valor desejado, avance os ponteiros auxiliares (prev e pos) para os próximos nós da lista
        while (pos != NULL && pos->val != val) {
            prev = prev->next;
            pos = pos->next;
        }

        // um nó de valor val foi encontrado e é apontado pelo ponteiro pos
        if (pos != NULL) {
            prev->next = pos->next;

            // se o elemento a ser removido é o último nó da lista
            // caso 3 elemento está no final da lista - removendo o último nó da lista
            if (pos->next == NULL) {
                L->end = prev;
            }

            free(pos);
        }

    }

    L->size -= 1;

    return 0;
}



int LinkedList_size_slow(const LinkedList *L)
{
    size_t size = 0;
    SNode *p = L->begin;

    while (p != NULL) {
        size += 1;
        p = p->next;
    }

    // outra forma de fazer utilizando o for
    //for (SNode *p = L->begin; p != NULL; p->next)
    //    size += 1;

    return size;
}



int LinkedList_first_val(const LinkedList *L)
{
    if (L == NULL) {
        fprintf(stderr, "ERROR in 'LinkedList_first_val'\nList is empty\n");
        exit(EXIT_FAILURE);
    }
    else {
        return L->begin->val;
    }

}



int LinkedList_last_val(const LinkedList *L)
{
    if (L == NULL) {
        fprintf(stderr, "ERROR in 'LinkedList_first_val'\nList is empty\n");
        exit(EXIT_FAILURE);
    }
    else {
        return L->end->val;
    }

}



int LinkedList_get_val(const LinkedList *L, int index)
{
    if (L == NULL) {
        fprintf(stderr, "ERROR in 'LinkedList_first_val'\nList is empty\n");
        exit(EXIT_FAILURE);
    }
    else if (index < 0 || index >= L->size) {
        fprintf(stderr, "ERROR in 'LinkedList_first_val'\nInvalid Index\n");
        exit(EXIT_FAILURE);
    }
    else {
        int i = 0;
        Snode *p = L->begin;

        while (i != index) {
            p = p->next;
            i += 1;
        }

        return p->val;
    }
}