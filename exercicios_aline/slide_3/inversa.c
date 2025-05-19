#include <stdio.h>

int main() {
    int n;

    printf("Digite a ordem da matriz quadrada: ");
    scanf("%d", &n);

    float matriz[10][20];  // matriz aumentada: [n][2n]

    // Leitura da matriz original
    printf("Digite os elementos da matriz (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }

    // Monta a parte da matriz identidade ao lado direito
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2 * n; j++) {
            if (j == i + n)
                matriz[i][j] = 1.0;
            else
                matriz[i][j] = 0.0;
        }
    }

    // Aplicação do método de Gauss-Jordan
    for (int i = 0; i < n; i++) {
        float pivo = matriz[i][i];
        if (pivo == 0) {
            printf("Matriz não possui inversa (pivô zero).\n");
            return 1;
        }

        // Normaliza a linha do pivô
        for (int j = 0; j < 2 * n; j++) {
            matriz[i][j] = matriz[i][j] / pivo;
        }

        // Zera as outras linhas da coluna do pivô
        for (int k = 0; k < n; k++) {
            if (k != i) {
                float fator = matriz[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    matriz[k][j] = matriz[k][j] - fator * matriz[i][j];
                }
            }
        }
    }

    // Exibe a matriz inversa (lado direito da aumentada)
    printf("\nMatriz inversa:\n");
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2 * n; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
