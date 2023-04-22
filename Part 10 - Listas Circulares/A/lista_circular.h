


typedef struct lista Lista_Circular;


typedef struct Aluno
{
    int matricula;
    char nome[50];
    float nota;
} Aluno;



Lista_Circular *cria_lista();
int lista_vazia(Lista_Circular *lista);

int imprime_lista(Lista_Circular *lista);
int limpar_lista(Lista_Circular *lista);

