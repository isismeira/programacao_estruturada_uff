// lista_circular.c
#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

typedef struct listacircular {
    int info;
    struct listacircular* prox;
} ListaCircular;

ListaCircular* lista_circular_cria() {
    return NULL;
}

void lista_circular_libera(ListaCircular* lista) {
    if (!lista) return;
    ListaCircular* atual = lista->prox;
    while (atual != lista) {
        ListaCircular* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(lista);
}

ListaCircular* lista_circular_insere_inicio(ListaCircular* lista, int elemento) {
    ListaCircular* novo = (ListaCircular*) malloc(sizeof(ListaCircular));
    novo->info = elemento;

    if (!lista) {
        novo->prox = novo;
        return novo;
    }

    ListaCircular* ultimo = lista;
    while (ultimo->prox != lista)
        ultimo = ultimo->prox;

    novo->prox = lista;
    ultimo->prox = novo;
    return novo;
}

ListaCircular* lista_circular_insere_fim(ListaCircular* lista, int elemento) {
    ListaCircular* novo = (ListaCircular*) malloc(sizeof(ListaCircular));
    novo->info = elemento;

    if (!lista) {
        novo->prox = novo;
        return novo;
    }

    ListaCircular* ultimo = lista;
    while (ultimo->prox != lista)
        ultimo = ultimo->prox;

    novo->prox = lista;
    ultimo->prox = novo;
    return lista;
}

ListaCircular* lista_circular_insere_pos(ListaCircular* lista, int elemento, int pos) {
    int tamanho = lista_circular_tamanho(lista);
    if (pos < 1 || pos > tamanho + 1)
        return lista;

    if (pos == 1)
        return lista_circular_insere_inicio(lista, elemento);

    ListaCircular* novo = (ListaCircular*) malloc(sizeof(ListaCircular));
    novo->info = elemento;

    ListaCircular* atual = lista;
    for (int i = 1; i < pos - 1; i++)
        atual = atual->prox;

    novo->prox = atual->prox;
    atual->prox = novo;
    return lista;
}

void lista_circular_exibe(ListaCircular* lista) {
    if (!lista) return;
    ListaCircular* atual = lista;
    do {
        printf("Elemento = %d\n", atual->info);
        atual = atual->prox;
    } while (atual != lista);
}

int lista_circular_tamanho(ListaCircular* lista) {
    if (!lista) return 0;
    int tam = 0;
    ListaCircular* atual = lista;
    do {
        tam++;
        atual = atual->prox;
    } while (atual != lista);
    return tam;
}

ListaCircular* lista_circular_remove(ListaCircular* lista, int elemento) {
    if (!lista) return NULL;

    ListaCircular *atual = lista, *ant = NULL;
    do {
        if (atual->info == elemento) {
            if (atual == lista && atual->prox == lista) {
                free(atual);
                return NULL;
            }

            if (atual == lista) {
                ListaCircular* ultimo = lista;
                while (ultimo->prox != lista)
                    ultimo = ultimo->prox;
                lista = atual->prox;
                ultimo->prox = lista;
            } else {
                ant->prox = atual->prox;
            }
            free(atual);
            return lista;
        }
        ant = atual;
        atual = atual->prox;
    } while (atual != lista);

    return lista;
}

ListaCircular* lista_circular_busca(ListaCircular* lista, int elemento) {
    if (!lista) return NULL;
    ListaCircular* atual = lista;
    do {
        if (atual->info == elemento)
            return atual;
        atual = atual->prox;
    } while (atual != lista);
    return NULL;
}
