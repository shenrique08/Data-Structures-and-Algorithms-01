#include <stdio.h>

int main()
{
    int array[6] = {6, 2, 0, 4, 5};
    int num, pos;

    printf("\nNumbers in the array:\n");
    for (int i = 0; i < 5; i++)
        printf("[%d] ", array[i]);

    printf("\nEnter a integer: ");
    scanf("%d", &num);

    printf("Which position do you want to insert the number? (0-5) ");
    scanf("%d", &pos);

    for (int i = 4; i >= pos; i--) {
        array[i + 1] = array[i];
    }

    array[pos] = num;   


    printf("\nNumbers in the array after the swapp:\n");
    for (int i = 0; i < 6; i++)
        printf("[%d] ", array[i]);

    return 0;
}