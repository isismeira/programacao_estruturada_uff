#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

// gcc -o usa_lista_encadeada.exe usa_lista_encadeada.c lista_encadeada.c -lm
// .\usa_lista_encadeada.exe

int main() {

    printf("==== PARTE 1: Lista comum (inserção na cabeça e no final) ====\n");

    ListaInteiros* lista = lista_cria(); // cria lista vazia

    lista = lista_insere(lista, 30);
    lista = lista_insere(lista, 20);
    lista = lista_insere(lista, 10);
    lista_exibe(lista);

    lista = lista_insere_final_simples(lista, 40);
    lista = lista_insere_final_simples(lista, 50);
    lista_exibe(lista);

    lista_exclui(lista);

    printf("\n==== PARTE 2: Lista com controlador (inserção no final) ====\n");

    ListaControlador* controlador = lista_cria_controlador(); 

    lista_insere_final(controlador, 1);
    lista_insere_final(controlador, 2);
    lista_insere_final(controlador, 3);
    lista_insere_final(controlador, 4);

    // Exibindo a lista controlada
    printf("#### Lista encadeada (controlada) ####\n");
    ListaInteiros* p = controlador->inicio;
    while (p != NULL) {
        printf("info = %d\n", p->info);
        p = p->prox;
    }

    // Libera a memória da lista controlada
    lista_exclui(controlador->inicio);
    free(controlador); 

    return 0;
}
