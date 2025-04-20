#include <stdio.h>

int somatorio(int n);

int main()
{
    int n;
    scanf("%i", &n);
    printf("O somatorio dos numero de 1 ate %i = %i", n, somatorio(n));
}

int somatorio(int n)
{
    if (n == 0) {
        return 0;
    } else {
        return n + somatorio(n-1);
    }
}