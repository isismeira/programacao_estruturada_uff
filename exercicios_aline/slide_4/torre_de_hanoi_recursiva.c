#include <stdio.h>

void hanoi(int n, char origem, char destino, char auxiliar);

int main() {
    int num_discos = 3;

    printf("Solução para %d discos:\n", num_discos);
    hanoi(num_discos, 'A', 'C', 'B');

    return 0;
}

void hanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mover disco 1 de %c para %c\n", origem, destino);
        return;
    }

    // Move n-1 discos da origem para o auxiliar
    hanoi(n - 1, origem, auxiliar, destino);

    // Move o maior disco (o último) da origem para o destino
    printf("Mover disco %d de %c para %c\n", n, origem, destino);

    // Move os n-1 discos do auxiliar para o destino
    hanoi(n - 1, auxiliar, destino, origem);
}
