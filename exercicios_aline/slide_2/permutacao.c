#include <stdio.h>

int contadigitos(int n, int d);
int eh_permutacao(int a, int b);

int main()
{
    int a;
    int b;

    printf("Digite dois inteiros(a e b): ");
    scanf("%i %i", &a, &b);

    int resultado = eh_permutacao(a, b);
    if (resultado) {
        printf("%i eh permutacao de %i", b, a);
    } else {
        printf("%i nao eh permutacao de %i", b, a);
    }
}

int eh_permutacao(int a, int b){
    // Para cada um dos dez dígitos possíveis...
    for (int i=0; i <= 9; i++){
        if (contadigitos(a, i) != contadigitos(b,i)){ // ....se a contagem de um digito "i" for diferente para a e b...
            return 0; // ...b não é permutação de a!
            break;
        } 
    }
    return 1;
}

int contadigitos(int n,int d)
{
    int contador = 0;
    while (n > 0) {
        int ultimo_digito = n % 10;
        if (ultimo_digito == d){
            contador++;
        }
        n /= 10;
    }
    return contador;
}