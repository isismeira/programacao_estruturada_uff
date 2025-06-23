#include <stdio.h>
#include <stdlib.h>
#include "vetores.h"

typedef struct vetor {
    float* vetor;
    int len;
} Vetor;

Vetor* cria_vetor(int len) {
    Vetor* v = (Vetor*)malloc(sizeof(Vetor));
    if (v==NULL) {
        printf("Memória insufuciente");
        exit(1);
    }

    v->vetor = (float*)malloc(len * sizeof(float));
    if (v->vetor == NULL){
        free(v);
        printf("memória insuficiente");
        exit(1);
    }

    v->len = len;
    return v;
}

void preenche_vetor(Vetor* v, float* valores) {
    for (int i = 0; i < 3; i++) {
        v->vetor[i] = valores[i];
    }
}

float acessar_elemento(Vetor* v, int i) {
    return v->vetor[i];
}


void soma_vetores(Vetor* v1, Vetor* v2, Vetor* v3) {
    for (int i = 0; i < 3; i++) {
        v3->vetor[i] = v2->vetor[i] + v1->vetor[i];
    }
}

void multiplica_vetores(Vetor* v1, Vetor* v2, Vetor* v3) {
    for (int i = 0; i < 3; i++) {
        v3->vetor[i] = v2->vetor[i] * v1->vetor[i];
    }
}

void mult_escalar_vetor(Vetor* v, float k) {
    for (int i = 0; i < 3; i++) {
        v->vetor[i] = v->vetor[i] * k;
    }
}

void free_vetor(Vetor* v) {
    free(v->vetor);
    free(v);
}