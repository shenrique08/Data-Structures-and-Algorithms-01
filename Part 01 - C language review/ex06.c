#include <stdio.h>

int main()
{
    float base, altura;

    do {
        printf("Digite o comprimento da base em metros: ");
        scanf("%f", &base);

        if (base <= 0)
            printf("Digite um valor maior ou igual a zero!\n");

    } while (base <= 0);
        

    do {
        printf("Digite o comprimento da altura em metros: ");
        scanf("%f", &altura);

        if (altura <= 0)
            printf("Digite um valor maior ou igual a zero!\n");

    } while (altura <= 0);

    float area = (base * altura) / 2;

    printf("\nArea do triangulo = %.3fm2\n\n", area);

    return 0;
}