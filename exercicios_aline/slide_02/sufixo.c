#include <stdio.h>

int sufixo(int a, int b);

int main()
{
    int a, b;

    printf("Digite aqui dois números a e b, e verificarei se b é sufixo de a");
    scanf("%i %i", &a, &b);

    int resultado = sufixo(a, b);
    if (resultado) {
        printf("%i eh sufixo de %i", b, a);
    } else {
        printf("%i nao eh sufixo de %i", b, a);
    }

    return 0;
}

int sufixo(int a, int b)
{
    while (b > 0) {
        int ultimo_digito_b = b % 10;
        int ultimo_digito_a = a % 10;

        if (ultimo_digito_b != ultimo_digito_a) {
            return 0;
            break;
        }

        b /= 10;
        a /= 10;
    }
    return 1;
}