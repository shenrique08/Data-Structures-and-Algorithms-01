#include "fila_dinamica.h"
#include <stdio.h>



int main()
{
    Fila *fila = criar_fila();
    Paciente pacientes;
    char operando;

    do {
        printf("\n========== CONSUTORIO TODOS CONTRA O EBOLA =========\n\n");
        printf("[1] - Inserir paciente na fila: \n");
        printf("[2] - Atender paciente\n");
        printf("[3] - Mostrar pacientes na fila\n");
        printf("[4] - Sair\n");
        scanf("%c", &operando);
        getchar();
        if (operando == '4')
            break;

        switch (operando) {
            case '1':
                cadastrar_paciente(fila, pacientes, 1);
                break;

            case '2':
                ;
                Paciente paciente_atendido;
                remover(fila, &paciente_atendido);
                printf("\n========== Paciente atendido: ==========\n");
                printf("\nNome: %s", paciente_atendido.nome);
                printf("Senha: %s\n", paciente_atendido.senha);
                break;

            case '3':
                printf("\n========= PACIENTES NA FILA ==========");
                mostrar(fila);
                break;

            case '4':
                printf("\nPrograma encerrado!!!\n\n");
                break;

            default:
                break;
                
        }

    } while (operando != '4');
    

    return 0;
}