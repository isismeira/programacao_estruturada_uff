typedef struct lista ListaInteiros;

ListaInteiros* lista_cria();
ListaInteiros* lista_insere(ListaInteiros* l, int i);
void lista_exibe(ListaInteiros* l);
void lista_exclui(ListaInteiros* l);
int lista_vazia(ListaInteiros* l);
ListaInteiros* busca(ListaInteiros* l, int v);
ListaInteiros* lista_remove_elemento(ListaInteiros* l, int v);
ListaInteiros* lista_insere_ordenado(ListaInteiros* l, int v);