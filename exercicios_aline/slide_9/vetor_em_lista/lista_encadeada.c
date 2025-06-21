# include <stdio.h>
# include <stdlib.h>
# include "lista_encadeada.h"

typedef struct lista {
	int info;  
	struct lista* prox; 
}ListaInteiros;


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

ListaInteiros* lista_cria_de_vetor(int* vetor, int len) { // !!!
	ListaInteiros* l;

	for (int i = len - 1; i >= 0; i--) {
        l = lista_insere(l, vetor[i]);
    }

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