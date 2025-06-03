#include <stdio.h>
#include "data.h"

int main() {
    Data* d1 = data_cria(10, 5, 2020);
    Data* d2 = data_cria(25, 12, 2023);

    int diferenca = data_diferenca(d1, d2);
    printf("Diferença em dias: %d\n", diferenca);

    data_libera(d1);
    data_libera(d2);
    return 0;
}