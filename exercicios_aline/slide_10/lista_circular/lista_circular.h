typedef struct listacircular ListaCircular;

ListaCircular* lista_circular_cria();
void lista_circular_libera(ListaCircular* lista);
ListaCircular* lista_circular_insere_inicio(ListaCircular* lista, int elemento); 
ListaCircular* lista_circular_insere_fim(ListaCircular* lista, int elemento);
ListaCircular* lista_circular_insere_pos(ListaCircular* lista, int elemento, int pos);
void lista_circular_exibe(ListaCircular* lista);
int lista_circular_tamanho(ListaCircular* lista);  
ListaCircular* lista_circular_remove(ListaCircular* lista, int elemento);
ListaCircular* lista_circular_busca(ListaCircular* lista, int elemento);