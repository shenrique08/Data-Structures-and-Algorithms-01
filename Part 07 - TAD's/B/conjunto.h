#ifndef SET_H
#define SET_H

typedef struct set Set;

Set* create_set();
void destroy_set(Set* set);
int is_member(Set* set, int x);
void insert(Set* set, int x);
void remove_member(Set* set, int x);
Set* union_set(Set* set1, Set* set2);
Set* intersection(Set* set1, Set* set2);
Set* difference(Set* set1, Set* set2);

#endif /* SET_H */

struct set 
{
    int* elements;
    int size;
};