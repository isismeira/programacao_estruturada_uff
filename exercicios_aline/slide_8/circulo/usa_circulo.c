#include <stdio.h>
#include "circulo.h"

//Comando de compilação: gcc -o usa_circulo.exe usa_circulo.c circulo.c -lm
//Comando de execução: .\usa_circulo.exe

int main() {
    float x, y, raio;
    float ponto_x, ponto_y;

    // 1. Criação do círculo (dados fornecidos pelo usuário)
    printf("Digite as coordenadas do centro do círculo (x y): ");
    scanf("%f %f", &x, &y);
    printf("Digite o raio do círculo: ");
    scanf("%f", &raio);

    Circulo* meuCirculo = cria_circulo(x, y, raio);
    printf("\nCírculo criado com centro (%.1f, %.1f) e raio %.1f.\n", x, y, raio);

    // 2. Acesso aos atributos (demonstração)
    float cx, cy, cr;
    acessa_circulo(meuCirculo, &cx, &cy, &cr);
    printf("Dados acessados: Centro = (%.1f, %.1f), Raio = %.1f\n", cx, cy, cr);

    // 3. Modificação do círculo (dados fornecidos pelo usuário)
    printf("\nDigite as novas coordenadas do centro (x y): ");
    scanf("%f %f", &x, &y);
    printf("Digite o novo raio: ");
    scanf("%f", &raio);
    atribui_circulo(meuCirculo, x, y, raio);
    printf("Círculo modificado para centro (%.1f, %.1f) e raio %.1f.\n", x, y, raio);

    // 4. Cálculo da área
    printf("\nÁrea do círculo: %.2f\n", area_circulo(meuCirculo));

    // 5. Verificação de ponto (dados fornecidos pelo usuário)
    printf("\nDigite as coordenadas de um ponto para teste (x y): ");
    scanf("%f %f", &ponto_x, &ponto_y);
    if (dentro_circulo(meuCirculo, ponto_x, ponto_y)) {
        printf("O ponto (%.1f, %.1f) está DENTRO do círculo.\n", ponto_x, ponto_y);
    } else {
        printf("O ponto (%.1f, %.1f) está FORA do círculo.\n", ponto_x, ponto_y);
    }

    // 6. Liberação de memória
    libera_circulo(meuCirculo);
    printf("\nMemória do círculo liberada.\n");

    return 0;
}