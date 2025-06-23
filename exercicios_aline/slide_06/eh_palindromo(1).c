#include <stdio.h>

// essa versão verifica se frases inteiras são palíndromas

void retira_espacos(char *palavra, char *palavra_sem_espacos);
void inverte_palavra(char *palavra_sem_espacos,char *palavra_invertida, int tamanho_palavra);
int tamanho_palavra(char *palavra_sem_espacos);
int eh_palindromo(char *palavra_sem_espacos, char *palavra_invertida, int tamanho);

int main()
{
    char palavra[80], palavra_sem_espacos[80], palavra_invertida[80];

    printf("Digite a palavra: ");
    scanf(" %80[^\n]", palavra);

    retira_espacos(palavra, palavra_sem_espacos);

    int tamanho = tamanho_palavra(palavra_sem_espacos);
    
    inverte_palavra(palavra_sem_espacos, palavra_invertida, tamanho);

    if (eh_palindromo(palavra_sem_espacos, palavra_invertida, tamanho)){
        printf("eh palindroma");
    } else {
        printf("nao e palindroma");
    }
}

void retira_espacos(char *palavra, char *palavra_sem_espacos)
{
    int i;
    int j = 0;
    for(i = 0; *(palavra + i) != '\0'; i++) {
        if (*(palavra + i) != ' ') {
            *(palavra_sem_espacos + j) = *(palavra+ i);
            j++; 
        }
    }
    *(palavra + i) = '\0';
}

int tamanho_palavra(char *palavra_sem_espacos)
{
    int tamanho = 0;
    for (int i = 0; *(palavra_sem_espacos + i) != '\0'; i++) {
        tamanho++;
    }
    return (tamanho);
}

void inverte_palavra(char *palavra_sem_espacos, char *palavra_invertida, int tamanho)
{
    int i;
    int j = tamanho - 1;
    for (i = 0; *(palavra_sem_espacos + i) != '\0'; i++) {
        *(palavra_invertida + i) = *(palavra_sem_espacos + j);
        j--;
    }
    *(palavra_invertida + i) = '\0';
}

int eh_palindromo(char *palavra_sem_espacos, char *palavra_invertida, int tamanho)
{
    for (int i = 0; i < tamanho; i++) {
        if (*(palavra_sem_espacos + i) != *(palavra_invertida + i)) {
            return 0;
        }
    }
    return 1;
}