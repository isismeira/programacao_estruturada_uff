#include <stdio.h>

void soma_impares(int numero);

int main()
{
    int m;
    int i;
    printf("Digite o valor de m: ");
    scanf("%i", &m);

    for (i = 1; i <= m; i++) {
        soma_impares(i);
    }

    return 0;
}

void soma_impares(int numero){
    int primeiro_impar = (numero*numero) - numero + 1;
    int cubo = (numero*numero*numero);
    int soma = primeiro_impar;
    int numero_atual = primeiro_impar;

    printf("%i^3 : %i ", numero, primeiro_impar);

    for (int i = 1; i < numero; i++) {
        numero_atual += 2;
        printf("+ %i ", numero_atual);
        soma += numero_atual;
    } 

    printf("= %i \n", cubo);
}