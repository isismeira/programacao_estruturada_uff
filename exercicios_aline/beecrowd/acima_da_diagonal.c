#include <stdio.h>

int main() {
    char operacao;
    float matriz[12][12];
    float soma = 0.0;
    int contador = 0;

    scanf(" %c", &operacao);

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }

    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            soma += matriz[i][j];
            contador++;
        }
    }

    if (operacao == 'S') {
        printf("%.1f\n", soma);
    } else if (operacao == 'M') {
        printf("%.1f\n", soma / contador);
    }

    return 0;
}
