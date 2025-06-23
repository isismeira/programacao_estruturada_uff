#include <stdio.h>
#include <string.h>
#include "agenda.h"

#define MAX 100

int main() {
    Pessoa* agenda[MAX];
    int qtd = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Inserir pessoa\n");
        printf("2 - Buscar por nome\n");
        printf("3 - Buscar por mes de aniversario\n");
        printf("4 - Buscar por dia e mes de aniversario\n");
        printf("5 - Remover pessoa\n");
        printf("6 - Imprimir resumo\n");
        printf("7 - Imprimir completo\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        if(opcao == 1) {
            if(qtd >= MAX) {
                printf("Agenda cheia!\n");
                continue;
            }
            char nome[100], email[100], rua[100], complemento[50], bairro[50];
            char cep[20], cidade[50], estado[50], pais[50], telefone[20], obs[100];
            int numero, ddd, dia, mes, ano;

            printf("Nome: "); fgets(nome, 100, stdin); nome[strcspn(nome, "\n")] = '\0';
            printf("Email: "); fgets(email, 100, stdin); email[strcspn(email, "\n")] = '\0';
            printf("Rua: "); fgets(rua, 100, stdin); rua[strcspn(rua, "\n")] = '\0';
            printf("Numero: "); scanf("%d", &numero); getchar();
            printf("Complemento: "); fgets(complemento, 50, stdin); complemento[strcspn(complemento, "\n")] = '\0';
            printf("Bairro: "); fgets(bairro, 50, stdin); bairro[strcspn(bairro, "\n")] = '\0';
            printf("CEP: "); fgets(cep, 20, stdin); cep[strcspn(cep, "\n")] = '\0';
            printf("Cidade: "); fgets(cidade, 50, stdin); cidade[strcspn(cidade, "\n")] = '\0';
            printf("Estado: "); fgets(estado, 50, stdin); estado[strcspn(estado, "\n")] = '\0';
            printf("Pais: "); fgets(pais, 50, stdin); pais[strcspn(pais, "\n")] = '\0';
            printf("DDD: "); scanf("%d", &ddd); getchar();
            printf("Telefone: "); fgets(telefone, 20, stdin); telefone[strcspn(telefone, "\n")] = '\0';
            printf("Data de nascimento (dia mes ano): "); scanf("%d %d %d", &dia, &mes, &ano); getchar();
            printf("Observacao: "); fgets(obs, 100, stdin); obs[strcspn(obs, "\n")] = '\0';

            agenda[qtd] = agenda_cria();
            agenda_atribui(agenda[qtd], nome, email, rua, numero, complemento, bairro, cep, cidade, estado, pais, ddd, telefone, dia, mes, ano, obs);
            qtd++;
        }

        else if(opcao == 2) {
            char nome[100];
            printf("Nome a buscar: ");
            fgets(nome, 100, stdin); nome[strcspn(nome, "\n")] = '\0';

            for(int i = 0; i < qtd; i++) {
                if(compara_nome(agenda[i], nome)) {
                    imprime_completo(agenda[i]);
                }
            }
        }

        else if(opcao == 3) {
            int mes;
            printf("Mes de aniversario: ");
            scanf("%d", &mes); getchar();

            for(int i = 0; i < qtd; i++) {
                if(verifica_mes(agenda[i], mes)) {
                    imprime_completo(agenda[i]);
                }
            }
        }

        else if(opcao == 4) {
            int dia, mes;
            printf("Dia e mes de aniversario: ");
            scanf("%d %d", &dia, &mes); getchar();

            for(int i = 0; i < qtd; i++) {
                if(verifica_dia_mes(agenda[i], dia, mes)) {
                    imprime_completo(agenda[i]);
                }
            }
        }

        else if(opcao == 5) {
            char nome[100];
            printf("Nome a remover: ");
            fgets(nome, 100, stdin); nome[strcspn(nome, "\n")] = '\0';

            int found = -1;
            for(int i = 0; i < qtd; i++) {
                if(compara_nome(agenda[i], nome)) {
                    found = i;
                    break;
                }
            }

            if(found != -1) {
                agenda_libera(agenda[found]);
                for(int j = found; j < qtd - 1; j++) {
                    agenda[j] = agenda[j+1];
                }
                qtd--;
                printf("Removido!\n");
            } else {
                printf("Pessoa nao encontrada.\n");
            }
        }

        else if(opcao == 6) {
            for(int i = 0; i < qtd; i++) {
                imprime_resumido(agenda[i]);
            }
        }

        else if(opcao == 7) {
            for(int i = 0; i < qtd; i++) {
                imprime_completo(agenda[i]);
            }
        }

    } while(opcao != 0);

    for(int i = 0; i < qtd; i++) {
        agenda_libera(agenda[i]);
    }

    return 0;
}
