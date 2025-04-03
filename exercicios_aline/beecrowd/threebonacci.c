#include <stdio.h>

int threebonacci(int numero);
int tem_digito_tres(int numero);

int main()
{
    int numero;

    while(scanf("%i", &numero) != EOF) {
        int resultado = threebonacci(numero);
        printf("%i\n", resultado);
    }

    return 0;
}

int threebonacci(int numero)
{   
    int numero_a = 1;
    int numero_b = 1;
    int threebonacci = 0;

    while (threebonacci < 3) {
        for (int i = 1; i <= 100000; i++) {
            int prox_num = numero_a + numero_b;
            if (tem_digito_tres(prox_num) || (i%3 == 0)) {
                threebonacci++;
            }
            numero_a = numero_b;
            numero_b = prox_num;
        }
    }

    return(numero_b);
}

int tem_digito_tres(int numero){
    while (numero > 0) {
        int ultimo_digito = numero % 10;
        if (ultimo_digito == 3) {
            return 1;
            break;
        }
        numero = numero / 10;
    }
    return 0;
}