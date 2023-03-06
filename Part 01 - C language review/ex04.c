#include <stdio.h>

int main()
{
    float nota1, nota2, nota3, nota4;
    float media_passa_ano = 6;

    printf("Enter three grades: ");
    scanf("%f %f %f", &nota1, &nota2, &nota3);

    float mean = (nota1 + nota2 + nota3) / 3;

    if (mean >= 0 && mean <= 3)
        printf("You failed!\n");
    else if (mean > 3 && mean < 7) {
        printf("You're in the final exam!\n");
        nota4 = (2 * (media_passa_ano)) - mean;
        printf("You need to get a %f on the final exam!\n\n", nota4);
    }
    else if (mean >= 7 && mean <= 10)
        printf("You passed!\n");

    return 0;
}