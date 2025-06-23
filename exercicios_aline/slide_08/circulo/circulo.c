#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "circulo.h"

typedef struct circulo {
    float x;
    float y;
    float raio;
} Circulo;

Circulo* cria_circulo(float x, float y, float raio) {
    Circulo* c = (Circulo*) malloc(sizeof(Circulo));
    if (c == NULL) {
        printf("Memoria insuficiente");
        exit(1);
    }

    c->x = x;
    c->y = y;
    c->raio = raio;

    return c;
}

void acessa_circulo (Circulo* c, float* x, float* y, float* raio) 
{
    *x = c->x;
    *y = c->y;
    *raio = c->raio;
}

void atribui_circulo (Circulo* c, float x, float y, float raio)
{
    c->x = x;
    c->y = y;
    c->raio = raio;
}

void libera_circulo(Circulo* c) {
    free(c);
}

float area_circulo(Circulo* c) {
    float area = (3.14) * (c->raio) * (c->raio);
    return area;
}

int dentro_circulo(Circulo* c, float x_novo, float y_novo) {
    float dx = x_novo - c->x; 
    float dy = y_novo - c->y;
    float distancia_do_centro = sqrt(dx * dx);
    return (distancia_do_centro <= c->raio);
}