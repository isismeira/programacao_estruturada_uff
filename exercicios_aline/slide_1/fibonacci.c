#include <stdio.h>

int fibonacci(int numero);

int main()
{
    int numero;
    printf("Digite aqui um número para calcular os N primeiros termos da sequencia de Fibonacci: ");
    scanf("%i", &numero);

    fibonacci(numero);

    return 0;
}

int fibonacci(int numero)
{
    int numero_a = 1;
    int numero_b = 1;

    printf("Termo 1 : 1 \nTermo 2 : 1 \n");

    for (int i = 1; i <= (numero-2); i++) {
        int prox_num = numero_a + numero_b;
        
        printf("Termo %i : %i \n", (i + 2), prox_num);
        numero_a = numero_b;
        numero_b = prox_num;
    }
}