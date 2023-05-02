#include "lista_dupla.h"
#include <stdio.h>
#include <string.h>



int main()
{
    Lista_dupla *lista_dupla = criar_lista();
    Lista_dupla *lista_dupla2 = criar_lista();
    Aluno dados_aluno;
    Aluno dados_aluno2;
    char operando;

    do {
        printf("\n\n================ MENU =================\n\n");
        printf("(1) -> Cadastrar aluno ordenadamente\n");
        printf("(2) -> Remover aluno\n");
        printf("(3) -> Listar alunos cadastrados\n");
        printf("(4) -> Mostrar dados do aluno com maior nota\n");
        printf("(5) -> Remover todos os alunos\n");
        printf("(6) -> Trocar alunos de posicao\n");
        printf("(7) -> Verificar se as listas contem os mesmos alunos: \n");
        printf("(8) -> Retirar todas as repeticoes: \n");
        printf("(9) -> Sair\n\n");

        printf("Digite uma opcao: ");
        scanf("%c", &operando);
        getchar();

        if (operando == '9') {
            printf("\nPrograma encerrado!\n\n");
            break;
        }
        switch (operando)
        {
            case '1':
                // ================================================= INSERCAO NA LISTA 1 ==================================================
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

                strcpy(dados_aluno.nome, "Lazaro");
                dados_aluno.matricula = 53456;
                dados_aluno.nota = 87.1;

                insere_final(lista_dupla, dados_aluno);

                printf("\n================== [LISTA 1] DE ALUNOS CADASTRADOS ====================\n\n");
                imprime(lista_dupla);

                
                // ================================================= INSERCAO NA LISTA 2 ==================================================

                strcpy(dados_aluno2.nome, "Bazooka");
                dados_aluno2.matricula = 32345;
                dados_aluno2.nota = 67.3;

                insere_inicio(lista_dupla2, dados_aluno2);   

                strcpy(dados_aluno2.nome, "Lazaro");
                dados_aluno2.matricula = 53456;
                dados_aluno2.nota = 87.1;

                insere_final(lista_dupla2, dados_aluno2);
                
                strcpy(dados_aluno2.nome, "Geova");
                dados_aluno2.matricula = 64567;
                dados_aluno2.nota = 39.8;

                insere_final(lista_dupla2, dados_aluno2);

                strcpy(dados_aluno2.nome, "Geova");
                dados_aluno2.matricula = 64567;
                dados_aluno2.nota = 39.8;

                insere_final(lista_dupla2, dados_aluno2);

                printf("\n\n======================== [LISTA 2] DE ALUNOS ===============================\n\n");
                imprime(lista_dupla2);

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
            case '5':
                remover_alunos(lista_dupla);
                break;
            case '6':;
                int pos_aluno1, pos_aluno2;
                printf("Digite as duas posicoes que deseja realizar a troca: ");
                scanf("%d %d", &pos_aluno1, &pos_aluno2);
                fflush(stdin);
                
                troca_aluno(lista_dupla, pos_aluno1, pos_aluno2);
                printf("\n========== LISTA APOS TROCA DE ALUNOS ==========\n\n");
                imprime(lista_dupla);
                break;

            case '7':
                listas_iguais(lista_dupla, lista_dupla2);
                break;
            case '8':;
                int lista_retirar;
                printf("\nDe qual lista deseja retirar as repeticoes?\n(1) -> lista [1]\n(2) -> lista [2]\n ");
                scanf("%d", &lista_retirar);
                fflush(stdin);

                if (lista_retirar == 1) {
                    retira_repeticoes(lista_dupla);
                    printf("\n=============== Lista apos remocao das repeticoes ================\n\n");
                    imprime(lista_dupla);
                }
                else if (lista_retirar == 2) {
                    retira_repeticoes(lista_dupla2);
                    printf("\n=============== Lista apos remocao das repeticoes ================\n\n");
                    imprime(lista_dupla2);
                }
                break;
                
            default:
                printf("\nErro!!! Digite uma opcao valida.\n\n");
                break;
        }

    } while (operando != '9');


    return 0;
}