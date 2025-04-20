#include <stdio.h>

int digitos(int n, int digito);

int main()
{
    int n, digito;
    scanf("%i %i", &n, &digito);
    printf("O digito %i aparece %i vezes em %i", digito, digitos(n,digito), n);
}

int digitos(int n, int digito)
{
    if (n == 0)
        return 0;
    else
        return (n % 10 == digito) + digitos(n / 10, digito);
}