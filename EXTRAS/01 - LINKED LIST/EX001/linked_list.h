#ifndef LINKED_LIST_H
#define LINKED_LIST_H


typedef struct _simple_node {
    int value;
    struct _simple_node *next;
} SimpleNode;



typedef struct _linked_list {
    SimpleNode *begin;
} LinkedList;



LinkedList *LinkedList_create();
SimpleNode	*SimpleNode_create(int value);


#endif