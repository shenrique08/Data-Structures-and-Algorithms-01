#ifndef LINKED_LIST_H
#define LINKED_LIST_H


typedef struct _snode Snode;
typedef struct _linked_list LinkedList;


Snode *Snode_create(int val);

LinkedList *LinkedList_create();

void LinkedList_destroy(LinkedList **L_ref);

void LinkedList_add_first(LinkedList *L, int val);

void LinkedList_print(const LinkedList *L);

void LinkedList_add_last_slow(LinkedList *L, int val);

void LinkedList_add_last_fast(LinkedList *L, int val);

// remove o primeiro nó encontrado que possua o valor "val"
int LinkedList_remove_inicio(LinkedList *L, int val);

int LinkedList_remove_posicao(LinkedList *L, int val);

int LinkedList_size_slow(const LinkedList *L);

int LinkedList_first_val(const LinkedList *L);

int LinkedList_last_val(const LinkedList *L);

int LinkedList_get_val(const LinkedList *L, int index);



#endif