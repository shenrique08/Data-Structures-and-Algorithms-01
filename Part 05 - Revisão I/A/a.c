#include <stdio.h>
#include <stdlib.h>


int maxpot (int X, int Y, int MAX)
{
    int potencia = 1;

    for (int i = 0; i < Y; i++) 
        potencia *= X;
    
    if (Y == 0)
        potencia = 1;

    if (potencia > MAX)
        return 1;
    else 
        return 0;
}



int main()
{
    int numerador, expoente, max_valor;

    printf("Informe o numerador: ");
    scanf("%d", &numerador);

    printf("Informe o expoente: ");
    scanf("%d", &expoente);

    printf("Informe o valor maximo que a potencia pode atingir: ");
    scanf("%d", &max_valor);

    int resultado = maxpot(numerador, expoente, max_valor);

    printf("\nResultado = %d\n\n", resultado);

    return 0;
}