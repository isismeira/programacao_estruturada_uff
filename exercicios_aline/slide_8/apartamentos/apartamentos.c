#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apartamentos.h"

typedef struct apartamento {
    char nome[50];
    int numero;
    float area;
    int moradores;
    float valor;
} Apartamento;

Apartamento* cria_vetor_apartamentos(int qtd) {
    Apartamento* apts = malloc(sizeof(Apartamento) * qtd);
    if (apts == NULL) {
        printf("Memória insuficiente\n");
        exit(1);
    }
    for (int i = 0; i < qtd; i++) {
        apts[i].valor = 0.0;
    }
    return apts;
}

void le_dados_apartamentos(Apartamento* apts, int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("\nApartamento %d:\n", i + 1);
        printf("Nome do responsável: ");
        scanf(" %[^\n]", apts[i].nome);

        printf("Número do apartamento: ");
        scanf("%d", &apts[i].numero);

        printf("Área (m²): ");
        scanf("%f", &apts[i].area);

        printf("Número de moradores: ");
        scanf("%d", &apts[i].moradores);

        apts[i].valor = 0.0;
    }
}

float calcula_area_total(Apartamento* apts, int qtd) {
    float soma = 0;
    for (int i = 0; i < qtd; i++) {
        soma += apts[i].area;
    }
    return soma;
}

void calcula_valores(Apartamento* apts, int qtd, float despesa_total) {
    float area_total = calcula_area_total(apts, qtd);
    for (int i = 0; i < qtd; i++) {
        apts[i].valor = (apts[i].area / area_total) * despesa_total;
    }
}

void imprime_apartamento_maior_moradores(Apartamento* apts, int qtd) {
    int max_idx = 0;
    for (int i = 1; i < qtd; i++) {
        if (apts[i].moradores > apts[max_idx].moradores) {
            max_idx = i;
        }
    }

    printf("\nApartamento com mais moradores:\n");
    printf("Nome do responsável: %s\n", apts[max_idx].nome);
    printf("Número do apartamento: %d\n", apts[max_idx].numero);
    printf("Área: %.2f m²\n", apts[max_idx].area);
    printf("Moradores: %d\n", apts[max_idx].moradores);
    printf("Valor a pagar: R$ %.2f\n", apts[max_idx].valor);
}

void libera_apartamentos(Apartamento* apts) {
    free(apts);
}
