typedef struct lista ListaInteiros;

ListaInteiros* lista_cria();

ListaInteiros* lista_insere(ListaInteiros* l, int i);

ListaInteiros* lista_insere_ordenado (ListaInteiros* l, int v);

void lista_imprime(ListaInteiros* l);

int lista_vazia(ListaInteiros* l);

ListaInteiros* lista_busca(ListaInteiros* l, int i);

ListaInteiros* lista_insere_ordenado(ListaInteiros* l, int i);

ListaInteiros* lista_remove_elemento(ListaInteiros* l, int i);

ListaInteiros* lista_insere_fim(ListaInteiros* l, int elemento);

ListaInteiros* lista_insere_fim2(ListaInteiros* l, int elemento);

ListaInteiros* lista_concatena(ListaInteiros* l1, ListaInteiros* l2);

ListaInteiros* lista_metade(ListaInteiros* l);
	
ListaInteiros* lista_separa_por_info(ListaInteiros* l, int info);

ListaInteiros* lista_separa_por_pos(ListaInteiros* l, int pos);

ListaInteiros* lista_insere_do_vetor(ListaInteiros* l, int* v, int tam);

ListaInteiros* lista_insere_do_vetor_no_fim(ListaInteiros* l, int* v, int tam);
	
ListaInteiros* lista_remove_todos_por_elemento(ListaInteiros* l, int v);

int lista_tamanho(ListaInteiros* l);

void lista_exclui(ListaInteiros* l);

ListaInteiros* lista_remove_pares(ListaInteiros* l);