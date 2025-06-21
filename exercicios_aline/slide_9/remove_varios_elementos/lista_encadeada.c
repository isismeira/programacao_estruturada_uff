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

ListaInteiros* lista_remove_todos(ListaInteiros* l, int v) {  // !!!
    ListaInteiros* p = l;
    ListaInteiros* ant = NULL;

    while (p != NULL) {
        if (p->info == v) {
            ListaInteiros* temp = p;

            if (ant == NULL) {
                // Elemento a ser removido é o primeiro
                l = p->prox;
                p = l;
            } else {
                ant->prox = p->prox;
                p = p->prox;
            }

            free(temp);
        } else {
            ant = p;
            p = p->prox;
        }
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