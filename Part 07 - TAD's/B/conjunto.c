#include <stdlib.h>
#include <stdio.h>
#include "set.h"

struct set {
    int* elements;
    int size;
};

Set* create_set() {
    Set* new_set = (Set*) malloc(sizeof(Set));
    if (new_set == NULL) {
        printf("Erro ao alocar memória para o conjunto.\n");
        exit(1);
    }
    new_set->elements = NULL;
    new_set->size = 0;
    return new_set;
}

void destroy_set(Set* set) {
    free(set->elements);
    free(set);
}

int is_member(Set* set, int x) {
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == x) {
            return 1; // true
        }
    }
    return 0; // false
}

void insert(Set* set, int x) {
    if (is_member(set, x)) {
        return; // x já está no conjunto
    }
    set->size++;
    set->elements = (int*) realloc(set->elements, set->size * sizeof(int));
    if (set->elements == NULL) {
        printf("Erro ao alocar memória para o conjunto.\n");
        exit(1);
    }
    set->elements[set->size - 1] = x;
}

void remove_member(Set* set, int x) {
    if (!is_member(set, x)) {
        return; // x não está no conjunto
    }
    int index = 0;
    while (index < set->size && set->elements[index] != x) {
        index++;
    }
    set->size--;
    for (int i = index; i < set->size; i++) {
        set->elements[i] = set->elements[i + 1];
    }
    set->elements = (int*) realloc(set->elements, set->size * sizeof(int));
    if (set->size == 0) {
        free(set->elements);
        set->elements = NULL;
    }
}

Set* union_set(Set* set1, Set* set2) {
    Set* new_set = create_set();
    for (int i = 0; i < set1->size; i++) {
        insert(new_set, set1->elements[i]);
    }
    for (int i = 0; i < set2->size; i++) {
        insert(new_set, set2->elements[i]);
    }
    return new_set;
}

Set* intersection(Set* set1, Set* set2) {
    Set* new_set = create_set();
    for (int i = 0; i < set1->size; i++) {
        if (is_member(set2, set1->elements[i])) {
            insert(new_set, set1->elements[i]);
        }
    }
    return new_set;
}

Set* difference(Set* set1, Set* set2) {
    Set* new_set = create_set();
    for (int i = 0; i < set1->size; i++) {
        if (!is_member(set2, set1->elements[i])) {
            insert(new_set, set1->elements[i]);
        }
    }
    return new_set;
}