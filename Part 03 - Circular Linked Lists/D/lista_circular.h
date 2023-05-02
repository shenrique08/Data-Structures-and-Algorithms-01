


typedef struct lista_circular Lista_Circular;


typedef struct Aluno
{
    int matricula;
    char nome[50];
    float nota;
} Aluno;



Lista_Circular *cria_lista();
int lista_vazia(Lista_Circular *lista);
int tamanho_lista(Lista_Circular *lista);
int imprime_lista(Lista_Circular *lista);


int inserir_inicio(Lista_Circular *lista, Aluno aluno);
int inserir_fim(Lista_Circular *lista, Aluno aluno);


int remover_inicio(Lista_Circular *lista);
int remover_fim(Lista_Circular *lista);

int buscar_aluno(Lista_Circular *lista, int matricula, Aluno *aluno);


int remove_pos(Lista_Circular *lista, int pos);
int remove_meio(Lista_Circular *lista);
int remove_aluno(Lista_Circular *lista, int matricula);


Lista_Circular *intersection(Lista_Circular *lista1, Lista_Circular *lista2);