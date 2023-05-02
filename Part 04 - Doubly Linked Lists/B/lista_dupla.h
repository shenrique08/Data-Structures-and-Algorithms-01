

typedef struct aluno
{
    char nome[50];
    int matricula;
    float nota;


} Aluno;

typedef struct lista Lista_dupla;



Lista_dupla *criar_lista();
void remover_alunos(Lista_dupla *lista);
int lista_vazia(Lista_dupla *lista);
int tam_lista(Lista_dupla *lista);

void imprime(Lista_dupla *lista);

int insere_inicio(Lista_dupla *lista, Aluno aluno);
int insere_final(Lista_dupla *lista, Aluno aluno);
int inserir_pos(Lista_dupla *lista, Aluno aluno, int pos);
int insere_ordenado(Lista_dupla *lista, Aluno aluno);

int remove_inicio(Lista_dupla *lista);
int remove_final(Lista_dupla *lista);
int remove_aluno(Lista_dupla *lista, int matricula);
int remove_pos(Lista_dupla *lista, int pos);

int aluno_maior_nota(Lista_dupla *lista);
int troca_aluno(Lista_dupla *lista, int pos1, int pos2);