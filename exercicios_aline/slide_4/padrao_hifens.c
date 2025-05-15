#include <stdio.h>
#include <math.h>

void recursao(int *vetor, int inicio, int fim, int n);
void imprimir_desenho(int *vetor,int tam_vetor);

int main()
{
    int n;
    printf("Digite o valor de n: ");
    scanf("%i", &n);

    int tam_vetor = (int)pow(2, n) - 2;

    /*
    int vetor[tam_vetor] = {0};

    int inicio = 0;
    int fim = tam_vetor - 1;
    
    recursao(vetor, inicio, fim, n);
    imprimir_desenho(vetor, tam_vetor);  */
}
    
void recursao(int *vetor, int inicio, int fim, int n)
{
    if (n <= 0 || inicio > fim) {
        return;
    }
    int meio = (inicio + fim) / 2;
    vetor[meio] = n; /* a cada chamada de recursão, o correspondente ao meio no vetor de zeros 
    receberá um valor inteiro que corresponde ao número de hifens que aquela posição vai ter na hora da impressão */
    recursao(vetor, inicio, meio - 1, n - 1);
    recursao(vetor, meio + 1, fim, n - 1);
}

// Aqui, o vetor de inteiros será percorrido, seu valor em cada indice corresponde a quantidade de "-" que será exibido naquela linha
void imprimir_desenho(int *vetor, int tam_vetor) {
    for (int i = 0; i < tam_vetor; i++) {
        for (int j = 0; j < vetor[i]; j++) {
            printf("-");
        }
        printf("\n");
    }

}