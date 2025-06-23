#include <stdio.h>
#include <math.h>

void calcula_raizes(int a, int b, int c);

int main()
{
    int a, b, c;
    printf("Digite aqui um valores para a, b e c: ");
    scanf("%i %i %i", &a, &b, &c);

    
    calcula_raizes(a, b, c);

    return 0;
}

void calcula_raizes(int a, int b, int c)
{
    int raiz_1 = ((-b) + sqrt((b * b) - (4 * a * c)))/(2*a);
    int raiz_2 = ((-b) - sqrt((b * b) - (4 * a * c)))/(2*a);
    
    printf("As raizes sao: %i e %i", raiz_1, raiz_2);
}