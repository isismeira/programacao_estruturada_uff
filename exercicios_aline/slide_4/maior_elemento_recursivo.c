#include <stdio.h>

int maxr (int v[], int n);

int main()
{
    int v[] = {3,55,7,8,3,2};
    int n = sizeof(v) / sizeof(v[0]);
    int resposta = maxr(v, n);
    printf("Maior termo de v: %i", resposta);
}

int maxr (int v[], int n) {
    if (n == 1) { 
        return v[0];
    } else {
        int x;
        x = maxr(v, n-1);
        if (x > v[n-1]) {
            return x;
        } else {
            return v[n-1];
        } }
}        