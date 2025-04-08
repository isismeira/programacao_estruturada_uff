#include <stdio.h>

int contadigitos(int n, int d);

int main()
{
    int n;
    int d;

    printf("Digite um inteiro: ");
    scanf("%i", &n);

    printf("Escreva um digito d para ver quantas vezes ele aparece em %i: ", n);
    scanf("%i", &d);

    int resultado = contadigitos(n, d);
    printf("O digito %i aparece %i vezes no numero %i", d, resultado, n);
}

int contadigitos(int n,int d)
{
    int contador = 0;
    while (n > 0) {
        int ultimo_digito = n % 10;
        if (ultimo_digito == d){
            contador++;
        }
        n /= 10;
    }
    return contador;
}