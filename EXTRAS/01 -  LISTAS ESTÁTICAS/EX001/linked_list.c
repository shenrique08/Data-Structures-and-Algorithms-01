#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>



LinkedList *LinkedList_create()
{
    LinkedList *L = (LinkedList *) calloc(1, sizeof(LinkedList));
    L->begin = NULL;
}



SimpleNode	*SimpleNode_create(int value)
{
    SimpleNode *simplenode = (SimpleNode *) calloc(1, sizeof(SimpleNode));
    simplenode->value = value;
    simplenode->next = NULL;
}

