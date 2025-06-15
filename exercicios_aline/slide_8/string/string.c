#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

typedef struct string {
    char* string;
} String;

String* cria_string(char* string) {
    String* s = (String*)malloc(sizeof(String));
    if (s==NULL) {
        printf("Memória insuficiente");
        exit(1);
    }
    s->string = strdup(string);
    return s;
}

char* inverte_string(String* s) {
    int len = strlen(s->string);
    char* invertida = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        invertida[i] = s->string[len - 1 - i];
    }
    invertida[len] = '\0';
    return invertida;    
}

int eh_palindromo(String* s) {
    int i = 0;
    int j = strlen(s->string) - 1;
    while (i < j) {
        if (s->string[i] != s->string[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}

char* prefixo_string(String* s, int pos_max) {
    char* prefixo = malloc(pos_max + 1);
    for (int i = 0; i < pos_max; i++) {
        prefixo[i] = s->string[i];
    }
    prefixo[pos_max] = '\0'; // !!!
    return prefixo;
}

char* sufixo_string(String* s, int pos_min) {
    int len = strlen(s->string);
    char* sufixo = malloc(len - pos_min + 1);
    int i = 0;
    int j = pos_min;
    for (int i = 0; i < len - pos_min; i++) {
        sufixo[i] = s->string[j];
        j++;        
    }
    sufixo[len - pos_min] = '\0'; // !!!
    return sufixo;
}

char* troca_letra(String* s, char letra_original, char letra_substituta) {
    int len = strlen(s->string);
    char* substituida = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        if (s->string[i] == letra_original) {
            substituida[i] = letra_substituta;
        } else {
            substituida[i] = s->string[i];
        }
    }
    substituida[len] = '\0'; /// !!!
    return substituida;
}


void libera_string(String* s) {
    free(s->string);
    free(s);
}