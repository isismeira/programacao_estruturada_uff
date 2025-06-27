typedef struct elemento Elemento;
typedef struct pilha Pilha;

Pilha* pilha_start();
int pilha_empty(Pilha*p);
Pilha* pilha_push(Pilha* p, char info);
Pilha* pilha_pop(Pilha* p, char info);
Pilha* pilha_exibe(Pilha* p);
Pilha* pilha_free(Pilha* p);