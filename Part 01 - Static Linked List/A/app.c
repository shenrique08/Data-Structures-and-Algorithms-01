#include "lista.h"
#include <stdio.h>
#include <string.h>


int main()
{
    Lista *lista = criar_lista();
    Aluno dados_aluno[5];

    dados_aluno[0].matricula = 12345;
    strcpy(dados_aluno[0].nome, "Marivaldo");
    dados_aluno[0].nota = 60.5;
    inserirInicio(lista, dados_aluno[0]);


    dados_aluno[1].matricula = 95642;
    strcpy(dados_aluno[1].nome, "Capateu");
    dados_aluno[1].nota = 48.8;
    inserirFim (lista, dados_aluno[1]);
    

    dados_aluno[2].matricula = 65478;
    strcpy(dados_aluno[2].nome, "Geraldino");
    dados_aluno[2].nota = 97.2;
    inserirInicio(lista, dados_aluno[2]);

    dados_aluno[3].matricula = 78954;
    strcpy(dados_aluno[3].nome, "Bazooka");
    dados_aluno[3].nota = 26.0;
    inserirPosicao(lista, dados_aluno[3], 2);
    printf("\n========= LISTA apos insercoes =========\n\n");
    imprime(lista);

    

    removerPosicao(lista, 3);
    printf("\n========== Apos remocao do elemento de posicao 3 ==========\n\n");
    imprime(lista);

    removerAluno(lista, 78954);
    printf("\n========== Apos remocao do aluno de matricula '78954' ==========\n\n");
    imprime(lista);

    buscar_aluno_mat(lista, 95642);

    return 0;
}