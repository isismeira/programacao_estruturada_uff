#include <stdio.h>

/*O problema pede que você leia uma matriz 12x12 e, dependendo da operação (S para soma ou M para média), 
realize a operação apenas na área direita da matriz, conforme indicado na parte verde da imagem. */

int main() {
    char operacao;
    double matriz[12][12], soma = 0.0;
    int contador = 0;

    // Leitura da operação
    scanf(" %c", &operacao);

    // Leitura da matriz
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }

    // Cálculo da área direita
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if ((j > i && j > 11 - i)) { // condição para a área verde (direita)
                soma += matriz[i][j];
                contador++;
            }
        }
    }

    // Saída conforme operação
    if (operacao == 'S') {
        printf("%.1lf\n", soma);
    } else if (operacao == 'M') {
        printf("%.1lf\n", soma / contador);
    }

    return 0;
}
