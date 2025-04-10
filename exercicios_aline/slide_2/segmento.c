#include <stdio.h>

int eh_segmento(int a, int b);
int verificador_sufixo(int a, int b);

int main()
{
    int a, b;

    printf("Digite dois numeros a e b: \n");
    scanf("%i %i", &a, &b);

    int resposta = eh_segmento(a,b);

    if (resposta) {
        printf("%i eh segmento de %i", b, a);
    } else {
        printf("%i nao eh segmento de %i", b, a);
    }

    return 0;
}

/*
    A lógica desse programa é simples.
    A função "eh_segmento" vai cortando sempre o último digito de a.
    A cada vez que a é cortado, chama-se uma função para verificar se b é sufixo de a
    Caso b seja sufixo de a, a função retorna true e para o loop. Caso contrário, continua "cortando" a
*/

int eh_segmento(int a, int b) {
    int ultimo_digito_b = b % 10;

    while (a > 0) {
        int ultimo_digito_a = a % 10;
        if (ultimo_digito_a == ultimo_digito_b) {
            int resposta = verificador_sufixo(a, b);
            if (resposta) {
                return 1;
                break;
            }
        }
        a /= 10;
    }

    return 0;
}

int verificador_sufixo(int a, int b)
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