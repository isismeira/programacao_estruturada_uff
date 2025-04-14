#include <stdio.h>

// Não usar pow de <math.h>, pois ele pode gerar erro de arredondamento ao ser convertido para int

void resultado(int n);
int retorna_dois_ultimos(int n);
int retorna_dois_primeiros(int n);
int concatenacao(int dois_ultimos, int dois_primeiros);

int main()
{
    int n;
    printf("Escreva aqui um numero inteiro: ");
    scanf("%i", &n);

    resultado(n);
    
    return 0;
}

void resultado(int n) 
{
    int dois_ultimos = retorna_dois_ultimos(n);
    int dois_primeiros = retorna_dois_primeiros(n);
    int concatena = concatenacao(dois_ultimos, dois_primeiros); // não dar o nome da variável igual a de uma função
    int potencia = (dois_primeiros + dois_ultimos) * (dois_primeiros + dois_ultimos);
    printf("(%i+%i)^2 = %i\n", dois_primeiros, dois_ultimos, potencia);
    if (potencia == concatena) {
        printf("A propriedade e valida");
    } else {
        printf("A propriedade nao e valida");
    }
}

int retorna_dois_ultimos(int n)
{
    int dois_ultimos = 0;
    int contador = 0;
    while (contador < 2){
        if (contador == 0) {
            int ultimo_digito = n % 10;
            dois_ultimos += ultimo_digito;
            n /= 10;
            contador++;
        }
        if (contador == 1) {
            int ultimo_digito = n % 10;
            dois_ultimos += (10 * ultimo_digito);
            n /= 10;
            contador++;
        }
    }
    return dois_ultimos;
}

int retorna_dois_primeiros(int n) 
{
    int dois_primeiros = 0;
    while (n > 0){
        if (n <= 99 && n >= 10) {
            int ultimo_digito = n % 10;
            dois_primeiros += ultimo_digito;
        }
        if (n <= 9 && n >= 1) {
            int ultimo_digito = n % 10;
            dois_primeiros += (ultimo_digito * 10);
        }
        n /= 10;
    }
    return dois_primeiros;
}

int concatenacao(int dois_ultimos, int dois_primeiros) 
{
    int digito_0 = ((dois_primeiros / 10) % 10);
    int digito_1 = (dois_primeiros % 10);
    int digito_2 = ((dois_ultimos / 10) % 10);
    int digito_3 = ((dois_ultimos % 10));

    int concatenacao = (digito_0 * 1000) + (digito_1 * 100) + (digito_2 * 10) + digito_3;

    return concatenacao;
}