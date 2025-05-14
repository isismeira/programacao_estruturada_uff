#include <stdio.h>
#include <string.h> // para manipular strings
#include <stdlib.h> // essas duas bibliotecas vão servir para o sorteio de uma palavra
#include <time.h>

int forca(char **palavras, int numero_de_palavras);

int main()
{
    FILE *entrada = fopen("C:/Users/Isis/Desktop/teste/entrada.txt", "r");
    FILE *saida = fopen("C:/Users/Isis/Desktop/teste/saida.txt", "w");

    char *palavras[20]; // arrays de ponteiros para strings
    char linha[100];

    int i = 0;
    while (fgets(linha, sizeof(linha), entrada) != NULL ) {
        linha[strcspn(linha, "\n")] = '\0'; //!!!
        palavras[i] = strdup(linha); //!!!
        i++;
    }

    int numero_de_palavras = i;

    if (forca(palavras, numero_de_palavras)) {
        printf("Você ganhou o jogo!");
    } else {
        printf("Você perdeu o jogo");
    }

    fclose(saida);
    fclose(entrada);
    return 0; 
}

int forca(char **palavras, int numero_de_palavras)
{
    srand(time(NULL));
    int numero_sorteado = rand() % numero_de_palavras;
    char palavra_sorteada[100];
    strcpy(palavra_sorteada, palavras[numero_sorteado]); //!!!

    // !!! - inicializo uma string de flags    
    int tamanho = strlen(palavra_sorteada);
    int acertou[tamanho];
    for (int i = 0; i < tamanho; i++) acertou[i] = 0;

    int num_tentativas = 6;
    
    while (num_tentativas > 0) {
        char letra;
        int tem_a_letra = 0;
        printf("Escolha uma letra: ");
        scanf(" %c", &letra);

        for (int i = 0; palavra_sorteada[i] != '\0'; i++) {
            if (palavra_sorteada[i] == letra) {
                tem_a_letra = 1;
                acertou[i] = 1; /// !!!
            }
        }

        if (tem_a_letra) {
            printf("%c esta presente na palavra \n", letra); 
        } else {
            printf("%c nao está presente na palavra \n", letra);
        }

        num_tentativas--;
    }

    for (int i = 0; i < tamanho; i++) {
        if (acertou[i] != 1) {
            return 0;
            break;
    }}

    return 1;
}