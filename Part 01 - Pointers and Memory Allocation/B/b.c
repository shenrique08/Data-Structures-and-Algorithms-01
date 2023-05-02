#include <stdio.h>
#include <stdlib.h>


int main()
{
    int *vetor;

    vetor = (int *)calloc(5, sizeof(int));

    for (int i = 0; i < 5; i++) {
        printf("Digite o [%do] numero: ", i + 1);
        scanf("%d", (vetor + i));
    }

    printf("\nValores digitados:\n");
    for (int i = 0; i < 5; i++)
        printf("[%d] ", *(vetor + i));

    free(vetor);

    return 0;
}