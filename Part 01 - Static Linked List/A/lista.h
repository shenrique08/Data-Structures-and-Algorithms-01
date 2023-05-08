#define MAX 100



typedef struct aluno {
    int matricula;
    char nome[35];
    float nota;
} Aluno;

typedef struct lista Lista;



Lista *criar_lista();

void limpar_lista(Lista *lista);
int lista_vazia(Lista *lista);
int lista_cheia(Lista *lista);
int imprime(Lista *lista);



int inserirInicio(Lista *lista, Aluno aluno);
int inserirFim(Lista *lista, Aluno aluno);
int inserirPosicao(Lista *lista, Aluno aluno, int pos);



int removerInicio(Lista *lista);
int removerFim(Lista *lista);
int removerPosicao(Lista *lista, int pos);
int removerAluno(Lista *lista, int matricula);



int buscar_aluno_mat(Lista *lista, int matri);