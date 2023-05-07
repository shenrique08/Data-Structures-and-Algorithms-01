


typedef struct no *Lista;


Lista *criar_lista();

int lista_vazia(Lista *lista);
int tam_lista(Lista *lista);
void limpar_lista(Lista *lista);

int imprime(Lista *lista);


int insere_inicio(Lista *lista, int valor);
int insere_final(Lista *lista, int valor);
int inserir_pos(Lista *lista, int valor, int pos);
int insere_ordenado(Lista *lista, int valor);



int remove_inicio(Lista *lista);
int remove_final(Lista *lista);
int remove_pos(Lista *lista, int pos);


int qtd_dado_numero(Lista *lista, int numero);
int maior_valor(Lista *lista);

int listas_iguais(Lista *lista1, Lista *lista2);
int recursive_sum(Lista *lista);
void inverse_list(Lista *lista);