#include <stdio.h>
#include <stdlib.h>


void data (int dia, int mes, int ano)
{
    printf("\n[%d/%d/%d]\n\n", dia, mes, ano);
}




int main()
{
    int dia, mes, ano;

    printf("Informe o dia: (dd) ");
    scanf("%d", &dia);

    printf("Informe o mes: (mm) ");
    scanf("%d", &mes);

    printf("Informe o ano: (aaaa) ");
    scanf("%d", &ano);

    data(dia, mes, ano);

    return 0;
}