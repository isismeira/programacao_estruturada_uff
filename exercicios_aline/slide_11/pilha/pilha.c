#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct elementos {
    char info;
    struct elemento* prox;
}Elemento;

typedef struct pilha {
    Elemento* topo;
}Pilha;

Pilha* pilha_start(){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p -> topo = NULL;
    return p;
}

int pilha_empty(Pilha*p) {
    if (p->topo == NULL) {
        return 1;
    }
    return 0;
}

Pilha* pilha_push(Pilha* p, char info) {
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    novo->info = info;
    novo->prox = p->topo;
    p->topo = novo;
    return p;
}

Pilha* pilha_pop(Pilha* p, char info) {
    if (pilha_empty(p)) {
        return -1;
    }
    Elemento* popped = p->topo;
    p->topo = popped->prox;
    free(popped);
}

Pilha* pilha_exibe(Pilha* p) {
    Elemento* atual = p->topo;
    while (p->topo != NULL) {
        printf(" %c", atual->info);
        atual = atual->prox;
    }
}

Pilha* pilha_free(Pilha* p) {
    Elemento* atual = p->topo;
    while (p->topo != NULL) {
        Elemento* aux = atual->prox;
        free(atual);
        atual = aux;
    }
    free(p);
}