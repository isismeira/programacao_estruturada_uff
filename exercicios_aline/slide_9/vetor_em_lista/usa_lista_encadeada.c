#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"  

// gcc -o usa_lista_encadeada.exe usa_lista_encadeada.c lista_encadeada.c -lm
// .\usa_lista_encadeada.exe

int main() {
    ListaInteiros* lista; 

    int vetor[5] = {1,2,3,4,5};
    int len = 5;

    lista = lista_cria_de_vetor(vetor, len);

    lista_exibe(lista);

    lista_exclui(lista);
    printf("\nLista liberada da memória.\n");
    return 0;
}
