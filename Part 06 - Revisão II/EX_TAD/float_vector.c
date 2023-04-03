#include "float_vector.h"

#include <stdlib.h>

struct float_vector 
{
    int capacity; // número máximo de elementos do vetor
    int size; // quantidade de elementos armazenados atualmente
    float *data; // vetor de floats
};


/*
* @brief Cria (aloca) um vetor de floats com uma dada capacidade
*@param capacity capacidade do vetro.
* @return FloatVector* Um vetor de floats alocado/criado.
*/
FloatVector *create(int capacity)
{
    FloatVector *vec = (FloatVector*) calloc(1, sizeof(FloatVector*));
    vec->size = 0;
    vec->capacity = capacity;
    vec->data = (float *) calloc(capacity, sizeof(float));

    return vec;

}

void destroy (FloatVector **vec)
{
    
}