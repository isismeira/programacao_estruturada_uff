#include <stdio.h>

/*
    r = an - an-1
    an = a1 + (n-1)r
    sn = (a1 + an)n / 2 
*/

int soma_pa(int a1, int razao, int n);

int main()
{
    int a1, razao, n;
    printf("Digite o primeiro termo, a razão e o numero de termos: ");
    scanf("%i %i %i", &a1, &razao, &n);
    printf("A soma da P.A. eh: %i", soma_pa(a1,razao,n));
}

int soma_pa(int a1, int razao, int n)
{
    int soma_pa = ((a1 + (a1 + ((n-1)*razao))) * n)/2;
    return soma_pa;
}