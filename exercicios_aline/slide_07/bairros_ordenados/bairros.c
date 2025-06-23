#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* entrada = fopen("C:/Users/Isis/Documents/prog_estruturada_uff/exercicios_aline/slide_7/bairros_ordenados/entrada.txt", "r");
    if (!entrada) {
        perror("Erro ao abrir entrada.txt");
        return 1;
    }

    // Declaração de arrays e variáveis
    int totalPessoas = 0;
    int totalBairros = 0;

    char nomes[1000][100];
    int idades[1000];
    char bairros[1000][100];

    char bairrosUnicos[1000][100];

    // Leitura do arquivo com fscanf
    while (1) {
        char nome[100];
        int idade;
        char bairro[100];

        if (fscanf(entrada, "%[^;];%i;%[^\n]\n", nome, &idade, bairro) != 3) break;

        strcpy(nomes[totalPessoas], nome);
        idades[totalPessoas] = idade;
        strcpy(bairros[totalPessoas], bairro);
        totalPessoas++;
    }
    fclose(entrada);

    // Encontrar bairros únicos
    for (int i = 0; i < totalPessoas; i++) {
        int encontrado = 0;
        for (int j = 0; j < totalBairros; j++) {
            if (strcmp(bairrosUnicos[j], bairros[i]) == 0) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            strcpy(bairrosUnicos[totalBairros], bairros[i]);
            totalBairros++;
        }
    }

    // Para cada bairro único, gera arquivo com pessoas ordenadas por idade
    for (int b = 0; b < totalBairros; b++) {
        char* bairroAtual = bairrosUnicos[b];

        char nomesBairro[1000][100];
        int idadesBairro[1000];
        int count = 0;

        // Coleta as pessoas do bairro atual
        for (int i = 0; i < totalPessoas; i++) {
            if (strcmp(bairros[i], bairroAtual) == 0) {
                strcpy(nomesBairro[count], nomes[i]);
                idadesBairro[count] = idades[i];
                count++;
            }
        }

        // Ordena por idade (bubble sort)
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (idadesBairro[j] > idadesBairro[j + 1]) {
                    int tempIdade = idadesBairro[j];
                    idadesBairro[j] = idadesBairro[j + 1];
                    idadesBairro[j + 1] = tempIdade;

                    char tempNome[100];
                    strcpy(tempNome, nomesBairro[j]);
                    strcpy(nomesBairro[j], nomesBairro[j + 1]);
                    strcpy(nomesBairro[j + 1], tempNome);
                }
            }
        }

        // Cria arquivo do bairro
        char nomeArquivo[120];
        snprintf(nomeArquivo, sizeof(nomeArquivo), "%s.txt", bairroAtual);
        FILE* out = fopen(nomeArquivo, "w");
        if (!out) {
            perror("Erro ao criar arquivo do bairro");
            continue;
        }

        for (int i = 0; i < count; i++) {
            fprintf(out, "%s;%d\n", nomesBairro[i], idadesBairro[i]);
        }

        fclose(out);
    }

    printf("Arquivos por bairro criados com sucesso.\n");
    return 0;
}
