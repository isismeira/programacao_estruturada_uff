#include <stdio.h>

void inverte_palavra(char *palavra,char *palavra_invertida, int tamanho_palavra);
int tamanho_palavra(char *palavra);
int eh_palindromo(char *palavra, char *palavra_invertida, int tamanho);

int main()
{
    char palavra[80], palavra_invertida[80];

    printf("Digite a palavra: ");
    scanf(" %80[^\n]", palavra);

    int tamanho = tamanho_palavra(palavra);
    
    inverte_palavra(palavra, palavra_invertida, tamanho);

    if (eh_palindromo(palavra, palavra_invertida, tamanho)){
        printf("eh palindroma");
    } else {
        printf("nao e palindroma");
    }
}

int tamanho_palavra(char *palavra)
{
    int tamanho = 0;
    for (int i = 0; *(palavra + i) != '\0'; i++) {
        tamanho++;
    }
    return (tamanho);
}

void inverte_palavra(char *palavra,char *palavra_invertida, int tamanho)
{
    int i;
    int j = tamanho - 1;
    for (i = 0; *(palavra + i) != '\0'; i++) {
        *(palavra_invertida + i) = *(palavra + j);
        j--;
    }
    *(palavra_invertida + i) = '\0';
}

int eh_palindromo(char *palavra, char *palavra_invertida, int tamanho)
{
    for (int i = 0; i < tamanho; i++) {
        if (*(palavra + i) != *(palavra_invertida + i)) {
            return 0;
        }
    }
    return 1;
}