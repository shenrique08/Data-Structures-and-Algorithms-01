#include "lista_circular.h"
#include <stdio.h>
#include <string.h>



int main()
{
    Aluno dados_aluno;

    Lista_Circular *lista_circular = cria_lista();

    
    /***************************************************************************************************/


    // inserindo no início
    dados_aluno.matricula = 123435;
    strcpy(dados_aluno.nome, "Mariscleudo");
    dados_aluno.nota = 60.5;

    inserir_inicio(lista_circular, dados_aluno);
    printf("\n---------- Lista apos a [primeira] INSERCAO no INICIO ---------- \n");
    imprime_lista(lista_circular);


    // inserindo no início 2
    dados_aluno.matricula = 524332;
    strcpy(dados_aluno.nome, "Bazooka");
    dados_aluno.nota = 100;

    inserir_inicio(lista_circular, dados_aluno);
    printf("\n---------- Lista apos a [segunda] INSERCAO no INICIO ---------- \n");
    imprime_lista(lista_circular);


    /***************************************************************************************************/

    // inserindo no final 1
    dados_aluno.matricula = 925347;
    strcpy(dados_aluno.nome, "Gibiao");
    dados_aluno.nota = 56.5;

    inserir_fim(lista_circular, dados_aluno);
    printf("\n---------- Lista apos a [primeira] INSERCAO no FINAL ---------- \n");
    imprime_lista(lista_circular);

    // inserindo no final 2
    dados_aluno.matricula = 234894;
    strcpy(dados_aluno.nome, "Carceres");
    dados_aluno.nota = 98.8;

    inserir_fim(lista_circular, dados_aluno);
    printf("\n---------- Lista apos a [segunda] INSERCAO no FINAL ---------- \n");
    imprime_lista(lista_circular);

    // inserindo no final 3
    dados_aluno.matricula = 234894;
    strcpy(dados_aluno.nome, "Carceres");
    dados_aluno.nota = 98.8;

    inserir_fim(lista_circular, dados_aluno);
    printf("\n---------- Lista apos a [terceira] INSERCAO no FINAL ---------- \n");
    imprime_lista(lista_circular);
    printf("[TAMANHO DA LISTA]: [%d] Alunos\n\n", tamanho_lista(lista_circular));

    /*=======================================================================================================*/
    /*
    // removendo do início
    remover_inicio(lista_circular);
    printf("\n********** Lista apos a [REMOCAO do INICIO] ********** \n");
    imprime_lista(lista_circular);

    
    // removendo do final
    remover_fim(lista_circular);
    printf("\n********** Lista apos a [REMOCAO do FINAL] ********** \n");
    imprime_lista(lista_circular);

    // buscando aluno

    buscar_aluno(lista_circular, 925347, &dados_aluno);
    

   
   remove_pos(lista_circular, 2);
   printf("\n********** Lista apos a [REMOCAO na posicao 2] ********** \n");
   imprime_lista(lista_circular);
   


    remove_meio(lista_circular);
    printf("\n********** Lista apos a [REMOCAO NO MEIO] ********** \n");
    imprime_lista(lista_circular);
    */

    remove_aluno(lista_circular, 234894);
    printf("\n********** Lista apos a ocorrencia do primeiro aluno de [matricula 234894] ********** \n");
    imprime_lista(lista_circular);


    return 0;
}