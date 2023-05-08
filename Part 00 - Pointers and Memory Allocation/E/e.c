#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 100

typedef struct 
{
    char cpf[12];
    char estadoCivil[10];
    char **filhos;
    int numFilhos;

} Cliente;

int main() 
{
    int opcao, numClientes = 0, i, j, pos;
    Cliente *clientes = (Cliente*) malloc(MAX_CLIENTES * sizeof(*clientes));

    do {
        printf("Escolha uma opcao:\n");
        printf("1 - Inserir novo cliente\n");
        printf("2 - Remover cliente\n");
        printf("3 - Mostrar CPFs dos clientes\n");
        printf("0 - Sair\n");

        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                if(numClientes >= MAX_CLIENTES) {
                    printf("O vetor de clientes esta cheio.\n");
                    break;
                }

                printf("Informe o CPF do cliente: ");
                scanf("%s", clientes[numClientes].cpf);

                printf("Informe o estado civil do cliente: ");
                scanf("%s", clientes[numClientes].estadoCivil);

                printf("Informe a quantidade de filhos do cliente: ");
                scanf("%d", &clientes[numClientes].numFilhos);

                if(clientes[numClientes].numFilhos > 0) {
                    clientes[numClientes].filhos = (char**) malloc(clientes[numClientes].numFilhos * sizeof(char*));

                    for(i = 0; i < clientes[numClientes].numFilhos; i++) {
                        clientes[numClientes].filhos[i] = (char*) malloc(50 * sizeof(char));

                        printf("Informe o nome do filho %d: ", i+1);
                        scanf("%s", clientes[numClientes].filhos[i]);
                    }
                }

                numClientes++;

                break;
            case 2:
                printf("Informe a posicao do cliente que deseja remover (entre 1 e %d): ", numClientes);
                scanf("%d", &pos);

                if(pos < 1 || pos > numClientes) {
                    printf("Posicao invalida.\n");
                    break;
                }

                pos--;

                free(clientes[pos].filhos);

                for(i = pos; i < numClientes-1; i++) {
                    strcpy(clientes[i].cpf, clientes[i+1].cpf);
                    strcpy(clientes[i].estadoCivil, clientes[i+1].estadoCivil);

                    clientes[i].numFilhos = clientes[i+1].numFilhos;

                    clientes[i].filhos = (char**) malloc(clientes[i].numFilhos * sizeof(char*));

                    for(j = 0; j < clientes[i].numFilhos; j++) {
                        clientes[i].filhos[j] = (char*) malloc(50 * sizeof(char));
                        strcpy(clientes[i].filhos[j], clientes[i+1].filhos[j]);
                    }

                    free(clientes[i+1].filhos);
                }

                numClientes--;

                break;
            case 3:
                printf("\nCPF dos clientes:\n");

                for(i = 0; i < numClientes; i++) {
                    printf("%s\n", clientes[i].cpf);
                }

                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
        }

        printf("\n");

    } while(opcao != 0);


    for(i = 0; i < numClientes; i++) {
        free(clientes[i].filhos);
    }

    free(clientes);

   
    return 0;

}