#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    float valores[n];
    int contado[n]; 

    for (int i = 0; i < n; i++) {
        scanf("%f", &valores[i]);
        contado[i] = 0; 
    }

    for (int i = 0; i < n; i++) {
        if (contado[i] == 1) continue; 

        int contagem = 1;
        for (int j = i + 1; j < n; j++) {
            if (valores[i] == valores[j]) {
                contagem++;
                contado[j] = 1; 
            }
        }

        printf("%.1f ocorre %d vez%s\n", valores[i], contagem, contagem > 1 ? "es" : "");
    }

    return 0;
}
