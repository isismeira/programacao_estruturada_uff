#include <stdio.h>
#include <math.h>

// Essa versão evita overflow

int conta_digitos(int base, int expoente);

int main() {
    int testes;
    scanf("%d", &testes);
    for (int i = 0; i < testes; i++) {
        int base, expoente;
        scanf("%d %d", &base, &expoente);
        printf("%d\n", conta_digitos(base, expoente));
    }
    return 0;
}

int conta_digitos(int base, int expoente) {
    if (base == 0)
        return 1;
    double resultado = expoente * log10(base);
    return (int)resultado + 1;
}
