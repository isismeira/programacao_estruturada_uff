#include <stdio.h>

int fibonacci(int n);

int main()
{
    int termo = 7;
    int resultado = fibonacci(termo);
    printf("%i", resultado);
}

int fibonacci(int n)
{
    if (n < 2) {
        return 1;
    } else {   
        return fibonacci(n-1) + fibonacci(n-2);
    } 
}