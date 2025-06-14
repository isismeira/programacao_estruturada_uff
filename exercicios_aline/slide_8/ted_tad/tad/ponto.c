#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

typedef struct ponto {
	float x;
	float y;
}Ponto;

// "->" é a maneira de acessar campos de uma struct através de um ponteiro

//Função para criar o ponto dinâmicamente
Ponto* pto_cria(float x, float y){
	Ponto* p = (Ponto*) malloc(sizeof(Ponto));
	if (p == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	}
	p->x = x;
	p->y = y;
	return p;
}


// Função para liberar a memória do ponto
void pto_libera (Ponto* p){
	free(p);
}

//Função para calcular a distância entre dois pontos
float pto_distancia (Ponto* p1, Ponto* p2){
	float dx = p2->x - p1->x;
	float dy = p2->y - p1->y;
	return sqrt(dx*dx + dy*dy);
}


// Função para acessar as coordenadas de um ponto
void pto_acessa (Ponto* p, float* x, float* y){
	*x = p->x;
	*y = p->y;
}

// Função para alterar as coordenadas de um ponto
void pto_atribui (Ponto* p, float x, float y){
	p->x = x;
	p->y = y;
}