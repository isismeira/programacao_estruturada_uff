# include <stdio.h>
# include <stdlib.h>
# include "lista_encadeada.h"


typedef struct lista {
	int info;  // informação armazenada
	struct lista* prox; // o ponteiro autoreferencia a lista
}ListaInteiros;


// Criação da lista: cria uma lista vazia
ListaInteiros* lista_cria ( ){
	return NULL;
}

// Inserir um novo elemento na cabeça da lista (início da lista).
ListaInteiros* lista_insere (ListaInteiros* l, int i) { // l é o ponteiro para o início atual da lista, e i, a infomação que desejamos adicionar
	ListaInteiros* novo = (ListaInteiros*)malloc(sizeof(ListaInteiros)); //  alocado dinamicamente um novo nó do tipo ListaInteiros
	novo->info = i;	// armazena o valor que queremos adicionar à lista.
	novo->prox = l;	// O campo prox do novo nó vai apontar para o início da lista atual 		
	return novo; // retorna o ponteiro para o novo início da lista 			
}

// exibe na tela os elementos na lista 
void lista_exibe(ListaInteiros* l) {
	puts("#### Lista encadeada #####");
	ListaInteiros* p;						// ponteiro auxiliar para "andar" na lista
	for (p = l; p != NULL; p = p->prox)		// percorre a lista, apontando para cada elemento a cada iteração 
		printf("info = %d\n", p->info);		// imprime a informação armazenada no nó
 }
 

// exclusão da lista: libera espaço de memória de cada elemento alocado dinamicamente
void lista_exclui (ListaInteiros* l){
	ListaInteiros* p = l;			// ponteiro para o primeiro elemento da lista
	while (p != NULL) {			// enquanto não chega no último elemento
		ListaInteiros* t = p->prox;	// guarda o ponteiro para o próximo elemento
		free(p);				// libera espaço do elemento corrente
		p = t;					// lista passa apontar para o próximo elemento
	}
}


int lista_vazia (ListaInteiros* l){
	return (l == NULL);
}


// procura um determinado elemento na lista 

ListaInteiros* busca (ListaInteiros* l, int v) { 
	ListaInteiros* p;
	for (p = l; p != NULL; p = p->prox) {
		if (p->info == v)				// achou a informação: termina a busca
			return p;
	}
	return NULL;					// passou por todos os elementos e não achou o procurado 
}

// Exclui um determinado elemento v da lista encadeada
ListaInteiros* lista_remove_elemento(ListaInteiros* l, int v) {
	ListaInteiros* ant = NULL;			// ponteiro para armazenar o elemento anterior	
	ListaInteiros* p = l;				// ponteiro para percorrer a lista
	while (p != NULL && p->info != v) { 	// não chegou no fim e não achou o elemento
		ant = p;					// aponta para o próximo elemento
		p = p->prox; 
	}
	if (p == NULL)					// chegou no fim da lista e não achou o elemento
		return l;					// a lista permanece a mesma
	if (ant == NULL)					// (Caso 1) é o primeiro elemento, logo 
		l = p->prox; 				// lista passa a apontar para o ex-segundo elemento
	else 
		ant->prox = p->prox; 			// (casos 2 e 3) corta a referência com o elemento encontrado
	free(p);						// libera o espaço alocado para o elemento
	return l;						
}

// insere elemento em ordem 
ListaInteiros* lista_insere_ordenado (ListaInteiros* l, int v) {
	ListaInteiros* ant = NULL;					// ponteiro para guardar o elemento que ficará antes do novo 
	ListaInteiros* p = l;							// ponteiro para percorrer a lista
	while (p != NULL && p->info < v) { 		// percorre a lista até achar a posição correta
		ant = p; 
		p = p->prox; 
	}
	ListaInteiros* novo = (ListaInteiros*) malloc(sizeof(ListaInteiros));	// aloca espaço para o novo elemento
	novo->info = v;						// insere a nova informação
	if (ant == NULL){						// elemento é o menor da lista: entrará...
		novo->prox = l; 					// na primeira posição e lista passará a 	
		l = novo; 						// apontar para ele
	}
	else { 
		novo->prox = ant->prox;			// elemento é inserido em alguma posição
		ant->prox = novo; 				// intermediária ou no fim da lista
	}
	return l;
}