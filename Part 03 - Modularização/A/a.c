#include <stdio.h>
#include <stdlib.h>

int retorna_soma (int *N)
{
    int soma = 0;

    for (int i = 1; i <= *N; i++) {
        soma += i;
    }

    return soma;
}

int main()
{
    int valor;

    printf("Digite um valor inteiro: ");
    scanf("%d", &valor);

    printf("A soma entre 1 e %d eh %d\n", valor, retorna_soma(&valor));

    return 0;
}