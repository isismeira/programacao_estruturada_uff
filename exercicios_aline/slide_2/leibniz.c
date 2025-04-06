#include <stdio.h>
#include <math.h>

float calcula_leibniz(int termos);

int main()
{
    int termos;

    printf("Digite o numero de termos para calcular a serie de Leibniz");
    scanf("%i", &termos);

    float resultado = calcula_leibniz(termos);
    printf("O resultado para a série de Leibniz para %i termos eh %f", termos, resultado);
}

float calcula_leibniz(int termos)
{
    float somatorio = 0;
    for (int i = 0; i < termos; i++){
        somatorio += (pow(-1, i))/(2*i+1);
    }
    float resultado = (somatorio) * 4;
    return resultado;
}