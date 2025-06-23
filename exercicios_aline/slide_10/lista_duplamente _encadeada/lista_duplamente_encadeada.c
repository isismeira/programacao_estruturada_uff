# include <stdio.h>
# include <stdlib.h>
# include "lista_duplamente_encadeada.h"

typedef struct listadupla {
	int info;
	struct listadupla* ant;
	struct listadupla* prox;
}ListaDupla;

ListaDupla* lista_dupla_cria (){
	return NULL;
}

/* exclusão da lista: libera espaço de memória de cada elemento alocado dinamicamente */

void lista_dupla_libera(ListaDupla* lista){
	ListaDupla* percorre = lista;			// ponteiro para o primeiro elemento da lista
	while (percorre != NULL) {		           // enquanto não chega no último elemento
		ListaDupla* aux = percorre->prox;	   // guarda o ponteiro para o próximo elemento
		free(percorre);      				   // libera espaço do elemento corrente 
		percorre = aux;					       // lista passa apontar para o próximo elemento
	}
}


ListaDupla* lista_dupla_insere_inicio(ListaDupla* lista, int elemento){
	ListaDupla* novo = (ListaDupla*) malloc(sizeof(ListaDupla));
	novo->info = elemento;
	novo->ant = NULL;
	// lista não vazia: prox aponta para ela
	if (lista != NULL){
		novo->prox = lista;
		lista->ant = novo;
	}
	else
		novo->prox = NULL;
	return novo;
}

ListaDupla* lista_dupla_insere_fim(ListaDupla* lista, int elemento){
	ListaDupla* novo = (ListaDupla*) malloc(sizeof(ListaDupla));
	ListaDupla* percorre = lista;
	novo->info = elemento;
	novo->prox = NULL;
	
	// lista vazia
	if (lista == NULL){
		novo->ant = NULL;
		return novo;
	}
		
	// percorre a lista	
	while (percorre->prox != NULL)
		percorre = percorre->prox;

	// percorre agora aponta para o último elemento
	novo->ant = percorre;
	percorre->prox = novo;
	return lista;
}

void lista_dupla_exibe(ListaDupla* lista){
	ListaDupla* percorre = lista;
	while (percorre != NULL){
		printf("Elemento = %i\n", percorre->info);		
		percorre = percorre->prox;
	}
}

void lista_dupla_exibe_ao_contrario(ListaDupla* lista){
	ListaDupla* percorre = lista;
	// para chegar na última posição
	while (percorre->prox != NULL)
		percorre = percorre->prox;
	// escreve de trás para a frente
	while (percorre != NULL){
		printf("Elemento = %i\n", percorre->info);		
		percorre = percorre->ant;		
	}
}

int lista_dupla_tamanho(ListaDupla* lista){
	int tamanho = 0;
	ListaDupla* percorre = lista;
	
	while (percorre != NULL){
		tamanho++;
		percorre = percorre->prox;
	}
	return tamanho;
}

ListaDupla* lista_insere_em_pos(ListaDupla* lista, int elemento, int pos){
	int tamanho = lista_dupla_tamanho(lista);
	// quer inserir mais que na última posição: nao dá...
	if ((pos > (tamanho+1)) || (pos < 1))
		return lista;
	// quer inserir na primeira posição
	if (pos == 1)
		return lista_dupla_insere_inicio(lista, elemento);
	// quer inserir na última posição
	if (pos == (tamanho+1))
		return lista_dupla_insere_fim(lista, elemento);
	
	// cria dinamicamente novo elemento
	ListaDupla* novo = (ListaDupla*) malloc(sizeof(ListaDupla));
	novo->info = elemento;
	
	ListaDupla* percorre = lista;
	int indice = 1;
	while (indice < pos)
		percorre = percorre->prox;
	
	novo->prox = percorre;
	novo->ant = percorre->ant;
	
	percorre->ant->prox = novo;
	percorre->ant = novo;
	
	return lista;		
}