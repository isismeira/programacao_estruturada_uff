#include <stdio.h>

void conceito_de_ponteiro()
{
    int x = 10;
    printf("Esse é o valor de x: %i \n", x);
    printf("Esse é o endereço de x: %i \n", &x);

    int *ponteiro = &x; // "apontamos o ponteiro para o endereço de x"
    printf("Acessando o valor do ponteiro: %i \n", *ponteiro);
    printf("Acessando o endereço que o ponteiro aponta: %p \n", ponteiro);

}

void troca_com_ponteiros(int *px, int *py)
{
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

void incrementa_vetor(int *vetor)
{
    for (int i = 0; i < 5; i++) {
        vetor[i]++;
    }
}

int main()
{
    int a = 1, b = 2;
    printf("%i %i\n", a, b);
    troca_com_ponteiros(&a, &b);
    printf("%i %i\n", a, b);

    int vetor[5] = {1,2,3,4,5};
    incrementa_vetor(&vetor[0]);
    for (int i = 0; i < 5; i++){
        printf("%i ", vetor[i]);
    }
    
    return 0;
}