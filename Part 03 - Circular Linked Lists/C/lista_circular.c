#include "lista_circular.h"
#include <stdio.h>
#include <stdlib.h>



typedef struct no
{
    Aluno dados_aluno;
    struct no *prox;

} No;



typedef struct lista_circular
{
    No *inicio;

} Lista_Circular;



/*============================================================================================*/
/*============================================================================================*/
/*============================================================================================*/



Lista_Circular *cria_lista()
{
    Lista_Circular *lista = (Lista_Circular *) malloc(sizeof(Lista_Circular));
    lista->inicio = NULL;

    return lista;
}





int lista_vazia(Lista_Circular *lista)
{
    if (lista->inicio == NULL) // se a lista for vazia
        return 1;
    return 0;
}





int tamanho_lista(Lista_Circular *lista)
{
    if (lista == NULL) 
        return -1;
    
    if (lista_vazia(lista) == 1) 
        return 0;

    No *noLista = lista->inicio;

    int contador = 0;

    do {
        contador += 1;
        noLista = noLista->prox;
    } while (noLista != lista->inicio);

    return contador;
}





int imprime_lista(Lista_Circular *lista)
{
    if (lista == NULL) {
        fprintf(stderr, "\nERRO!!! A lista nao existe.\n");
        return -1;
    }
        
    if (lista_vazia(lista) == 1) {
        fprintf(stderr, "\nA lista esta vazia!!!\n");
        return -2;
    }
        
    
    No *no_lista = lista->inicio;

    do {
        printf("\n\nMatricula: [%d]\n", no_lista->dados_aluno.matricula);
        printf("Nome: [%s]\n", no_lista->dados_aluno.nome);
        printf("Nota: [%.3f]\n\n", no_lista->dados_aluno.nota);

        no_lista = no_lista->prox;

    } while (no_lista != lista->inicio); // enquanto o final da lista não apontar para o início da lista

    printf("\n");

    return 0;
}





// Função para inserir um elemento no início de uma lista circular encadeada
// Recebe como parâmetros um ponteiro para a lista circular e uma estrutura Aluno
// Retorna 0 se a operação for bem-sucedida, ou -1 caso contrário
int inserir_inicio(Lista_Circular *lista, Aluno aluno)
{
    // Verifica se a lista passada como parâmetro é nula
    if (lista == NULL) 
        return -1;

    // Aloca dinamicamente um novo nó e armazena o aluno passado como parâmetro na estrutura de dados do nó
    No *novo = (No *) malloc(sizeof(No));
    novo->dados_aluno = aluno;

    // Se a lista estiver vazia, o ponteiro inicio da lista recebe o endereço do novo nó e o ponteiro prox do novo nó aponta para ele mesmo
    // já que se trata de uma lista circular
    if (lista_vazia(lista) == 1) {
        lista->inicio = novo;
        novo->prox = novo; 
    }

    // Se a lista não estiver vazia, o ponteiro prox do novo nó é configurado para apontar para o início da lista
    // É feita uma busca pelo último elemento da lista, que é aquele cujo ponteiro prox aponta para o início
    // O novo nó é inserido depois desse último nó encontrado
    else {
        novo->prox = lista->inicio;
        No *ultimo = lista->inicio; 
        while (ultimo->prox != lista->inicio) 
            ultimo = ultimo->prox;
        ultimo->prox = novo;
    }
    
    // O ponteiro inicio da lista é atualizado para apontar para o novo nó inserido, concluindo a operação
    lista->inicio = novo; 

    // Retorna 0 para indicar que a operação foi bem-sucedida
    return 0;
}





int inserir_fim(Lista_Circular *lista, Aluno aluno)
{
    if (lista == NULL) return 2;

    // criando dinâmicamente um novo nó e armazena os dados do aluno passados como parâmetro na estrutura de dados nó
    No *no = (No *) malloc(sizeof(No));
    no->dados_aluno = aluno;

    // se a lista estiver vazia, então o início da lista recebe o novo nó e o ponteiro do nó recebe ele mesmo, 
    // já que se trata de uma lista circular
    if (lista_vazia(lista) == 1) {
        lista->inicio = no;
        no->prox = no;

    // se a lista não estiver vazia
    } else {
        No *temp = lista->inicio; // inicializo um ponteiro temp que aponta para o início da lista
        while (temp->prox != lista->inicio) // enquanto o ponteiro do prox não apontar para o início da lista (que será seu final)
            temp = temp->prox; // incremento
        temp->prox = no; // coloca a estrutura de dados criada no último nó
        no->prox = lista->inicio; // faz com que o ponteiro dessa estrutura de dados aponte para o início da lista
    }

    return 0;
}





int remover_inicio(Lista_Circular *lista)
{
    if (lista == NULL)
        return 2;
    if (lista_vazia(lista) == 1)
        return 1;
    
    if (lista->inicio->prox == lista->inicio) { // se houver apenas um elemento na lista, remova-o e aponte o início da lista para NULL. Ou seja, agora ela estará vazia
        free(lista->inicio);
        lista->inicio = NULL;
        return 0;
    }

    No *no = lista->inicio;

    // percorre até o final da lista
    while (no->prox != lista->inicio) {
        no = no->prox; // no agora aponta para o último elemento da lista
    }

    No *temp = lista->inicio; // armazena o primeiro elemeto da estrutura de dados em um nó temporário
    no->prox = temp->prox; // o ponteiro do último elemento agora apontará para o segundo elemento, que é temp->prox
    lista->inicio = temp->prox; // o segundo elemento agora será o primeiro

    // libera memória do primeiro elemento, que tinha sido armazenado em temp
    free(temp);

    return 0;
}





int remover_fim(Lista_Circular *lista)
{
    if (lista == NULL)
        return 2;
    if (lista_vazia(lista) == 1)
        return 1;

    if (lista->inicio->prox == lista->inicio) { // se houver apenas um elemento na lista, remova-o e atualize o ponteiro
        free(lista->inicio);
        lista->inicio = NULL;
        return 0;
    }

    No *anterior = NULL; // ponteiro para o nó anterior
    No *atual = lista->inicio; //  ponteiro para o nó atual

    // percorre toda a lista, atualizando os ponteiros anterior e atual
    while(atual->prox != lista->inicio) {
        anterior = atual;
        atual = atual->prox;
    }

    // o penúltimo ponteiro passa a apontar para o início da lista (atual->prox é o último)
    anterior->prox = atual->prox;

    // libera memória do último elemento
    free(atual);

    return 0;
}





int buscar_aluno(Lista_Circular *lista, int matricula, Aluno *aluno)
{
    if (lista == NULL)
        return 2;
    if (lista_vazia(lista) == 1) {
        printf("\nA lista esta vazia!!!\n\n");
        return 1;
    }

    No *no = lista->inicio; 
    // percorre até encontrar o aluno com a matrícula procurada e não chegar ao final da lista
    while ((no->prox != lista->inicio) && (no->dados_aluno.matricula != matricula))
        no = no->prox;

    // verifica se chegou ao final da lista e não encotrou o aluno
    if (no->dados_aluno.matricula != matricula) {
        printf("\nAluno nao encontrado!!!\n\n");
        return 1;
    } else {
        // se encontrou o aluno, imprima na tela os dados deste aluno
        printf("\n\n================ ALUNO ENCONTRADO ==============\n\n");
        printf("Nome: [%s]\n", no->dados_aluno.nome);
        printf("Nota: [%.3f]\n", no->dados_aluno.nota);
        printf("Matricula: [%d]\n\n", no->dados_aluno.matricula);

        return 0;
    }
}




int remove_pos(Lista_Circular *lista, int pos)
{
    if (lista == NULL || lista_vazia(lista) == 1 || pos < 1 || pos > tamanho_lista(lista)) {
        printf("Erro: posição inválida ou lista vazia!\n");
        return -1;
    }

    No *node_atual = lista->inicio;
    No *node_anterior = NULL;
    int contador = 1;

    while (contador < pos) {
        node_anterior = node_atual;
        node_atual = node_atual->prox;
        contador++;
    }

    if (contador == 1) { // se for o primeiro elemento
        remover_inicio(lista);
        return 0;

    } else if (node_atual->prox == lista->inicio){ // se for o último elemento
        remover_fim(lista);
        return 0;
    } else { // se for um elemento do meio
        node_anterior->prox = node_atual->prox;
        free(node_atual);
    }

    return 0;
}





int remove_meio(Lista_Circular *lista)
{
    if (lista == NULL)
        return -2;
    if (lista_vazia(lista) == 1)
        return -1;

    int tam_lista = tamanho_lista(lista);

    if (tam_lista % 2 == 0) {
        int pos_remocao = tam_lista / 2; // se o tamanho da lista for 8, por exemplo, a posição de remoção será 4
        remove_pos(lista, pos_remocao);
    } else {
        int pos_remocao = (tam_lista / 2) + 1; // a posição do meio será o quociente da divisão + 1. Exemplo, se for 5 o tamanho da lista, então o quociente da divisão será 2. Logo, a pos_remoção será 2 + 1 = 3
        remove_pos(lista, pos_remocao);
    }
}




int remove_aluno(Lista_Circular *lista, int matricula)
{
    if (lista == NULL)
        return -2;
    if (lista_vazia(lista) == 1)
        return -1;
    
    No *aux = lista->inicio;
    int posicao = 1;
    while ((aux->prox != lista->inicio) && (aux->dados_aluno.matricula != matricula)) {
        posicao += 1;
        aux = aux->prox;
    }

    remove_pos(lista, posicao);

    return 0;
}