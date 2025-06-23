#include <stdio.h>

int comparar_strings(int indice, char *maior, char *menor, int len_menor);

int main()
{
    char maior[80], menor[80];
    int len_menor = 3;

    printf("Digite a string maior: ");
    scanf(" %80[^\n]", maior);
    printf("Digite a string menor: ");
    scanf(" %80[^\n]", menor);    



    int i;

    for (i = 0; *(maior + i) != '\0'; i++) {
        if (*(maior + i) == *(menor + 0)) {
            if (comparar_strings(i, maior, menor, len_menor)) {
                printf("%i", i);
                return 0;
            }
        }
    }
    printf("Não foi possivel encontrar o indice onde a string menor comeca");
}

int comparar_strings(int indice, char *maior, char *menor, int len_menor)
{
    int i;
    int j = 0;
    char temp[80];
    for (i = indice; i < (len_menor + 1); i++) {
        *(temp + j) = *(maior + i);
        j++;
    }
    *(temp + j) = '\0';

    for (int k = 0; k < (len_menor +1); k++) {
        if (*(menor + k) != *(temp + k)) {
            return 0;
        }
    }
    return 1;
}