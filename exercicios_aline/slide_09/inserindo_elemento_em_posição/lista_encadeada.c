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

ListaInteiros* lista_insere_posicao(ListaInteiros* l, int valor, int pos) { // !!!
    ListaInteiros* novo = (ListaInteiros*)malloc(sizeof(ListaInteiros));
    novo->info = valor;

    ListaInteiros* p = l;
    int i = 0;

    while (p != NULL && i < pos - 1) {
        p = p->prox;
        i++;
    }

    novo->prox = p->prox;
    p->prox = novo;

    return l;
}

ListaInteiros* lista_insere_depois_de(ListaInteiros* l, int valor, int x) { // !!!
    ListaInteiros* p = l;

    while (p != NULL && p->info != x) {
        p = p->prox;
    }

    if (p == NULL) {
        return l;
    }

    ListaInteiros* novo = malloc(sizeof(ListaInteiros));
    novo->info = valor;
    novo->prox = p->prox;
    p->prox = novo;

    return l;
}

void lista_exclui (ListaInteiros* l){
	ListaInteiros* p = l;			
	while (p != NULL) {			
		ListaInteiros* t = p->prox;	
		free(p);				
		p = t;					
	}
}