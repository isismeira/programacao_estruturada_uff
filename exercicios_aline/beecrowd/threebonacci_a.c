#include <stdio.h>

// Essa versão é correta, mas dá time limit exceeded em jurados online

int threebonacci(int n), eh_fibonacci(int n), eh_multiplo_3(int n), tem_digito_3(int n);

int main()
{
    int n;
    while(scanf("%i", &n) !=  EOF) {
        printf("%i\n", threebonacci(n));
    }
    return 0;
}

int threebonacci(int n)
{
    int numero_atual= 3;
    int contador_termos = 0;

    while (contador_termos < n) {
        if (eh_fibonacci(numero_atual)){
            if (eh_multiplo_3(numero_atual) || tem_digito_3(numero_atual)) {
                contador_termos++;
            }
        }
        numero_atual++;
    }

    return (numero_atual - 1);
}

int eh_fibonacci(int n) 
{
    int termo_a = 1;
    int termo_b = 1;

    while (termo_b < n) {
        int prox_num = termo_a + termo_b;
        termo_a = termo_b;
        termo_b = prox_num;
    }

    if (termo_b == n) {
        return 1;
    }
    return 0;
}

int eh_multiplo_3(int n)
{
    if (n % 3 == 0){
        return 1;
    }
    return 0;
}

int tem_digito_3(int n)
{
    while (n > 0) {
        int ultimo_digito = n % 10;
        if (ultimo_digito == 3){
            return 1;
            break;
        }
        n /= 10;
    }
    return 0;
}