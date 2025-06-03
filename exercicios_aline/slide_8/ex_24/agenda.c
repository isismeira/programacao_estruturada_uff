#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

typedef struct pessoa {
    char nome[100];
    char email[100];
    char rua[100];
    int numero;
    char complemento[50];
    char bairro[50];
    char cep[20];
    char cidade[50];
    char estado[50];
    char pais[50];
    int ddd;
    char telefone[20];
    int dia;
    int mes;
    int ano;
    char observacao[100];
} Pessoa;

Pessoa* agenda_cria() {
    Pessoa* p = (Pessoa*) malloc(sizeof(Pessoa));
    if (p == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }
    return p;
}

void agenda_libera(Pessoa* p) {
    free(p);
}

void agenda_atribui(Pessoa* p, char nome[], char email[], char rua[], int numero, 
                     char complemento[], char bairro[], char cep[], char cidade[], 
                     char estado[], char pais[], int ddd, char telefone[], 
                     int dia, int mes, int ano, char obs[]) {
    strcpy(p->nome, nome);
    strcpy(p->email, email);
    strcpy(p->rua, rua);
    p->numero = numero;
    strcpy(p->complemento, complemento);
    strcpy(p->bairro, bairro);
    strcpy(p->cep, cep);
    strcpy(p->cidade, cidade);
    strcpy(p->estado, estado);
    strcpy(p->pais, pais);
    p->ddd = ddd;
    strcpy(p->telefone, telefone);
    p->dia = dia;
    p->mes = mes;
    p->ano = ano;
    strcpy(p->observacao, obs);
}

void agenda_acessa(Pessoa* p) {
    imprime_completo(p);
}

int compara_nome(Pessoa* p, char nome[]) {
    return strcmp(p->nome, nome) == 0;
}

int verifica_mes(Pessoa* p, int mes) {
    return p->mes == mes;
}

int verifica_dia_mes(Pessoa* p, int dia, int mes) {
    return (p->dia == dia && p->mes == mes);
}

void imprime_resumido(Pessoa* p) {
    printf("Nome: %s | Telefone: (%d) %s | Email: %s\n", p->nome, p->ddd, p->telefone, p->email);
}

void imprime_completo(Pessoa* p) {
    printf("\nNome: %s\nEmail: %s\nTelefone: (%d) %s\n", p->nome, p->ddd, p->telefone, p->email);
    printf("Endereco: %s, %d, %s, %s, %s, %s, %s, %s\n", p->rua, p->numero, p->complemento, p->bairro, p->cep, p->cidade, p->estado, p->pais);
    printf("Aniversario: %02d/%02d/%04d\n", p->dia, p->mes, p->ano);
    printf("Observacoes: %s\n", p->observacao);
}
