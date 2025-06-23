#include <stdio.h>

void copiando_trecho(int indice,char *palavra, char *trecho, char caractere);

int main()
{
    char palavra[80], trecho[80];
    char caractere;

    printf("Digite a palavra: ");
    scanf(" %80[^\n]", palavra);

    printf("Digite o caractere: ");
    scanf(" %c", &caractere); // ler caractere eh assim
    
    int i;
    for (i = 0; *(palavra + i) != '\0'; i++){ // sempre '\0'
        if (*(palavra + i) == caractere) {
            copiando_trecho(i, palavra, trecho, caractere);
            break;
        }
    } 

    return 0;
}


void copiando_trecho(int indice,char *palavra, char *trecho, char caractere)
{
    int j = 0;
    for (int i = indice + 1; palavra[i] != '\0' && palavra[i] != caractere; i++) { // importante! olha esse loop
        *(trecho + j) = *(palavra + i);
        j++;
    }

    *(trecho + j) = '\0';

    printf("Trecho copiado: %s\n", trecho);
}