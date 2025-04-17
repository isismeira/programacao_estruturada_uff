#include <stdio.h>
#include <stdlib.h>

void quicksort(int *vetor, int inicio, int fim);
int particiona(int *vetor, int inicio, int fim);

int main()
{
    int vetor[8] = {22, 45, 13, 30, 37, 34, 48, 20};
    int len = sizeof(vetor)/sizeof(vetor[0]);

    quicksort(vetor, 0, len - 1);

    for (int i = 0; i < len; i++) {
        printf("%i ", vetor[i]);
    }
}

void quicksort(int *vetor, int inicio, int fim)
{
    if (inicio < fim) {
        int posicao = particiona(vetor, inicio, fim); // retorna o indice do meio, o elemento que está na posição correta
        quicksort(vetor, inicio, posicao - 1); // chama recursivamente a parte a esquerda do pivô (inicio - meio)
        quicksort(vetor, posicao, fim); // chama recursivamente a parte a direita do pivô (meio - fim)
    }
}

/* Vai colocar um elemento na posição correta (pivô), 
onde todos os elementos a sua esquerda serão menores que ele, e a direita, maiores */
int particiona(int *vetor, int inicio, int fim) 
{
    int pivo = (vetor[inicio] + vetor[fim] + vetor[(inicio+fim)/2]) / 3;

    while (inicio < fim) { // enquanto os elementos i e f não se "cruzarem"  
        while (inicio < fim && vetor[inicio] <= pivo) // percorre o vetor da esquerda para o meio, procurando o maior
            inicio += 1; 
        while (inicio < fim && vetor[fim] > pivo) // percorre o vetor da direita para o meio, procurando o menor
            fim -= 1; 
        
        // Realiza a troca entre os elementos
        int temp = vetor[inicio]; 
        vetor[inicio] = vetor[fim];
        vetor[fim] = temp;    
    }

    return inicio; // obs. aqui, inicio = fim
}