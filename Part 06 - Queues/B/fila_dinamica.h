


typedef struct paciente {
    char nome[50];
    char cpf[15];

} Paciente;


typedef struct fila Fila;


Fila *criar_fila();
int fila_vazia(Fila *fila);
int limpar_fila(Fila *fila);

void mostrar(Fila *f);
int cadastrar_paciente(Fila *fila, Paciente paciente, int qtd_cadastro);

int inserir(Fila *fila, Paciente paciente);
int remover(Fila *fila, Paciente *paciente_removido);

Fila *intercala(Fila *fila1, Fila *fila2);