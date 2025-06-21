#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"  

// gcc -o usa_lista_encadeada.exe usa_lista_encadeada.c lista_encadeada.c -lm
// .\usa_lista_encadeada.exe

int main() {
    ListaInteiros* lista_1;
    ListaInteiros* lista_2;
    lista_1 = lista_cria();
    lista_2 = lista_cria();
    printf("Lista criada.\n");


    lista_1 = lista_insere(lista_1, 40);
    lista_1 = lista_insere(lista_1, 30);
    lista_1 = lista_insere(lista_1, 20);
    lista_1 = lista_insere(lista_1, 10);
    printf("\nLista_1:\n");
    lista_exibe(lista_1);
    lista_2 = lista_insere(lista_2, 40);
    lista_2 = lista_insere(lista_2, 30);
    lista_2 = lista_insere(lista_2, 20);
    lista_2 = lista_insere(lista_2, 10);
    printf("\nlista_2:\n");
    lista_exibe(lista_2);

    printf("\nlistas concatenadas:\n");
    lista_exibe(lista_concatenar(lista_1, lista_2));

    lista_exclui(lista_1);
    lista_exclui(lista_2);
    printf("\nLista liberada da memória.\n");
    return 0;
}
