#include "fila_dinamica.h"
#include <stdio.h>



int main()
{
    Fila *fila1 = criar_fila();
    Fila *fila2 = criar_fila();
    Paciente pacientes1;
    Paciente pacientes2;

    cadastrar_paciente(fila1, pacientes1, 2);
    printf("\n=========== Pacientes cadastrados na [FILA 01] ==========\n");
    mostrar(fila1);

    cadastrar_paciente(fila2, pacientes2, 2);
    printf("\n=========== Pacientes cadastrados na [FILA 02] ==========\n");
    mostrar(fila2);

    Fila *fila3 = intercala(fila1, fila2);
    printf("\n=========== FILA 01 E FILA 02 INTERCALADAS ==========\n");
    mostrar(fila3);

    return 0;
}