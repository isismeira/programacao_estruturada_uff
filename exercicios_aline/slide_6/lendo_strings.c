#include <stdio.h>

int eh_digito(char c) // determina se um caractere é um digito
{
    if ((c>='0')&&(c<='9'))
        return 1;
    else
        return 0;   
}

int eh_letra(char c) // determina se um caractere é uma letra
{
    if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')))
        return 1;
    else
        return 0;
}

int vira_maiuscula(char c) // transforma todas letras em maiúsculas
{
    if ((c >= 'a') && (c <= 'z'))
        return c - ('a' - 'A');
    else
        return c;    
}

int vira_minuscula(char c) // transforma todas letras em minusculas
{
    if ((c >= 'A') && (c <= 'Z'))
        return c + ('a' - 'A');
    else
        return c;    
}
void imprime(char* s) // le caractere por caractere
{
    int i;
    for (i=0; s[i] != '\0'; i++)
        printf("%c",s[i]);
    printf("\n");
}

void le_e_imprime(char* string) // como ler e imprimir strings
{
    // Leitura ideal para nomes compostos
    scanf(" %80[^\n]", string); // ATENÇÃO: sem & ; lê no máximo 80 caracteres

    // Impressão
    for (int i = 0; string[i] != '\0'; i++){
        printf("%c", string[i]);
    }
    
}

void copia (char* dest, char* orig) // copia os elementos da cadeia original para a cadeia de destino
{
    int i;
    for (i=0; orig[i] != '\0'; i++)
        dest[i] = orig[i];
    /* fecha a cadeia copiada */
    dest[i] = '\0';
}


int main() {
    char c = 97;
    printf("%d %c\n",c,c); // 97 a

    char cidade[] = {'R', 'i', 'o', '\0'};

    char string[81];
    le_e_imprime(string);
    //obs "\0" sempre indica o final de uma cadeia de caracteres
}    