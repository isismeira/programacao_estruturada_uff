#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHAS 1000
#define MAX_NOME 100
#define MAX_BAIRRO 100

// Arrays para armazenar os dados
char nomes[MAX_LINHAS][MAX_NOME];
int idades[MAX_LINHAS];
char bairros[MAX_LINHAS][MAX_BAIRRO];

char bairrosUnicos[MAX_LINHAS][MAX_BAIRRO];
int totalPessoas = 0;
int totalBairros = 0;

// Função para verificar se um bairro já está na lista de bairros únicos
int encontrar_ou_adicionar_bairro(const char* bairro) {
    for (int i = 0; i < totalBairros; i++) {
        if (strcmp(bairrosUnicos[i], bairro) == 0)
            return i;
    }
    // Se não encontrou, adiciona
    strcpy(bairrosUnicos[totalBairros], bairro);
    totalBairros++;
    return totalBairros - 1;
}

int main() {
    FILE* entrada = fopen("exercicios_aline/slide_7/nome_idade_cidade.txt", "r");
    if (!entrada) {
        perror("Erro ao abrir entrada.txt");
        return 1;
    }

    char linha[300];
    while (fgets(linha, sizeof(linha), entrada)) {
        char* token;

        // Nome
        token = strtok(linha, ";\n");
        if (!token) continue;
        strcpy(nomes[totalPessoas], token);

        // Idade
        token = strtok(NULL, ";\n");
        if (!token) continue;
        idades[totalPessoas] = atoi(token);

        // Bairro
        token = strtok(NULL, ";\n");
        if (!token) continue;
        strcpy(bairros[totalPessoas], token);

        totalPessoas++;
    }
    fclose(entrada);

    // Para cada bairro único, filtra e salva as pessoas
    for (int b = 0; b < totalPessoas; b++) {
        encontrar_ou_adicionar_bairro(bairros[b]);
    }

    for (int i = 0; i < totalBairros; i++) {
        char* bairroAtual = bairrosUnicos[i];

        // Cria arrays temporários para as pessoas deste bairro
        char nomesBairro[MAX_LINHAS][MAX_NOME];
        int idadesBairro[MAX_LINHAS];
        int count = 0;

        for (int j = 0; j < totalPessoas; j++) {
            if (strcmp(bairros[j], bairroAtual) == 0) {
                strcpy(nomesBairro[count], nomes[j]);
                idadesBairro[count] = idades[j];
                count++;
            }
        }

        // Ordena por idade (bubble sort simples)
        for (int x = 0; x < count - 1; x++) {
            for (int y = 0; y < count - x - 1; y++) {
                if (idadesBairro[y] > idadesBairro[y + 1]) {
                    int tempIdade = idadesBairro[y];
                    idadesBairro[y] = idadesBairro[y + 1];
                    idadesBairro[y + 1] = tempIdade;

                    char tempNome[MAX_NOME];
                    strcpy(tempNome, nomesBairro[y]);
                    strcpy(nomesBairro[y], nomesBairro[y + 1]);
                    strcpy(nomesBairro[y + 1], tempNome);
                }
            }
        }

        // Gera nome do arquivo: bairro.txt
        char nomeArquivo[MAX_BAIRRO + 10];
        snprintf(nomeArquivo, sizeof(nomeArquivo), "%s.txt", bairroAtual);
        FILE* out = fopen(nomeArquivo, "w");
        if (!out) {
            perror("Erro ao criar arquivo");
            continue;
        }

        for (int k = 0; k < count; k++) {
            fprintf(out, "%s;%d\n", nomesBairro[k], idadesBairro[k]);
        }

        fclose(out);
    }

    printf("Arquivos por bairro criados com sucesso.\n");
    return 0;
}
