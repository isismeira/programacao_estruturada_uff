typedef struct lista ListaInteiros;

ListaInteiros* lista_cria();
ListaInteiros* lista_insere(ListaInteiros* l, int i);
void lista_exibe(ListaInteiros* l);
void lista_exclui(ListaInteiros* l);
ListaInteiros* lista_concatenar(ListaInteiros* l1, ListaInteiros* l2);