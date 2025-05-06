#include <stdio.h>

int main()
{
    int x = 10;  // valor 10 está na gaveta 0061FF18
    int *p = &x; // p é um papel(ponteiro) que diz "0061FF18"

    // (&) Endereço de
    printf("Endereco de x: %p \n", &x); // Exibe "0061FF18" // endereço de x

    // (*) Conteúdo de
    printf("Valor de x: %d", *p); // Exibe 10

    // Modificar via ponteiro
    // *p = 99
    // printf("Novo valor de x: %d", x);

    // Passando ponteiros para modificar valores fora da função
    int num = 5;
    incrementar(&num); // num agora é 6
}

void incrementar(int *num) {
    (*num)++; // Altera o valor original
}