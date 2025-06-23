typedef struct listadupla ListaDupla;

ListaDupla* lista_dupla_insere_inicio(ListaDupla* lista, int elemento);

ListaDupla* lista_dupla_insere_fim(ListaDupla* lista, int elemento);

void lista_dupla_exibe(ListaDupla* lista);

void lista_dupla_exibe_ao_contrario(ListaDupla* lista);

int lista_dupla_tamanho(ListaDupla* lista);

ListaDupla* lista_insere_em_pos(ListaDupla* lista, int elemento, int pos);

ListaDupla* lista_dupla_cria();

void lista_dupla_libera(ListaDupla* lista);
