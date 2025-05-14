#include <stdio.h>

void criptografar(FILE *entrada, FILE *saida, int k);
void descriptografar(FILE *saida_leitura, FILE *descriptografia, int k);

int main()
{
    FILE *entrada, *saida, *descriptografia;
    int k;

    printf("Informe o valor de k: ");
    scanf("%i", &k);

    entrada = fopen("C:/Users/Isis/Desktop/teste/entrada.txt", "r");
    saida = fopen("C:/Users/Isis/Desktop/teste/saida.txt", "w");
    descriptografia = fopen("C:/Users/Isis/Desktop/teste/descriptografia.txt", "w");

    criptografar(entrada, saida, k);

    fclose(saida); //fecha para reabrir como leitura (na função descrpitografar) 
    FILE *saida_leitura = fopen("C:/Users/Isis/Desktop/teste/saida.txt", "r");   
    descriptografar(saida_leitura, descriptografia, k);

    fclose(entrada);
    fclose(saida_leitura);
    fclose(descriptografia);
}

void criptografar(FILE *entrada, FILE *saida, int k) {
    char caractere;
    while (fscanf(entrada, "%c", &caractere) == 1) {
        caractere = (caractere + k) % 128;
        fprintf(saida, "%c", caractere);
    }
}

void descriptografar(FILE *saida_leitura, FILE *descriptografia, int k) {
    char caractere;
    while( fscanf(saida_leitura, "%c", &caractere) == 1 ) { 
        caractere = (caractere - k) % 128;
        fprintf(descriptografia, "%c", caractere);
    }
}