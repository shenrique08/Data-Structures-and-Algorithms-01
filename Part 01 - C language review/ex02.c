#include <stdio.h>


int main()
{
    int num1, num2;

    printf("Informe o primeiro numero inteiro: ");
    scanf("%d", &num1);
    printf("Informe o segundo numero inteiro: ");
    scanf("%d", &num2);
    fflush(stdin);
    
    char operando;

    printf("Informe qual operacao deseja realizar: (+, -, *, /): ");
    scanf("%c", &operando);

    switch (operando)
    {
        case '+':
            printf("%d + %d = %d\n", num1, num2, (num1 + num2));
            break;
        case '-':
            printf("%d - %d = %d\n", num1, num2, (num1 - num2));
            break;
        case '*':
            printf("%d * %d = %d\n", num1, num2, (num1 * num2));
            break;
        case '/':
            printf("%d // %d = %.3f\n", num1, num2, (num1 / (float)num2));
            break;
        default:
            printf("Operando invalido!!!\n");
            break;
    }

    return 0;
}