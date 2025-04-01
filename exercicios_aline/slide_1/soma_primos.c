#include <stdio.h>

int eh_primo(int numero);
int soma_primos(int numero);

int main()
{
    int numero;
    
    printf("Digite um numero e direi quantos primos existem ate ele: ");
    scanf("%i", &numero);

    int resultado = soma_primos(numero);

    printf("Existem %i primos de 0 até %i", resultado, numero);

    return 0;
}

int soma_primos(int numero)
{
    int soma = 0;

    while (numero > 0) {
        if (eh_primo(numero) == 1){
            printf("%i eh primo", numero);
            soma++;
        }
        numero--;
    }

    return soma;
}

int eh_primo(int numero)
{
    int i;

    if (numero == 0 || numero == 1) {
        return 0;
    }

    for (i = 2; i < numero; i++){
        if (numero % i == 0) {
            return 0;
            break;
        }        
    }

    return 1;
}