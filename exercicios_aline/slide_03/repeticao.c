#include <stdio.h>

// Para entender melhor a lógica desse programa, olhar a imagem 'repeticao.jpeg' dessa pasta

int main()
{
    int n = 8;
    float sequencia[] = {-1.7, 3.0, 0.0, 1.5, 0.0, -1.7, 2.3, -1.7};

    int ja_contado[8] = {0}; // marca se o número ja foi contado
    
    for (int i = 0; i < n; i++) {
        if (ja_contado[i]) continue; // pula se já foi contado

        int contador = 1;
        for (int j = i + 1; j < n; j++) {
            if (sequencia[i] == sequencia[j]) {
                contador++;
                ja_contado[j] = 1;
            }
        }

        printf("%.1f ocorre %d vez(es)\n", sequencia[i], contador);
    }

    return 0;
}