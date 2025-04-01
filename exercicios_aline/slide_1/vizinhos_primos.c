#include <stdio.h>

void vizinhos_primos(int numero);

int main()
{
    int numero;
    
    printf("Digite aqui um numero primo e iremos dizer os 2 numeros primos anteriores e os 2 numeros primos sucessores: ");
    scanf("%i", &numero);

    vizinhos_primos(numero);
}


void vizinhos_primos(int numero)
{
    int primo_antecessor_a = 0;
    int primo_antecessor_b = 0;
    int primo_sucessor_b = 0;
    int primo_sucessor_a = 0;

    // Antecessores
    for (int i = numero; i >= 1; i--){
        if (eh_primo(i) && primo_antecessor_b == 0) {
            primo_antecessor_b = i;
        }
        if (eh_primo(i) && primo_antecessor_b != 0){
            primo_antecessor_a = i;
            break;
        }
    }

    // Sucessores
    for (int i = numero; i <= i*i; i++){
        if (eh_primo(i) && primo_antecessor_b == 0) {
            primo_sucessor_b = i;
        }
        if (eh_primo(i) && primo_antecessor_b != 0){
            primo_sucessor_a = i;
            break;
        }
    }

    printf("%i %i %i %i", primo_antecessor_a, primo_antecessor_b, primo_sucessor_b, primo_sucessor_a);
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