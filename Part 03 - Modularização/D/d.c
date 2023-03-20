/*#include <stdio.h>

int divisao (int a, int b, int *quociente, int *resto)
{
    if (b == 0)
        return -1;
    else {
        *quociente = a / b;
        *resto = a % b;
        return 0;

    }
}

int main()
{
    int divisor, dividendo, quociente, resto;

    printf("Informe o numerador da divisao: ");
    scanf("%d", &divisor);

    printf("Informe o denominador da divisao: ");
    scanf("%d", &dividendo);

    int resultado = divisao(divisor, dividendo, &quociente, &resto);

    if (resultado == -1)
        printf("\nDivisao impossivel!\n");
    else {
        printf("\nQuociente: %d\n", quociente);
        printf("Resto: %d\n", resto);
    }

    return 0;
} */

#include <stdio.h>
int main() {
   int *p;
   char *c;
   double *d;
   float *f;

   printf("O tamanho do ponteiro e %lu bytes\n", sizeof(p));
   printf("O tamanho do ponteiro e %lu bytes\n", sizeof(c));
   printf("O tamanho do ponteiro e %lu bytes\n", sizeof(d));
   printf("O tamanho do ponteiro e %lu bytes\n", sizeof(f));
   return 0;
}