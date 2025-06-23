#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    TED (Tipo Estruturado de Dados)
    É um tipo definido pelo programador que agrupa vários dados de tipos diferentes (ou iguais) em uma única estrutura.
    Serve para organizar dados com algum relacionamento lógico.
*/

typedef struct { // Cria uma caixa 
    int idade;
    char sexo;
    char nome[100];
}Pessoa; // O nome da caixa é "pessoa"

int main()
{
    Pessoa isis;
    Pessoa joao;

    isis.idade = 19;
    isis.sexo = 'F';
    strcpy(isis.nome, "Isis");

    printf("Digite seu nome: ");
    fgets(joao.nome, 100, stdin);
    joao.nome[strcspn(joao.nome, "\n")] = '\0'; // Para remover o \n na leitura do fgets
    printf("Digite sua idade: ");
    scanf("%d", &joao.idade);
    printf("Digite F ou M para o sexo: ");
    scanf(" %c", &joao.sexo);

    printf("Nome: %s\nIdade: %d\nSexo: %c\n", isis.nome, isis.idade, isis.sexo);
    printf("Nome: %s\nIdade: %d\nSexo: %c\n", joao.nome, joao.idade, joao.sexo);

    return 0;
}