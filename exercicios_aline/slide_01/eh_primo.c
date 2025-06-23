#include <stdio.h>

int eh_primo(int numero);

int main()
{
    int numero;

    printf("Digite um número para descobrir se ele é primo: \n");
    scanf("%i", &numero);

    char resposta = eh_primo(numero);

    if (resposta == 1) {
        printf("O número %i é primo! \n", numero);
    } else {
        printf("O número %i não é primo \n", numero);
    }

    return 0;
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