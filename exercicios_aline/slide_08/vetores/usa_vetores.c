#include <stdio.h>
#include <stdlib.h>
#include "vetores.h"

int main()
{
    Vetor* vetor_1 = cria_vetor(3);
    Vetor* vetor_2 = cria_vetor(3);
    Vetor* vetor_3 = cria_vetor(3);

    float valores_1[3];
    float valores_2[3];
    printf("Digite os valores de cada ponto do vetor 1: ");
    scanf("%f %f %f", &valores_1[0], &valores_1[1], &valores_1[2]);
    printf("Digite os valores de cada ponto do vetor 2: ");
    scanf("%f %f %f", &valores_2[0], &valores_2[1], &valores_2[2]);
    preenche_vetor(vetor_1, valores_1);
    preenche_vetor(vetor_2, valores_2);

    soma_vetores(vetor_1, vetor_2, vetor_3);
    printf("Soma dos vetores 1 e 2: \n");
    for (int i = 0; i < 3; i++) {
        printf("%f ", acessar_elemento(vetor_3, i));
    }

    multiplica_vetores(vetor_1, vetor_2, vetor_3);
    printf("Multiplicação dos vetores 1 e 2: \n");
    for (int i = 0; i < 3; i++) {
        printf("%f ", acessar_elemento(vetor_3, i));
    }

    float k;
    printf("Digite o valor de um escalar k");
    scanf("%f", &k);
    mult_escalar_vetor(vetor_1, k);
    for (int i = 0; i < 3; i++) {
        printf("%f ", acessar_elemento(vetor_1, i));
    }

    free_vetor(vetor_1);
    free_vetor(vetor_2);
    free_vetor(vetor_3);
}    