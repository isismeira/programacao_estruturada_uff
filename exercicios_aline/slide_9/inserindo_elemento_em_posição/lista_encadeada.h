typedef struct lista {
    int info;
    struct lista* prox;
} ListaInteiros;

ListaInteiros* lista_cria();
ListaInteiros* lista_insere(ListaInteiros* l, int i);
void lista_exibe(ListaInteiros* l);
void lista_exclui(ListaInteiros* l);
ListaInteiros* lista_insere_posicao(ListaInteiros* l, int valor, int pos);
ListaInteiros* lista_insere_depois_de(ListaInteiros* l, int valor, int x);