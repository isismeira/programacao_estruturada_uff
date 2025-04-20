#include <stdio.h>

int comm(int n, int k);

int main()
{
    int n, k;
    scanf("%i %i", &n, &k);
    int resultado = comm(n,k);
    printf("Numero de comites = %i", resultado);
    return 0;
}

int comm(int n, int k){
	if (k > n)
		return 0;
	if ((k == 1) || (n == 1))
		return n;
	return comm(n-1,k) + comm(n-1,k-1);
}