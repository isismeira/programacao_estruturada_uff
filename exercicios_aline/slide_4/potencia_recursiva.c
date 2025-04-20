#include <stdio.h>

int potencia(int base, int expoente);

int main()
{
    int base, expoente;
    scanf("%i %i", &base, &expoente);
    int resultado = potencia(base, expoente); 
    printf("%i^%i = %i", base, expoente, resultado);
    return 0;
}

int potencia(int base, int expoente)
{
    if (expoente == 0) {
        return 1;
    } else {
        return base * potencia(base, expoente - 1);
    }
}