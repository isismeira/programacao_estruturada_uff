#include <stdio.h>

/*
    (vetor + i) => &vetor[i]
    *(vetor + i) => vetor[i]
*/

void ler_vetor(int *vetor, int n);

int procurar_elemento(int *vetor, int **vetor_enderecos, int n, int x);

void print_enderecos(int **vetor_enderecos, int j);

int main()
{   
    int n; 
    printf("Quantos elementos?: ");
    scanf("%i", &n);

    int vetor[n];
    ler_vetor(vetor, n);

    int x;
    printf("Está procurando por quem?");
    scanf("%i", &x);

    int *vetor_enderecos[n]; // vetor de ponteiros para inteiros
    int qtdd_indices = procurar_elemento(vetor, vetor_enderecos, n, x);

    print_enderecos(vetor_enderecos, qtdd_indices);
}

void ler_vetor(int *vetor, int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o elemento da posição %i: ", i);
        scanf("%i", (vetor+i));   // não precisa de & pois (vetor + i) ja é o endereço   
    }
}

int procurar_elemento(int *vetor, int **vetor_enderecos, int n, int x)
{
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (*(vetor+i) == x) { 
            *(vetor_enderecos + j) = (vetor +i);
            j++;
        }
    }
    return j;
}

void print_enderecos(int **vetor_enderecos, int j)
{
    for (int i = 0; i < j; i++) {
        printf("%p\n", *(vetor_enderecos + i));
    }     
}
