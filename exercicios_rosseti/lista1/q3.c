#include <stdio.h>

int main()
{
    int h1, m1, h2, m2;
    while(scanf("%i %i %i %i", &h1, &m1, &h2, &m2) !=  EOF) {
        if (h1 == 0 && h2 == 0 && m1 == 0 && m2 == 0) {
            break;
        } else {
            // Converter horas e minutos para minutos totais 
            int inicio = h1 * 60 + m1;
            int fim = h2 * 60 +m2;

            // Calcular diferença, considerando a virada do dia
            int resultado = fim - inicio;
            if (resultado < 0) {
                resultado += 24*60; // !!!!!
            }
            printf("%d\n", resultado);
        }
    }
    return 0;
}