#include <stdio.h>

int main()
{
    int idade1, data_nasc, data_atual;

    printf("Digite seu ano de nascimento: ");
    scanf("%d", &data_nasc);

    printf("Digite o ano atual: ");
    scanf("%d", &data_atual);

    idade1 = data_atual - data_nasc;

    printf("Vc tera %d anos em 2030!\n\n", (2030 - data_atual) + idade1);

    return 0;
}