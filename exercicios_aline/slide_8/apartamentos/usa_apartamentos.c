#include <stdio.h>
#include <stdlib.h>
#include "apartamentos.h"

int main() {
    int qtdd;
    printf("Digite a quantidade de apartamentos no condomínio: \n");
    scanf("%i", &qtdd);

    Apartamento* apts = cria_vetor_apartamentos(qtdd);

    le_dados_apartamentos(apts, qtdd);

    float area_total = calcula_area_total(apts, qtdd);
    printf("\nÁrea total ocupada: %.2f m²\n", area_total);

    float despesa;
    printf("\nDigite o valor total da despesa do condomínio: R$ ");
    scanf("%f", &despesa);

    calcula_valores(apts, qtdd, despesa);

    imprime_apartamento_maior_moradores(apts, qtdd);

    libera_apartamentos(apts);
    return 0;
}
