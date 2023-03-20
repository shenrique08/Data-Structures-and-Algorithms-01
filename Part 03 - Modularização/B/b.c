#include <stdio.h>

float potenciacao (float X, float Y)
{
    float potencia = 1;

    for (int i = 0; i < Y; i++) {
        potencia *= X;
    }

    if (Y = 0)
        potencia = 1;

    return potencia;
}


int main()
{
    float numerador, expoente;

    printf("Digite o numerador: ");
    scanf("%f", &numerador);

    printf("Digite o expoente: ");
    scanf("%f", &expoente);

    printf("\n%.3f elevado a %.3f eh [%f]\n", numerador, expoente, potenciacao(numerador, expoente));


    return 0;
}