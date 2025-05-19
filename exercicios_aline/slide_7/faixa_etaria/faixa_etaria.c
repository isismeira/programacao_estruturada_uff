#include <stdio.h>
#include <string.h>

void bubble_sort(int n, char nomes[][100], int idades[], char profissoes[][100]);

int main()
{
    FILE *entrada = fopen("C:/Users/Isis/Documents/prog_estruturada_uff/exercicios_aline/slide_7/faixa_etaria/entrada.txt", "r");

    int n_jovens = 0;
    char nomes_jovens[1000][100];
    int idades_jovens[1000];
    char profissoes_jovens[1000][100];

    int n_adultos = 0;
    char nomes_adultos[1000][100];
    int idades_adultos[1000];
    char profissoes_adultos[1000][100];

    int n_idosos = 0;
    char nomes_idosos[1000][100];
    int idades_idosos[1000];
    char profissoes_idosos[1000][100];

    while (1) {
        char nome[100];
        int idade;
        char profissao[100];

        if (fscanf(entrada, "%[^;];%i;%[^\n]\n", nome, &idade, profissao) != 3) break;

        if (idade < 18) {
            strcpy(nomes_jovens[n_jovens], nome);
            idades_jovens[n_jovens] = idade;
            strcpy(profissoes_jovens[n_jovens], profissao);
            n_jovens++;
        } else if  (idade >= 18 && idade < 60){
            strcpy(nomes_adultos[n_adultos], nome);
            idades_adultos[n_adultos] = idade;
            strcpy(profissoes_adultos[n_adultos], profissao);
            n_adultos++;
        } else if (idade >= 60) {
            strcpy(nomes_idosos[n_idosos], nome);
            idades_idosos[n_idosos] = idade;
            strcpy(profissoes_idosos[n_idosos], profissao);
            n_idosos++;            
        }
    }

    bubble_sort(n_jovens, nomes_jovens, idades_jovens, profissoes_jovens);
    bubble_sort(n_adultos, nomes_adultos, idades_adultos, profissoes_adultos);
    bubble_sort(n_idosos, nomes_idosos, idades_idosos, profissoes_idosos);

    FILE *jovens = fopen("C:/Users/Isis/Documents/prog_estruturada_uff/exercicios_aline/slide_7/faixa_etaria/jovens.txt", "w");
    FILE *adultos = fopen("C:/Users/Isis/Documents/prog_estruturada_uff/exercicios_aline/slide_7/faixa_etaria/adultos.txt", "w");
    FILE *idosos = fopen("C:/Users/Isis/Documents/prog_estruturada_uff/exercicios_aline/slide_7/faixa_etaria/idosos.txt", "w");

    for (int i = 0; i < n_jovens; i++) {
        fprintf(jovens, "%s;%i;%s", nomes_jovens[i], idades_jovens[i], profissoes_jovens[i]);
    }
    for (int i = 0; i < n_adultos; i++) {
        fprintf(adultos, "%s;%i;%s", nomes_adultos[i], idades_adultos[i], profissoes_adultos[i]);
    }
    for (int i = 0; i < n_idosos; i++) {
        fprintf(idosos, "%s;%i;%s", nomes_idosos[i], idades_idosos[i], profissoes_idosos[i]);
    }
    fclose(entrada);
    fclose(jovens);
    fclose(adultos);
    fclose(idosos);
}

void bubble_sort(int n, char nomes[][100], int idades[], char profissoes[][100])
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0 ; j < n - i - 1; j++) {
            if(strcmp(nomes[j], nomes[j+1]) > 0) {
                char temp_nome[100],temp_profissao[100];
                int temp_idade;
               
                strcpy(temp_nome, nomes[j]);
                strcpy(nomes[j], nomes[j + 1]);
                strcpy(nomes[j + 1], temp_nome);

                temp_idade = idades[j];
                idades[j] = idades[j+1];
                idades[j+1] = temp_idade;

                strcpy(temp_profissao, profissoes[j]);
                strcpy(profissoes[j], profissoes[j + 1]);
                strcpy(profissoes[j + 1], temp_profissao);
            }
        }
    }
}