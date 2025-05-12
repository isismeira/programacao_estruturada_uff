#include <stdio.h>

void ler_vetor(int *vetor, int n);

void maior_menor(int *vetor, int *vetor_maior_menor, int n);

int main()
{
    int n;
    printf("Digite o numero de elementos que o vetor vai ter: ");
    scanf("%d", &n);

    int vetor[n];
    ler_vetor(vetor, n);

    int vetor_maior_menor[2];
    maior_menor(vetor, vetor_maior_menor, n);

    printf("Maior: %d Menor: %d", vetor_maior_menor[0], vetor_maior_menor[1]);
}

void ler_vetor(int *vetor, int n)
{
    for (int i = 0; i < n; i++) {
        printf("Digite o valor do elemento %d: ", i);
        scanf("%d", (vetor + i)) ;
    }
}

void maior_menor(int *vetor, int *vetor_maior_menor, int n)
{
   int maior = *(vetor), menor = *(vetor);

   for (int i = 0; i < n; i++) {
        if (*(vetor + i) <= menor) {
            menor = *(vetor + i);
        }
        else if (*(vetor + i) >= maior) {
            maior = *(vetor + i);
        }                
   }
   *(vetor_maior_menor) = maior;
   *(vetor_maior_menor + 1) = menor;
}    