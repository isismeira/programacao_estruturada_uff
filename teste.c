#include <stdio.h>

int main()
{
    int vetor[5] = {0};
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);
    printf("%i", tamanho);
    return 0;
}