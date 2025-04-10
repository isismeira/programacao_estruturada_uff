#include <stdio.h>
#include <math.h>

/* Números como 100^100 são gigantescos (com mais de 199 dígitos), e não cabe
 em um int (nem em long long int). Isso causa comportamento indefinido
ou resultados errados, como zero. Pra resolver problemas com numeros grandes,
olhar a resulução desse problema com logaritmos */

int conta_digitos(int potencia);

int main()
{
    int testes;
    scanf("%i", &testes);
    for (int i = 0; i < testes; i++){
        int base, expoente;
        scanf("%i %i", &base, &expoente);
        printf("%i\n", conta_digitos(pow(base, expoente)));
    }
    return 0;
}

int conta_digitos(int potencia)
{   
    int contador = 0;
    while (potencia > 0) {
        contador++;
        potencia /= 10;
    }
    return contador;
}