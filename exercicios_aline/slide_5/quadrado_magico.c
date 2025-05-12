#include <stdio.h>
#include <stdlib.h>

int **alocar_matriz(int l, int c);
void ler_matriz(int **matriz, int l, int c);
void verifica_soma_linhas(int **matriz, int l, int c, int *vetor_retorno);
void verifica_soma_colunas(int **matriz, int l, int c, int *vetor_retorno);
void verifica_soma_diagonais(int **matriz, int l, int c, int *vetor_retorno);
int eh_quadrado_magico(int *vetor_retorno_linha, int *vetor_retorno_coluna, int *vetor_retorno_diagonal);

int main() {
    int l, c;
    printf("Digite o número de linhas e colunas: ");
    scanf("%i %i", &l, &c);

    int **matriz = alocar_matriz(l, c);
    ler_matriz(matriz, l, c);

    int a[2], b[2], d[2];
    verifica_soma_linhas(matriz, l, c, a);
    verifica_soma_colunas(matriz, l, c, b);
    verifica_soma_diagonais(matriz, l, c, d);

    if (!eh_quadrado_magico(a, b, d)) {
        return 0;
    }

    printf("eh quadrado magico\n");

    for (int i = 0; i < l; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

int **alocar_matriz(int l, int c) {
    int **matriz = (int **)malloc(l * sizeof(int *));
    for (int i = 0; i < l; i++)
        matriz[i] = (int *)malloc(c * sizeof(int));
    return matriz;
}

void ler_matriz(int **matriz, int l, int c) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("Digite o elemento da linha %i e da coluna %i: ", i, j);
            scanf("%i", *(matriz + i) + j);
        }
    }
}

void verifica_soma_linhas(int **matriz, int l, int c, int *vetor_retorno) {
    int soma_anterior = 0;
    vetor_retorno[0] = 1;

    for (int i = 0; i < l; i++) {
        int soma = 0;
        for (int j = 0; j < c; j++) {
            soma += *(*(matriz + i) + j);
        }

        if (i == 0) {
            soma_anterior = soma;
        } else if (soma != soma_anterior) {
            vetor_retorno[0] = 0;
        }
    }

    vetor_retorno[1] = soma_anterior;
}

void verifica_soma_colunas(int **matriz, int l, int c, int *vetor_retorno) {
    int soma_anterior = 0;
    vetor_retorno[0] = 1;

    for (int j = 0; j < c; j++) {
        int soma = 0;
        for (int i = 0; i < l; i++) {
            soma += *(*(matriz + i) + j);
        }

        if (j == 0) {
            soma_anterior = soma;
        } else if (soma != soma_anterior) {
            vetor_retorno[0] = 0;
        }
    }

    vetor_retorno[1] = soma_anterior;
}

void verifica_soma_diagonais(int **matriz, int l, int c, int *vetor_retorno) {
    int diagonal1 = 0, diagonal2 = 0;

    for (int i = 0; i < l; i++) {
        diagonal1 += *(*(matriz + i) + i);
        diagonal2 += *(*(matriz + i) + (c - 1 - i));
    }

    vetor_retorno[0] = (diagonal1 == diagonal2);
    vetor_retorno[1] = diagonal1;
}

int eh_quadrado_magico(int *vetor_retorno_linha, int *vetor_retorno_coluna, int *vetor_retorno_diagonal) {
    if (!vetor_retorno_linha[0] || !vetor_retorno_coluna[0] || !vetor_retorno_diagonal[0]) {
        return 0;
    }

    int soma = vetor_retorno_linha[1];

    if (vetor_retorno_coluna[1] != soma || vetor_retorno_diagonal[1] != soma) {
        return 0;
    }

    return 1;
}
