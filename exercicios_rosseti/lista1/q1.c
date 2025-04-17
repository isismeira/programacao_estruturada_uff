#include <stdio.h>

void primeiros_primos(int n);
int eh_primo(int n);

int main()
{
    int n;
    while(scanf("%i", &n) !=  EOF) {
        if (n == 0 || n < 0) {
            break;
        }
        primeiros_primos(n);
    }
    return 0;
}

void primeiros_primos(int n) 
{
    int primos[n];

    int contador = 0;
    int numero_atual = 2;
    while (contador < n) {
        if (eh_primo(numero_atual)) {
            primos[contador] = numero_atual;
            contador++;
        }
        numero_atual++;
    }

    printf("%i primeiros numeros primos: ",n);
    for (int i = 0; i < n; i++) {
        printf("%i ", primos[i]);
    } 
}

int eh_primo(int n)
{
    if (n == 2) {
        return 1;
    } else {
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                return 0;
                break;
            }
        }
    }
    return 1;
}