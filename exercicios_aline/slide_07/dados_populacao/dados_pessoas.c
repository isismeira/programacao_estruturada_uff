#include <stdio.h>
#include <string.h> // !!!

int main()
{
    FILE *entrada = fopen("C:/Users/Isis/Desktop/teste/entrada.txt", "r");
    FILE *saida = fopen("C:/Users/Isis/Desktop/teste/saida.txt", "w");

    char nome[20], sexo[20], olhos[20], ensino[20];
    float altura, peso;
    int idade;

    int soma_idades = 0;
    int idades[50];
    float soma_alturas = 0;
    int qtt_olhos_verdes_mais_de_50 = 0;
    int num_pessoas = 0;

    while ( fscanf(entrada, "%[^;];%[^;];%f;%f;%d;%[^;];%[^\n]\n", nome, sexo, &altura, &peso, &idade, olhos, ensino) == 7) {
        soma_idades += idade;
        idades[num_pessoas] = idade;
        soma_alturas += altura;
        if ((strcmp(sexo, "Feminino") == 0) && (idade >= 50) && (strcmp(olhos, "Verdes") == 0)) { //!!!
            qtt_olhos_verdes_mais_de_50++;
        }
        num_pessoas++;
    }

    // Média das idades
    float media_idade = ((float)soma_idades / num_pessoas); //!!!
    // Média das alturas
    float media_altura = ((float)soma_alturas / num_pessoas ); //!!!
    // Numero de pessoas com a idade acima da média
    int num_pessoas_idade_acima_media = 0;
    for (int i = 0; i < num_pessoas; i++) {
        if (idades[i] > media_idade) {
            num_pessoas_idade_acima_media++;
        }
    } 

    fprintf(saida, "Média das idades: %f\n", media_idade);
    fprintf(saida, "Média das alturas: %f\n", media_altura);
    fprintf(saida, "Quantidade de pessoas com idade acima da media: %i\n", num_pessoas_idade_acima_media);
    fprintf(saida, "Quantidade de mulheres de olhos verdes com mais de 50 anos: %i", qtt_olhos_verdes_mais_de_50);

    fclose(saida);
    fclose(entrada);
    return 0; 
}

