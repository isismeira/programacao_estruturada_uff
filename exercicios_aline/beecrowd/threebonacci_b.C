#include <stdio.h>
#include <string.h>

int contem_tres(long long num); 

int main() {
    long long fib[100]; // Armazenar a sequência de Fibonacci
    long long threebonacci[61]; // Armazenar os 60 termos válidos
    int count = 0;

    // Inicializa os dois primeiros termos da sequência de Fibonacci
    fib[0] = 0;
    fib[1] = 1;

    // Índice para a sequência de Fibonacci
    int i = 2;

    // Gera Fibonacci e verifica os critérios até encontrar 60 termos válidos
    while (count < 60) {
        fib[i] = fib[i - 1] + fib[i - 2];

        if (fib[i] % 3 == 0 || contem_tres(fib[i])) {
            count++;
            threebonacci[count] = fib[i];
        }

        i++;
    }

    int n;
    // Lê até o final do arquivo
    while (scanf("%d", &n) != EOF) {
        printf("%lld\n", threebonacci[n]);
    }

    return 0;
}

int contem_tres(long long num) {
    while (num > 0) {
        if (num % 10 == 3)
            return 1;
        num /= 10;
    }
    return 0;
}