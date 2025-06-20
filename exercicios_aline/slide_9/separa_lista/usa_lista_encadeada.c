#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"  

// gcc -o usa_lista_encadeada.exe usa_lista_encadeada.c lista_encadeada.c -lm
// .\usa_lista_encadeada.exe

int main() {
    ListaInteiros* lista;

    lista = lista_cria();
    printf("Lista criada.\n");

    lista = lista_insere(lista, 40);
    lista = lista_insere(lista, 30);
    lista = lista_insere(lista, 20);
    lista = lista_insere(lista, 10);
    printf("\nApós inserções na cabeça:\n");
    lista_exibe(lista);

    int len_lista = lista_len(lista); 

    lista_exibe(lista_meio(lista, len_lista));
    lista_exibe(lista_separa_elemento(lista, 20));
    lista_exibe(lista_separa_posicao(lista, 3));

    lista_exclui(lista);
    printf("\nLista liberada da memória.\n");
    return 0;
}
