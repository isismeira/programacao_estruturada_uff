# include <stdio.h>
# include <stdlib.h>
# include "lista_encadeada.h"

ListaInteiros* lista_cria ( ){
	return NULL;
}

void lista_exibe(ListaInteiros* l) {
	puts("#### Lista encadeada #####");
	ListaInteiros* p;						
	for (p = l; p != NULL; p = p->prox)		
		printf("info = %d\n", p->info);		
 }

ListaInteiros* lista_insere (ListaInteiros* l, int i) { 
	ListaInteiros* novo = (ListaInteiros*)malloc(sizeof(ListaInteiros));
	novo->info = i;	
	novo->prox = l;			
	return novo; 
}

// Insere no final sem TAD adicional
ListaInteiros* lista_insere_final_simples(ListaInteiros* l, int valor) { 
    ListaInteiros* novo = (ListaInteiros*)malloc(sizeof(ListaInteiros));
    novo->info = valor;
    novo->prox = NULL;

    if (l == NULL) {
        // Lista estava vazia
        return novo;
    }

    // Percorre até o final da lista
    ListaInteiros* p = l;
    while (p->prox != NULL) {
        p = p->prox;
    }

    // Liga o último nó ao novo nó
    p->prox = novo;
    return l;
}

// Insere no final COM TAD adicional
// Cria e inicializa o controlador
ListaControlador* lista_cria_controlador() { // ListaControlador é uma estrutura que guarda dois ponteiros
    ListaControlador* c = (ListaControlador*)malloc(sizeof(ListaControlador)); 
    c->inicio = NULL; // aponta para o primeiro elemento da lista
    c->fim = NULL; // aponta para o último elemento da lista
    return c;
}

// Insere elemento no final da lista controlada
void lista_insere_final(ListaControlador* controlador, int valor) {
    ListaInteiros* novo = (ListaInteiros*)malloc(sizeof(ListaInteiros)); // aloca dinâmicamente um novo nó
    novo->info = valor; // atribui o valor novo no campo da informação do novo nó
    novo->prox = NULL; // não aponta para nada

    if (controlador->inicio == NULL) { // caso a lista esteja vazia
        controlador->inicio = novo;
        controlador->fim = novo;
    } else { // caso a lista não esteja vazia
        //controlador->fim aponta para o último nó 
        controlador->fim->prox = novo; /// controlador->fim->prox aponta para o próximo nó depois do último
        controlador->fim = novo; // o campo fim do controlador aponta corretamente para o último nó
    }
}

void lista_exclui (ListaInteiros* l){
	ListaInteiros* p = l;			
	while (p != NULL) {			
		ListaInteiros* t = p->prox;	
		free(p);				
		p = t;					
	}
}