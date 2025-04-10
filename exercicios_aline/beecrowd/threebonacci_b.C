#include <stdio.h>
#include <stdlib.h>

#define MAX_FIB 1000000000
#define MAX_FIB_TERMS 50

int eh_multiplo_3(int n), tem_digito_3(int n), threebonacci(int n), busca_binaria(int n);
void gerar_fibonacci();
int fibonacci[MAX_FIB_TERMS];
int total_fib = 0;

int main() {
    gerar_fibonacci();
    int n;
    while (scanf("%i", &n) != EOF) {
        printf("%i\n", threebonacci(n));
    }
    return 0;
}

void gerar_fibonacci() {
    int a = 1, b = 1;
    fibonacci[0] = a;
    fibonacci[1] = b;
    total_fib = 2;
    while (1) {
        int c = a + b;
        if (c > MAX_FIB) break;
        fibonacci[total_fib++] = c;
        a = b;
        b = c;
    }
}

int busca_binaria(int n) {
    int inicio = 0, fim = total_fib - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (fibonacci[meio] == n) return 1;
        else if (fibonacci[meio] < n) inicio = meio + 1;
        else fim = meio - 1;
    }
    return 0;
}

int threebonacci(int n) {
    int numero_atual = 3;
    int contador_termos = 0;

    while (contador_termos < n) {
        if (busca_binaria(numero_atual)) {
            if (eh_multiplo_3(numero_atual) || tem_digito_3(numero_atual)) {
                contador_termos++;
            }
        }
        numero_atual++;
    }

    return numero_atual - 1;
}

int eh_multiplo_3(int n) {
    return n % 3 == 0;
}

int tem_digito_3(int n) {
    while (n > 0) {
        if (n % 10 == 3) return 1;
        n /= 10;
    }
    return 0;
}
