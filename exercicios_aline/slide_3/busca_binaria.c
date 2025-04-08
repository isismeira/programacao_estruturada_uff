#include <stdio.h>

int busca_binaria(int termo, int vetor[], int tamanho);

int main()
{
    int termo;
    int vetor[] = {2, 4, 5, 23, 45, 60, 77, 80, 81, 100};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Digite aqui um elemento do vetor para retornar a posicao onde ele esta: ");
    scanf("%i", &termo);

    int resultado = busca_binaria(termo, vetor, tamanho);

    if (resultado != -1)
        printf("O elemento %i está na posicao %i\n", termo, resultado);
    else
        printf("Elemento %i não encontrado no vetor.\n", termo);

    return 0;
}

int busca_binaria(int termo, int vetor[], int tamanho)
{
    int baixo = 0;
    int alto = tamanho - 1;

    while (baixo <= alto) {
        int meio = (baixo + alto) / 2;
        int chute = vetor[meio];

        if (chute == termo) {
            return meio;
        } else if (chute > termo) {
            alto = meio - 1;
        } else {
            baixo = meio + 1;
        }
    }

    return -1; // elemento não encontrado
}