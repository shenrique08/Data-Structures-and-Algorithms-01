#include <stdio.h>
#include <stdlib.h>



int perfect_number (int number)
{
    int sum = 0;

    for (int i = 1; i < number; i++)
        if (number % i == 0)
            sum += i;
    
    if (sum == number)
        return 0;
    else 
        return 1;
}



int main()
{
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    int result = perfect_number(number);

    if (result == 1)
        printf("\n[%d] is not a perfect number.\n\n", number);
    else if (result == 0)
        printf("\n[%d] is a perfect number.\n\n", number);

    return 0;
}