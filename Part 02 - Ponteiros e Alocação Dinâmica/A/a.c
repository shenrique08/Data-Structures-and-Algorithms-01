#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[] = "Carla Faria";

    for (int i = 0; nome[i] != '\0'; i++) 
        printf("%c", *(nome + i));
    
    double vetor[10];
    printf("\n");

    for (int i = 0; i < 10; i++)
        printf("[%.3lf]\n", *(vetor + i));

    return 0;
}