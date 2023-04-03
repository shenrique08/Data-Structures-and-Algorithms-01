#include <stdio.h>
#include "set.h"

int main() 
{
    Set* A = create_set();
    Set* B = create_set();
    Set* C;

    insert(A, 1);
    insert(A, 2);
    insert(A, 3);
    insert(A, 4);
    insert(B, 3);
    insert(B, 4);
    insert(B, 5);
    insert(B, 6);

    printf("Conjunto A:\n");
    for (int i = 0; i < A->size; i++) {
        printf("%d ", A->elements[i]);
    }
    printf("\n");

    printf("Conjunto B:\n");
    for (int i = 0; i < B->size; i++) {
        printf("%d ", B->elements[i]);
    }
    printf("\n");

    printf("Conjunto A U B:\n");
    C = union_set(A, B);
    for (int i = 0; i < C->size; i++) {
        printf("%d ", C->elements[i]);
    }
    printf("\n");

    printf("Conjunto A ∩ B:\n");
    C = intersection(A, B);
    for (int i = 0; i < C->size; i++) {
        printf("%d ", C->elements[i]);
    }
    printf("\n");

    printf("Conjunto A - B:\n");
    C = difference(A, B);
    for (int i = 0; i < C->size; i++) {
        printf("%d ", C->elements[i]);
    }
    printf("\n");

    remove_member(A, 1);
    remove_member(B, 5);

    printf("Conjunto A depois de remover 1:\n");
    for (int i = 0; i < A->size; i++) {
        printf("%d ", A->elements[i]);
    }
    printf("\n");

    printf("Conjunto B depois de remover 5:\n");
    for (int i = 0; i < B->size; i++) {
        printf("%d ", B->elements[i]);
    }
    printf("\n");

    destroy_set(A);
    destroy_set(B);
    destroy_set(C);

    return 0;
}