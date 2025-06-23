#include <stdio.h>

int catalan(int n);

int main()
{
    int n;
    scanf("%i", &n);
    printf("O %i-esimo termo de Catalan e %i", n, catalan(n));
    return 0;
}

int catalan(int n) {
    if (n == 0)
        return 1;
    else
        return (2 * (2 * n - 1) * catalan(n - 1)) / (n + 1);
}
