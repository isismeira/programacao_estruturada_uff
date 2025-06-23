#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

// gcc -o usa_lista_encadeada.exe usa_lista_encadeada.c lista_encadeada.c -lm
// .\usa_lista_encadeada.exe

int main() {
    ListaInteiros* lista = lista_cria(); // cria lista vazia

    lista = lista_insere(lista, 30);
    lista = lista_insere(lista, 20);
    lista = lista_insere(lista, 10);
    lista = lista_insere(lista, 10);
    lista = lista_insere(lista, 30);
    lista = lista_insere(lista, 10);
    lista_exibe(lista);

    lista = lista_remove_todos(lista, 10);
    lista_exibe(lista);

    lista_exclui(lista);

    return 0;
}
