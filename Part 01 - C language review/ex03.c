#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int sum = 0;

    printf("\nargc = %d\n\n", argc);
    printf("Let's see what is in argv[]\n");
    
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
        sum += atoi(argv[i]);
        }
        printf("Total = %d\n", sum);
    }

    return 0;
}