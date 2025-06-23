#include <stdio.h>

int superfatorial(int n);
int fatorial(int n);

int main()
{
    int n;
    scanf("%i", &n);
    printf("O superfatorial de %i eh %i", n, superfatorial(n));
}

int superfatorial(int n)
{
    if (n == 1) {
        return 1;
    } else {
        return fatorial(n) * superfatorial(n-1);
    }
}

int fatorial(int n) 
{
    if (n == 1) {
        return 1;
    } else {
        return n * fatorial(n-1);
    }
}