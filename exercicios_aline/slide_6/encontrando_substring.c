#include <stdio.h>

int encontrar_substring(const char *maior, const char *menor);

int main() {
    char str1[100], str2[100];
    int tamanho_str1 = 0, tamanho_str2 = 0;
    int posicao;
    
    printf("Digite a primeira string: ");
    scanf("%99[^\n]%*c", str1);
    
    printf("Digite a segunda string: ");
    scanf("%99[^\n]%*c", str2);
      
    // Calcula tamanho das strings
    while (str1[tamanho_str1] != '\0') tamanho_str1++;
    while (str2[tamanho_str2] != '\0') tamanho_str2++;
    
    // Determina qual é a maior e qual é a menor
    if (tamanho_str1 >= tamanho_str2) {
        posicao = encontrar_substring(str1, str2);
        if (posicao != -1) {
            printf("A menor string aparece na posicao %d da maior string.\n", posicao);
        } else {
            printf("A menor string nao esta contida na maior string.\n");
        }
    } else {
        posicao = encontrar_substring(str2, str1);
        if (posicao != -1) {
            printf("A menor string aparece na posicao %d da maior string.\n", posicao);
        } else {
            printf("A menor string nao esta contida na maior string.\n");
        }
    }
    
    return 0;
}


int encontrar_substring(const char *maior, const char *menor) {
    int i, j, k;
    int pos = -1;
    
    // Percorre a string maior
    for (i = 0; maior[i] != '\0'; i++) {
        // Verifica se o caractere atual coincide com o primeiro da menor
        if (maior[i] == menor[0]) {
            // Compara os caracteres seguintes
            for (j = i, k = 0; menor[k] != '\0' && maior[j] == menor[k]; j++, k++);
            
            // Se toda a string menor foi percorrida, encontramos a substring
            if (menor[k] == '\0') {
                pos = i;
                break;
            }
        }
    }
    return pos;
}