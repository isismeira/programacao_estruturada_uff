#include <stdio.h>
#include "vetor.h"

int main() {
    // 1. Criação do vetor
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    Vetor* meu_vetor = cria_vetor(tamanho);
    printf("Vetor criado com tamanho %d.\n", tamanho);

    // 2. Preenchimento do vetor
    float valores[tamanho];
    printf("\nDigite os %d valores do vetor (separados por espaço): ", tamanho);
    for (int i = 0; i < tamanho; i++) {
        scanf("%f", &valores[i]);
    }
    
    preenche_vetor(meu_vetor, valores);
    printf("Vetor preenchido com sucesso.\n");

    // 3. Acesso a elementos
    int posicao;
    float valor;
    printf("\nDigite uma posição para acessar (0 a %d): ", tamanho-1);
    scanf("%d", &posicao);
    acessa_vetor(meu_vetor, posicao, &valor);
    printf("Valor na posição %d: %.2f\n", posicao, valor);

    // 4. Atribuição de valor
    printf("\nDigite uma posição para modificar (0 a %d): ", tamanho-1);
    scanf("%d", &posicao);
    printf("Digite o novo valor: ");
    scanf("%f", &valor);
    atribui_vetor(meu_vetor, posicao, valor);
    printf("Valor modificado com sucesso.\n");

    // 5. Soma cumulativa
    soma_vetor(meu_vetor);
    printf("\nSoma cumulativa aplicada ao vetor.\n");

    // 6. Menor e maior elemento
    printf("\nMenor elemento do vetor: %.2f\n", menor_elemento_vetor(meu_vetor));
    printf("Maior elemento do vetor: %.2f\n", maior_elemento_vetor(meu_vetor));

    // 7. Busca de elemento
    printf("\nDigite um valor para buscar no vetor: ");
    scanf("%f", &valor);
    int encontrado = vetor_busca(meu_vetor, valor);
    if (encontrado != -1) {
        printf("Valor %.2f encontrado na posição %d\n", valor, encontrado);
    } else {
        printf("Valor %.2f não encontrado no vetor\n", valor);
    }

    // 8. Liberação de memória
    libera_vetor(meu_vetor);
    printf("\nMemória do vetor liberada.\n");

    return 0;
}