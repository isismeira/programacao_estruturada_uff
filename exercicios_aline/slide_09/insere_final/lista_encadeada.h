typedef struct lista {
    int info;
    struct lista* prox;
} ListaInteiros;

typedef struct controlador { // !!!
    ListaInteiros* inicio;
    ListaInteiros* fim;
} ListaControlador;

ListaInteiros* lista_cria();
ListaInteiros* lista_insere(ListaInteiros* l, int i);
void lista_exibe(ListaInteiros* l);
void lista_exclui(ListaInteiros* l);
ListaInteiros* lista_insere_final_simples(ListaInteiros* l, int valor);
ListaControlador* lista_cria_controlador();
void lista_insere_final(ListaControlador* controlador, int valor);