#include <stdio.h>

int main()
{
    int entrada;
    int anos;
    int meses;
    int dias;

    scanf("%i", &entrada);

    anos = entrada / 365;
    entrada = entrada - (anos * 365);
    meses = entrada / 30;
    entrada = entrada - (meses * 30);
    dias = entrada;

    printf("%i ano(s)\n%i mes(es)\n%i dia(s)", anos, meses, dias);

    return 0;
}