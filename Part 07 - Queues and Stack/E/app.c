#include "pilhaDin.h"
#include <stdio.h>



int main()
{
    Pilha *p = cria_pilha();

    Aluno a1 = { 145, "Manel", 9.5 };
    Aluno a2 = { 265, "Gibiao", 8.5 };
    Aluno a3 = { 378, "Ze Jaca", 7.5 };
    Aluno a4 = { 265, "Gibiao", 8.5 };
    Aluno a5 = { 984, "Camareiro", 2.5};

    push(p, a1);
    push(p, a2);
    push(p, a3);
    push(p, a4);
    push(p, a5);

    printf("\nPilha original\n");
    mostrar_pilha(p);


    int resultado = pop_item(p, 265);
    if (resultado == 1) {
        printf("\nPilha apos remocao do aluno de matricula '265':\n");
        mostrar_pilha(p);
    } else {
        printf("\nAluno nao encontrado!\n\n");
    }
    
    
    limpar_pilha(p);

    return 0;
}