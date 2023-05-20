#include "fila_dinamica.h"
#include <stdio.h>
#include <stdlib.h>



typedef struct no {
    Paciente dados;
    struct no *prox;

} No;



typedef struct fila {
    No *inicio;
    No *fim;
    int tam_fila;

} Fila;



/*=============================================================================================================*/

Fila *criar_fila()
{
    Fila *fila = (Fila *) calloc(1, sizeof(Fila));

    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tam_fila = 0;

    return fila;
}





int fila_vazia(Fila *fila)
{
    if (fila == NULL)
        return -1;
    if (fila->tam_fila == 0)
        return 1;
    return 0;
}





int limpar_fila(Fila *fila)
{
    if (fila == NULL)
        return -1;
    while (fila_vazia(fila) != 1)
        remover(fila, NULL);

    free(fila);
    fila = NULL;

    return 0;
}





int inserir(Fila *fila, Paciente paciente)
{
    if (fila == NULL)
        return -1;
    
    No *novo_no = (No*) calloc(1, sizeof(No));
    novo_no->dados = paciente;
    novo_no->prox = NULL; // o prox do novo nó sempre será NULL, uma vez que a inserção em uma fila sempre será em seu final


    // se a fila estiver vazia, então aponte o início da fila para o novo_no
    if (fila_vazia(fila) == 1)  
        fila->inicio = novo_no;
    // caso contrário, aponte o que, anteriormente era o último nó, para o novo_no
    else 
        fila->fim->prox = novo_no;
    
    // em ambos os casos, o novo_no será o fim da fila
    fila->fim = novo_no;
    fila->tam_fila += 1;

    return 0;
}





int cadastrar_paciente(Fila *fila, Paciente paciente, int qtd_cadastro)
{
    if (fila == NULL)
        return -1;

    No *novo_no = (No*) calloc(1, sizeof(No));
    novo_no->dados = paciente;
    printf("\n=============== SISTEMA DE CADASTRO ===============\n");
    if (qtd_cadastro > 1) {
        for (int i = 0; i < qtd_cadastro; i++) {
            printf("\nInforme o NOME do [%do] paciente: ", i + 1);
            fgets(novo_no->dados.nome, sizeof(novo_no->dados.nome), stdin);

            printf("Informe o CPF do    [%do] paciente: ", i + 1);
            fgets(novo_no->dados.cpf, sizeof(novo_no->dados.cpf), stdin);

            inserir(fila, novo_no->dados);
        }
    }

    return 0;
}





int remover(Fila *fila, Paciente *paciente_removido)
{
    if (fila == NULL)
        return -1;
    if (fila_vazia(fila) == 1)
        return -2;
    
    No *no_aux = fila->inicio;
    *paciente_removido = no_aux->dados;
    // o início agora apontará para, anteriormente, segundo elemento
    fila->inicio = no_aux->prox;
    free(no_aux);

    // caso, após a remoção, a lista fique vazia, temos que atualizar o ponteiro fim
    if (fila->inicio == NULL)
        fila->fim = NULL;

    fila->tam_fila -= 1;

    return 0;
}





void mostrar(Fila *f) 
{
    if (f != NULL) {
        No *no = f->inicio;
        while (no != NULL) {
            printf("\nNOME: %s ",no->dados.nome);
            printf("CPF: %s \n",no->dados.cpf);
            
            no = no->prox;
        }
        printf("\n");
    }
}




Fila *intercala(Fila *fila1, Fila *fila2)
{
    int retorno = 0;
    if (fila1 == NULL || fila2 == NULL)
        return -1;
    if (fila_vazia(fila1) == 1 && fila_vazia(fila2) == 1)
        return -2;
    
    Fila *fila3 = criar_fila();

    No *nolista1 = fila1->inicio;
    No *nolista2 = fila2->inicio;
    // inserindo os elementos da primeira fila na terceira fila, mantendo sua ordem
    while (nolista1 != NULL) {
        inserir(fila3, nolista1->dados);
        nolista1 = nolista1->prox;
    }

    // agora, insere os elementos da segunda lista a partir do final da primeira lista
    while(nolista2 != NULL) {
        inserir(fila3, nolista2->dados);
        nolista2 = nolista2->prox;
    }

    return fila3;
}