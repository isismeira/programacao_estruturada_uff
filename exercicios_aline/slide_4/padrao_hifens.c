#include <stdio.h>
#include <math.h>

void recursao(int n, int l, int r);
void imprimir_desenho(int n);

int main()
{
    int n;
    printf("Digite o valor de n: ");
    scanf("%i", &n);

    int n_linhas = (int)pow(2, n) - 2;

    int l = 0;
    int r = n_linhas - 1;
    
    recursao(n, l, r);
}
    
void recursao(int n, int l, int r)
{
    if (n <= 0 || l > r) {
        return;
    }
    int m = (l + r)/2;
    recursao(n-1, l, m);
    imprimir_desenho(n);
    recursao(n-1, m, r);
}

void imprimir_desenho(int n) {
    for (int i = 0; i < n; i++) {
        printf("-");
    }
    printf("\n");
}