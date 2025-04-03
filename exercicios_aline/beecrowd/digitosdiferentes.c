#include <stdio.h>

int n_tem_digito_repetido(int numero);

int main()
{
    int n, m;

    while(scanf("%i %i", &n, &m) !=  EOF){
        int casas_possiveis = 0;

        for (int i = n; i <= m; i++) {
            if(n_tem_digito_repetido(i)){
                casas_possiveis++;
            }
        }

        printf("%i\n", casas_possiveis);
    }

}

int n_tem_digito_repetido(int numero)
{
    int digitos_usados[10] = {0};

    while (numero > 0) {
        int digito_atual = numero % 10;
        if (digitos_usados[digito_atual]) {
            return 0;
            break;
        }
        digitos_usados[digito_atual] = 1;
        numero = numero/10;
    }

    return 1;
}