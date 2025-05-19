#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *entrada, *saida;
    if (argc < 3) {
        printf("Insira os nomes dos arquivos!");
        return 0;
    }
    entrada = fopen(argv[1], "r");
    saida = fopen(argv[2], "w");
    
    int contador = 0;
    char palavras_unicas[1000][100];
    int repeticoes[1000] = {0};

    while(1) {
        char palavra[100];

        if (fscanf(entrada, " %[^ ]", palavra) != 1) break;

        if (contador > 0) {
            int eh_palavra_unica = 1;
            for (int i = 0; i < contador; i++) {
                if (strcmp(palavra, palavras_unicas[i]) == 0) {
                    eh_palavra_unica = 0;
                    repeticoes[i]++;
                    break;
                }
            }
            if (eh_palavra_unica) {
                strcpy(palavras_unicas[contador], palavra);
                repeticoes[contador] = 1;
            }
        } else {
            strcpy(palavras_unicas[contador], palavra);
            repeticoes[contador]++;
        }

        contador++;
    }

    for (int i = 0; i < contador; i++) {
        fprintf(saida, "%s: %i vezes\n", palavras_unicas[i], repeticoes[i]);
    }

    fclose(entrada);
    fclose(saida);
}    
