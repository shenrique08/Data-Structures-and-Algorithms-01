#include <stdio.h>

int main()
{
    int a = 10;
    int b, c;

    printf("Endereco de memoria = %p\n", &a);
    printf("Endereco de memoria = %p\n", &b);
    printf("Endereco de memoria = %p", &a);

    
    return 0;
}