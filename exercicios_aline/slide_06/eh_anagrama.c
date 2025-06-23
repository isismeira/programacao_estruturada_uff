#include <stdio.h>

void marcacao(char *palavra1, char *palavra2);
void achar_letra(char caractere,char *palavra2);
int esta_toda_marcada(char *palavra2);

int main()
{
    char palavra1[80], palavra2[80];

    printf("Digite a primeira palavra");
    scanf(" %80[^\n]", palavra1); 
    printf("Digite a segunda palavra");
    scanf(" %80[^\n]", palavra2);

    marcacao(palavra1, palavra2);

    if (esta_toda_marcada(palavra2)){
        printf("As palavras sao anagramas");
    } else {
        printf("As palavras nao sao anagramas");
    }
}

void marcacao(char *palavra1, char *palavra2) {
    for (int i = 0; *(palavra1 + i) != '\0'; i++) {
        achar_letra(*(palavra1 +i), palavra2);
    }
}

void achar_letra(char caractere,char *palavra2)  
{
    for (int i = 0; *(palavra2 + i) != '\0'; i++) {
        if ( (*(palavra2 + i)) == caractere ) {
            *(palavra2 + i) = '|';
            break;
        }
    }
}

int esta_toda_marcada(char *palavra2)
{
    for (int i = 0; *(palavra2 + i) != '\0'; i++) {
        if (*(palavra2 + i) != '|') {
            return 0;
        }
    }
    return 1;
}