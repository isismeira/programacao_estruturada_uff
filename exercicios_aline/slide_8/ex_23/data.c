#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "data.h"

typedef struct dma {
    int dia;
    int mes;
    int ano;
} Data;

Data* data_cria(int dia, int mes, int ano) {
    Data* d = (Data*) malloc(sizeof(Data));
    if (d == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }
    d->dia = dia;
    d->mes = mes;
    d->ano = ano;
    return d;
}

void data_libera(Data* d) {
    free(d);
}

void data_acessa(Data* d, int* dia, int* mes, int* ano) {
    *dia = d->dia;
    *mes = d->mes;
    *ano = d->ano;
}
 
void data_atribui(Data* d, int dia, int mes, int ano) {
    d->dia = dia;
    d->mes = mes;
    d->ano = ano;
}

// Função auxiliar p contar dias 
int total_dias(Data* d) {
    int dias_por_mes[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int dias = d->ano * 365 + d->dia;

    for (int i = 0; i < d->mes - 1; i++) {
        dias += dias_por_mes[i];
    }

    return dias;
}

int data_diferenca(Data* d1, Data* d2) {
    int total1 = total_dias(d1);
    int total2 = total_dias(d2);
    return abs(total1 - total2);
}
