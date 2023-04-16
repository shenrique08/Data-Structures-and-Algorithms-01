#include "linked_list.h"
#include <stdio.h>



int main()
{
    LinkedList *L = LinkedList_create();
    
    /*
    LinkedList_add_first(L, 5);
    LinkedList_print(L);

    LinkedList_add_first(L, 4);
    LinkedList_print(L);

    LinkedList_add_first(L, 2);
    LinkedList_print(L);

    LinkedList_add_first(L, 10);
    LinkedList_print(L);
    */


    LinkedList_add_last_fast(L, 10);
    LinkedList_add_last_fast(L, 2);
    LinkedList_add_last_fast(L, 4);
    LinkedList_add_last_fast(L, 5);
    LinkedList_add_last_fast(L, 7);
    LinkedList_print(L);

    LinkedList_remove_inicio(L, 10);
    LinkedList_print(L);


    LinkedList_remove_posicao(L, 5);
    LinkedList_print(L);

    printf("\nFirst: %d\n", LinkedList_first_val(L));
    printf("Last: %d\n", LinkedList_last_val(L));
    printf("[2 position]: %d\n", LinkedList_get_val(L, 2));
    printf("Size: %d\n\n", LinkedList_size_slow(L));

    

    return 0;
}