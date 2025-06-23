typedef struct lista ListaInteiros;

ListaInteiros* lista_cria();
ListaInteiros* lista_insere(ListaInteiros* l, int i);
void lista_exibe(ListaInteiros* l);
void lista_exclui(ListaInteiros* l);
int lista_len(ListaInteiros* l);
ListaInteiros* lista_meio(ListaInteiros* l, int len);
ListaInteiros* lista_separa_elemento(ListaInteiros* l, int i);
ListaInteiros* lista_separa_posicao(ListaInteiros* l, int indice) ;