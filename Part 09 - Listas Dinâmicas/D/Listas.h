

typedef struct aluno {
    int matricula;
    char nome[30];
    float nota;
} Aluno;



typedef struct lista Lista;


Lista *criar_lista();
void limpar_lista(Lista *lista);

int lista_vazia(Lista *lista);

int inserir_no_inicio(Lista *lista, Aluno aluno);
int inserir_no_fim(Lista *lista, Aluno aluno);
int inserir_pos(Lista *lista, Aluno aluno, int pos);

void imprime(const Lista *lista);
int tam_lista(Lista *lista);

int remover_inicio(Lista *lista);
int remover_fim(Lista *lista);
int remover_pos(Lista *lista, int pos);
int remover_aluno(Lista *lista, Aluno aluno);

//int buscar_pos(Lista *lista, struct aluno *retorno, int pos);

//int Contem_Aluno(Lista *lista, Aluno aluno);
Lista *concatena(Lista *lista1, Lista *lista2);

int aluno_maior_nota(Lista *lista);

int remove_da_lista(Lista *lista, int quantidade);