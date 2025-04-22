#include <stdio.h>

int fatorial_duplo(int n);

int main()
{
    int n;
    scanf("%i", &n);
    printf("%i!! = %i", n, fatorial_duplo(n));
}

int fatorial_duplo(int n)
{
    if (n == 1) {
        return 1;
    } else {
        return n * fatorial_duplo(n - 2);
    }
}