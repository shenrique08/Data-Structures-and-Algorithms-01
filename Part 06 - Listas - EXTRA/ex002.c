#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *del_value_array (int *array, int size_array, int pos_delete)
{
    for (int i = pos_delete; i < size_array; i++)
        array[i] = array[i + 1];

    return array;
}


int main()
{
    int *array_main, size_array_main, pos_value_delete;
    srand(time(NULL));

    printf("Enter the size of the array: ");
    scanf("%d", &size_array_main);

    array_main = (int *) calloc(size_array_main, sizeof(int));
    if (array_main == NULL) {
        printf("Error alocating memory\n");
        exit(1);
    }


    printf("\nValues in the array before the deletion:\n");
    for (int i = 0; i < size_array_main; i++) {
        array_main[i] = rand() % 10;
        printf("[%d] ", array_main[i]);
    }

    printf("\nWhich position do you want to delete? ");
    scanf("%d", &pos_value_delete);

    array_main = del_value_array(array_main, size_array_main, pos_value_delete);
    array_main = (int *) realloc(array_main, (size_array_main - 1) * sizeof(int));

    printf("\n\nValues in the array after the deletion:\n");
    for (int i = 0; i < size_array_main - 1; i++) 
        printf("[%d] ", array_main[i]);
    
    free(array_main);
    
    return 0;
}