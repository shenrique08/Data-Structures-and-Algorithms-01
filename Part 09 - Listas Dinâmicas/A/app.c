#include "Listas.h"
#include <string.h>
#include <stdio.h>

int main()
{
    Aluno dados_aluno;

    Lista *lista = criar_lista();


    // inserindo no início
    dados_aluno.matricula = 123435;
    strcpy(dados_aluno.nome, "Mariscleudo");
    dados_aluno.nota = 60.5;

    inserir_no_inicio(lista, dados_aluno);
    printf("\n---------- Lista apos a [primeira] INSERCAO no INICIO ---------- \n");
    imprime(lista);


    // inserindo no início 2
    dados_aluno.matricula = 524332;
    strcpy(dados_aluno.nome, "Bazooka");
    dados_aluno.nota = 100;

    inserir_no_inicio(lista, dados_aluno);
    printf("\n---------- Lista apos a [segunda] INSERCAO no INICIO ---------- \n");
    imprime(lista);


    // inserindo no final
    dados_aluno.matricula = 925347;
    strcpy(dados_aluno.nome, "Gibiao");
    dados_aluno.nota = 56.5;

    inserir_no_fim(lista, dados_aluno);
    printf("\n---------- Lista apos a [primeira] INSERCAO no FINAL ---------- \n");
    imprime(lista);

    // inserindo no final 2
    dados_aluno.matricula = 234894;
    strcpy(dados_aluno.nome, "Carceres");
    dados_aluno.nota = 98.8;

    inserir_no_fim(lista, dados_aluno);
    printf("\n---------- Lista apos a [segunda] INSERCAO no FINAL ---------- \n");
    imprime(lista);


    // inserindo em determinada posição
    dados_aluno.matricula = 654223;
    strcpy(dados_aluno.nome, "Jacamilton");
    dados_aluno.nota = 72.5;

    inserir_pos(lista, dados_aluno, 1);
    printf("\n---------- Lista apos a INSERCAO na posicao 1 ---------- \n");
    imprime(lista);


    // removendo do início
    remover_inicio(lista);
    printf("\n********** Lista apos a REMOCAO do INICIO ********** \n");
    imprime(lista);
    

    // removendo do final
    remover_fim(lista);
    printf("\n********** Lista apos a REMOCAO do FINAL ********** \n");
    imprime(lista);

    // removendo de uma determinada posição
    remover_pos(lista, 1);
    printf("\n********** Lista apos a REMOCAO da posicao 1 ********** \n");
    imprime(lista);


    // removendo um aluno passado como parâmetro
    remover_aluno(lista, dados_aluno);
    printf("\n********** Lista apos a REMOCAO de um qualquer aluno ********** \n");
    imprime(lista);


    // inserindo no início
    dados_aluno.matricula = 774393;
    strcpy(dados_aluno.nome, "Josevanderson");
    dados_aluno.nota = 59.9;

    inserir_no_inicio(lista, dados_aluno);
    printf("\n====================== Lista apos outra INSERCAO no INICIO ===================== \n");
    imprime(lista);

    // inserindo no início
    dados_aluno.matricula = 544333;
    strcpy(dados_aluno.nome, "Jesus");
    dados_aluno.nota = 80.5;

    inserir_no_inicio(lista, dados_aluno);
    printf("\n===================== Lista apos outra INSERCAO no INICIO =================== \n");
    imprime(lista);

    // busca por posição
    buscar_pos(lista, &dados_aluno, 2);



    return 0;
}