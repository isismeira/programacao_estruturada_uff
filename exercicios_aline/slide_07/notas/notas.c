#include <stdio.h>
#include <stdlib.h>

int main()
{
    float p1, p2, p3, media;
    FILE *arq_entrada, *arq_saida;

    arq_entrada = fopen("C:/Users/Isis/Desktop/teste/entrada_notas.txt", "r");
    if (arq_entrada == NULL) {
        printf("Erro ao abrir entrada.txt. Verifique se o arquivo existe.\n");
        exit(1);
    }

    arq_saida = fopen("C:/Users/Isis/Desktop/teste/saida_notas.txt", "w");
    if (arq_saida == NULL) {
        printf("Erro ao criar/abrir saida.txt.\n");
        fclose(arq_entrada); // Fecha o arquivo de entrada se a saída falhar
        exit(1);
    }

    while ( fscanf(arq_entrada, "%f %f %f", &p1, &p2, &p3) == 3 ) {
        media = (p1 + p2 + p3) / 3;
        fprintf(arq_saida, "%.1f ", media);
        if (media >= 5.0) {
            fprintf(arq_saida, "Aprovado(a)\n");
        } else {
            fprintf(arq_saida, "Reprovado(a)\n");
        }
    }

    fclose(arq_entrada);
    fclose(arq_saida);
    return 0;
}