#include "lista_dupla.h"
#include <stdio.h>
#include <string.h>



int main()
{
    Lista_dupla *lista_dupla = criar_lista();
    Aluno dados_aluno;
    char operando;

    do {
        printf("\n\n================ MENU =================\n\n");
        printf("(1) -> Cadastrar aluno ordenadamente\n");
        printf("(2) -> Remover aluno\n");
        printf("(3) -> Listar alunos cadastrados\n");
        printf("(4) -> Mostrar dados do aluno com maior nota\n");
        printf("(5) -> Remover todos os alunos\n");
        printf("(6) -> Sair\n\n");

        printf("Digite uma opcao: ");
        scanf("%c", &operando);
        getchar();

        if (operando == '6') {
            printf("\nPrograma encerrado!\n\n");
            break;
        }
        switch (operando)
        {
            case '1':
                
                strcpy(dados_aluno.nome, "Bazooka");
                dados_aluno.matricula = 32345;
                dados_aluno.nota = 67.3;

                insere_inicio(lista_dupla, dados_aluno);   

                strcpy(dados_aluno.nome, "Lazaro");
                dados_aluno.matricula = 53456;
                dados_aluno.nota = 87.1;

                insere_final(lista_dupla, dados_aluno);
                
                strcpy(dados_aluno.nome, "Geova");
                dados_aluno.matricula = 64567;
                dados_aluno.nota = 39.8;

                insere_final(lista_dupla, dados_aluno);
                printf("\n================== LISTA DE ALUNOS CADASTRADOS PREVIAMENTE ====================\n\n");
                imprime(lista_dupla);

                
                strcpy(dados_aluno.nome, "Capatais");
                dados_aluno.matricula = 46543;
                dados_aluno.nota = 17.8;

                insere_ordenado(lista_dupla, dados_aluno);
                printf("\n=============== LISTA DE ALUNOS APOS CADASTRO DE CATATAIS DE FORMA ORDENADA ===============================\n");
                imprime(lista_dupla);
                
                break;

            case '2':;
                int mat_remocao;
                printf("\nInforme a matricula do aluno que deseja remover: ");
                scanf("%d", &mat_remocao);

                remove_aluno(lista_dupla, mat_remocao);
                printf("\n========== LISTA APOS A REMOCAO =========\n\n");
                imprime(lista_dupla);
                break;

            case '3':
                printf("\n========== ALUNOS ATUALMENTE CADASTRADOS =========\n\n");
                imprime(lista_dupla);
                break;
                
            case '4':
                printf("\n========== ALUNO CADASTRADO COM MAIOR NOTA =========\n\n");
                aluno_maior_nota(lista_dupla);
                break;

            default:
                printf("\nErro!!! Digite uma opcao valida.\n\n");
                break;

        }



    } while (operando != '6');




    return 0;
}