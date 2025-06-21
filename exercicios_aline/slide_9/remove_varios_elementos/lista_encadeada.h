typedef struct lista {
    int info;
    struct lista* prox;
} ListaInteiros;

ListaInteiros* lista_cria();
ListaInteiros* lista_insere(ListaInteiros* l, int i);
void lista_exibe(ListaInteiros* l);
void lista_exclui(ListaInteiros* l);
ListaInteiros* lista_remove_todos(ListaInteiros* l, int v);