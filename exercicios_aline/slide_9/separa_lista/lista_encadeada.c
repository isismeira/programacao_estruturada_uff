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

int lista_len(ListaInteiros* l) { // !!!
	ListaInteiros* p;
	int contador = 0;						
	for (p = l; p != NULL; p = p->prox)	
		contador++;
	return contador;	
 }


ListaInteiros* lista_meio(ListaInteiros* l, int len) { // !!!
	int meio_lista = len / 2;
	int contador = 0;

	ListaInteiros* p = l;
	while (contador != meio_lista) {
		p = p->prox;
		contador++;
	}
	return p;
}

ListaInteiros* lista_separa_elemento(ListaInteiros* l, int i) { // !!!
	ListaInteiros* p; 
	for (p = l; p != NULL; p = p->prox)	 {
		if (p->info == i) {
			return p;
		}
	}
}

ListaInteiros* lista_separa_posicao(ListaInteiros* l, int indice) { // !!!
	ListaInteiros* p = l;
	int contador = 0;
	while (contador != indice) {
		p = p->prox;
		contador++;
	}
	return p;
}

void lista_exclui (ListaInteiros* l){
	ListaInteiros* p = l;			
	while (p != NULL) {			
		ListaInteiros* t = p->prox;	
		free(p);				
		p = t;					
	}
}