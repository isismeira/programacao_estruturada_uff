#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main() {
    String* s = cria_string("arara");

    char* inv = inverte_string(s);
    printf("String invertida: %s\n", inv);
    free(inv);

    printf("É palíndromo? %d\n", eh_palindromo(s));

    char* pre = prefixo_string(s, 3);
    printf("Prefixo até posição 3: %s\n", pre);
    free(pre);

    char* suf = sufixo_string(s, 2);
    printf("Sufixo a partir da posição 2: %s\n", suf);
    free(suf);

    printf("Após trocar 'a' por 'x': %s", troca_letra(s, 'a', 'x'));

    libera_string(s);
    return 0;
}
