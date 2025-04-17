#include <stdio.h>

int busca_binaria(int alvo, int tamanho, int vetor[]);
int busca_binaria_recursiva(int alvo, int inicio, int fim, int vetor[]);

int main() {
    int vetor[] = {1, 3, 5, 7, 9, 11};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int numero;
    printf("Digite o numero que deseja buscar: ");
    scanf("%d", &numero);

    int resultado = busca_binaria(numero, tamanho, vetor);

    printf("Indice: %d\n", resultado);

    return 0;
}

// Função principal de busca binária (chamada externa)
int busca_binaria(int alvo, int tamanho, int vetor[]) {
    return busca_binaria_recursiva(alvo, 0, tamanho - 1, vetor);
}

// Função de busca binária recursiva
int busca_binaria_recursiva(int alvo, int inicio, int fim, int vetor[]) {
    if (inicio > fim) {
        // Retorna a posição onde o valor deveria estar
        return fim + 1;
    } else {
        int meio = (inicio + fim) / 2;
        printf("meio: %i", meio);
        if (vetor[meio] < alvo)
            return busca_binaria_recursiva(alvo, meio + 1, fim, vetor);
        else
            return busca_binaria_recursiva(alvo, inicio, meio - 1, vetor);
    }
}
