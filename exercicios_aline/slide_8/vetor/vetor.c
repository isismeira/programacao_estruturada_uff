#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

typedef struct vetor{
    float* vetor;
    int len;
} Vetor;

Vetor* cria_vetor(int len) {
    Vetor* v = (Vetor*)malloc(sizeof(Vetor)); // Aloca memória para um objeto do tipo Vetor
    if (v == NULL) {
        printf("Memória insuficiente");
        exit(1);
    }

    v->vetor = (float*)malloc(len * sizeof(float)); // Aloca memória para um vetor de floats de tamanho len
    if (v->vetor == NULL) {
        free(v);
        printf("Memória insuficiente");
        exit(1);
    }

    v->len = len; // Define o tamanho do vetot na estrutura
    return v; // retorna o ponteiro
}

void acessa_vetor(Vetor* v, int posicao, float* valor) {
    if (posicao >= 0 && posicao < v->len) {
        *valor = v->vetor[posicao];
    }
}

void atribui_vetor(Vetor* v, int posicao, float valor) {
    if (posicao >= 0 && posicao < v->len) {
        v->vetor[posicao] = valor;
    }
}

void libera_vetor(Vetor* v) {
    free(v);
}

void preenche_vetor(Vetor* v, float* valores) {
    for (int i = 0; i < v -> len; i++) {
        v->vetor[i] = valores[i];
    }
}

void soma_vetor(Vetor* v) {
    if (v->len == 0) return;
    
    for (int i = 1; i < v->len; i++) {
        v->vetor[i] += v->vetor[i-1];
    }
}

float menor_elemento_vetor(Vetor* v) {
    float min = v->vetor[0];
    for (int i = 1; i < v->len; i++) {
        if (v->vetor[i] < min) {
            min = v->vetor[i];
        }
    }
    return min;    
}

float maior_elemento_vetor(Vetor* v) {
   float max = v->vetor[0];
   for (int i = 1; i < v->len; i++) {
    if (v->vetor[i] > max) {
        max = v->vetor[i];
    }
   }
    return max;    
}

int vetor_busca(Vetor* v, float elemento) {
    for (int i = 0; i < v->len; i++) {
        if (v->vetor[i] == elemento) {
            return i;
        }
    }
    return -1;
}