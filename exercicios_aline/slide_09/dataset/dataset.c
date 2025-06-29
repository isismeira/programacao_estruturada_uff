#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataset.h"

// Questão 1)
typedef struct exemplo {
    char palavra[100];
    float grupo_1[8];
    int inteiro;
    float grupo_2[8];
    char binario_1[8];
    char binario_2[8];
} Exemplo;

Exemplo* cria_exemplo(char *palavra, float *grupo_1, int inteiro, float *grupo_2, char *binario_1, char*binario_2) {
    Exemplo* e = (Exemplo*)malloc(sizeof(Exemplo));

    strcpy(e->palavra, palavra);
    memcpy(e->grupo_1, grupo_1, sizeof(float) * 8); // ❌ e->grupo_1 = grupo_1
    e->inteiro = inteiro;
    memcpy(e->grupo_2, grupo_2, sizeof(float) * 8); // ❌ e->grupo_2 = grupo_2
    strcpy(e->binario_1, binario_1);
    strcpy(e->binario_2, binario_2);

    return e;
}

void libera_exemplo(Exemplo* e) {
    free(e->palavra); 
    free(e->grupo_1);
    free(e->grupo_2);
    free(e->binario_1);
    free(e->binario_2); 
    free(e);
}

// Questão 2)
typedef struct dataset {
    Exemplo* info;
    struct dataset* prox;
} Dataset;

Dataset* cria_dataset() {
    return NULL;
}

void libera_dataset(Dataset* d) {
    Dataset* p = d;
    while (p->prox != NULL){
        Dataset* temp = p;
        libera_exemplo(temp->info);
        /* free(temp->info->palavra);
        free(temp->info->grupo_1);
        free(temp->info->grupo_2);
        free(temp->info->binario_1);
        free(temp->info->binario_2); */
        free(temp);
        p = p->prox;
    }
    free(d);
}

// Questão 3)
typedef struct elemento {
    Exemplo* info;
    struct elemento* prox;
}Elemento;

typedef struct fila {
    Elemento* primeiro;
    Elemento* ultimo;
} Fila;

Fila* cria_fila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->primeiro = NULL;
    f->ultimo = NULL;
    return f;
}

Fila* fila_free(Fila* f) {
    Elemento* percorre = f->primeiro;
    while(percorre != NULL) {
        Elemento* aux = percorre->prox;
        libera_exemplo(percorre->info); // Linha ausente
        free(percorre);
        percorre = aux;
    }
    free(f);
}

// Questão 4)
void insere_duas_filas(char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "r");

    int qtdd_linhas = 0; 
    fscanf(arquivo, "%i", &qtdd_linhas);

    Fila* fila_1 = cria_fila();
    Fila* fila_2 = cria_fila();

    while(1) {
            char p[100];
            float g1_1, g1_2, g1_3, g1_4, g1_5, g1_6, g1_7, g1_8;
            int i;
            float g2_1, g2_2, g2_3, g2_4, g2_5, g2_6, g2_7, g2_8;
            char b1[10];
            char b2[10];

            if (fscanf (arquivo, "%s %f %f %f %f %f %f %f %f %i %f %f %f %f %f %f %f %f %s %s",
                p,
                &g1_1, &g1_2, &g1_3, &g1_4, &g1_5, &g1_6, &g1_7, &g1_8,
                &i,
                &g2_1, &g2_2, &g2_3, &g2_4, &g2_5, &g2_6, &g2_7, &g2_8,
                b1,
                b2
            ) != 20) break;

            float grupo_1[8] = {g1_1, g1_2, g1_3, g1_4, g1_5, g1_6, g1_7, g1_8};
            float grupo_2[8] = {g2_1, g2_2, g2_3, g2_4, g2_5, g2_6, g2_7, g2_8};

            Exemplo* e = cria_exemplo(p, grupo_1, i, grupo_2, b1, b2);

            int len_b2 = strlen(b2);
            if (b2[len_b2-1] == '0') {
                fila_1 = insere_fila(fila_1, e);
            } else {
                fila_2 = insere_fila(fila_2, e);
            }
        }
    fclose(arquivo);    
}

Fila* insere_fila(Fila* f, Exemplo* e) {
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    novo->info = e;
    novo->prox = NULL;
    if (f->primeiro == NULL) {
        f->primeiro = novo;
    } else {
        f->ultimo->prox = novo;
    }
    f->ultimo = novo;
    return f;
}

// Questão 5) ❗
int eh_combinacao_linear(Fila* f, float vetor[], float escalares[8]) {
    Elemento* percorre = f->primeiro;

    float matriz[100][8];
    int n_vetores = 0;

    while(percorre != NULL) {
        for (int j = 0; j < 8; j++) {
            matriz[n_vetores][j] = percorre->info->grupo_1[j];
        }
        n_vetores++;
        percorre = percorre->prox;
    }

    float comb_lin[8] = {0};
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < n_vetores; i++) {
            comb_lin[j] += matriz[i][j] * escalares[i];
        }
    }

    for (int j = 0; j < 8; j++) {
        if (comb_lin[j] != vetor[j]) {
            return 0;
        }
    }

    return 1;
}

// Questão 6) ❗
Dataset* inverter_lista_rec(Dataset* atual, Dataset** novo_inicio) {
    if (atual == NULL || atual->prox == NULL) {
        *novo_inicio = atual;
        return atual;
    }

    Dataset* anterior = inverter_lista_rec(atual->prox, novo_inicio);
    anterior->prox = atual;
    atual->prox = NULL;
    return atual;
}

Dataset* inverter_lista(Dataset* lista) {
    Dataset* novo_inicio = NULL;
    inverter_lista_rec(lista, &novo_inicio);
    return novo_inicio;
}
