#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"  // Certifique-se de que esse cabeçalho está correto

// gcc -o usa_lista_encadeada.exe usa_lista_encadeada.c lista_encadeada.c -lm
// .\usa_lista_encadeada.exe

int main() {
    ListaInteiros* lista;

    // 1. Criando a lista
    lista = lista_cria();
    printf("Lista criada.\n");

    // 2. Verificando se está vazia
    if (lista_vazia(lista)) {
        printf("A lista está vazia.\n");
    }

    // 3. Inserindo elementos na cabeça
    lista = lista_insere(lista, 30);
    lista = lista_insere(lista, 20);
    lista = lista_insere(lista, 10);
    printf("\nApós inserções na cabeça:\n");
    lista_exibe(lista);

    // 4. Inserindo elementos ordenados
    lista = lista_insere_ordenado(lista, 25);
    lista = lista_insere_ordenado(lista, 5);
    lista = lista_insere_ordenado(lista, 35);
    printf("\nApós inserções ordenadas:\n");
    lista_exibe(lista);

    // 5. Buscando um elemento
    int valor_busca = 25;
    ListaInteiros* encontrado = busca(lista, valor_busca);
    if (encontrado != NULL) {
        printf("\nValor %d encontrado na lista.\n", valor_busca);
    } else {
        printf("\nValor %d não encontrado.\n", valor_busca);
    }

    // 6. Removendo elementos
    lista = lista_remove_elemento(lista, 10);  
    lista = lista_remove_elemento(lista, 30);  
    lista = lista_remove_elemento(lista, 35);  
    printf("\nApós remoções (10, 30, 35):\n");
    lista_exibe(lista);

    // 7. Verificando se está vazia após remoções
    if (lista_vazia(lista)) {
        printf("A lista está vazia.\n");
    } else {
        printf("A lista NÃO está vazia.\n");
    }

    // 8. Excluindo a lista completa
    lista_exclui(lista);
    printf("\nLista liberada da memória.\n");

    return 0;