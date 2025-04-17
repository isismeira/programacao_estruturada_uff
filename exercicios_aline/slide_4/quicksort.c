#include <stdio.h>

void troca(int array[], int a, int b);
int particao(int array[], int inicio, int fim);
void quicksort(int array[], int inicio, int fim);

// Função principal
int main() {
    int array[] = {8, 3, 1, 7, 0, 10, 2};
    int len = sizeof(array) / sizeof(array[0]);

    quicksort(array, 0, len - 1);

    printf("Ordenacao por quicksort: \n");
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

// Função Quicksort recursiva
void quicksort(int array[], int inicio, int fim) {
    if (inicio< fim) {
        int indicePivo = particao(array, inicio, fim);
        quicksort(array, inicio, indicePivo - 1);  // Lado esquerdo
        quicksort(array, indicePivo + 1, fim);    // Lado direito
    }
}

// Função de partição (estilo Lomuto)
int particao(int array[], int inicio, int fim) {
    int pivo = array[fim];  // O pivô é sempre o último elemento
    int indicePivo = inicio;

    for (int i = inicio; i < fim; i++) {
        if (array[i] < pivo) {
            troca(array, i, indicePivo);
            indicePivo++;
        }
    }

    troca(array, indicePivo, fim);  // Coloca o pivô na posição correta
    return indicePivo;
}

void troca(int array[], int a, int b) {
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}
