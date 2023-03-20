#include <stdio.h>
#include <math.h>

void calculaHexagono (float l, float *area, float *perimetro)
{
    *area = ((3 * (l * l)) * sqrt(3)) / 2;
    *perimetro = l * 6;
}


int main()
{
    float lado, area, perimetro;

    printf("Digite o valor do lado do hexagono regular em metros quadrados: ");
    scanf("%f", &lado);

    calculaHexagono(lado, &area, &perimetro);

    printf("\nA area do hexagono de lado %.3f eh = %.3fm2\n", lado, area);
    printf("O perimetro do hexagono de lado %.3f eh = %.3fm\n", lado, perimetro);


    return 0;
}