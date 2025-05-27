#include <stdio.h>
#include <string.h>

int main() {
    char frase[6][10] = {"Eu", "quero", "justificar", "esse", "texto", "aqui"};
    int colunas = 10;
    int num_palavras = 6;

    char linha[100] = "";
    int tam_linha = 0;

    for (int i = 0; i < num_palavras; i++) {
        int tam_palavra = strlen(frase[i]);

        // Verifica se cabe na linha atual (com espaço se necessário)
        if (tam_linha + tam_palavra + (tam_linha > 0 ? 1 : 0) > colunas) {
            printf("%s\n", linha);
            linha[0] = '\0';
            tam_linha = 0;
        }

        // Adiciona espaço se não for a primeira palavra da linha
        if (tam_linha > 0) {
            strcat(linha, " ");
            tam_linha++;
        }

        strcat(linha, frase[i]);
        tam_linha += tam_palavra;
    }

    // Imprime última linha se sobrar algo
    if (tam_linha > 0) {
        printf("%s\n", linha);
    }

    return 0;
}
