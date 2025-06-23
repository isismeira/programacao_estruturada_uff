#include <stdio.h>

int fatorial(int numero);

int main()
{
    int numero;

    printf("Digite aqui um numero e retornaremos o seu fatorial: ");
    scanf("%i", &numero);

    int resultado = fatorial(numero);

    printf("%i! = %i", numero, resultado);

    return 0;
}


int fatorial(int numero)
{
    int resultado = 1;

    for (int i = numero; i >= 1; i--) {
        resultado *= i;
    }

    return resultado;
}
