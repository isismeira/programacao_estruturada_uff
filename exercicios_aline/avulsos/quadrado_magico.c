#include <stdio.h>
#include <stdlib.h>

int **alocar_matriz(int l, int c) {
    int **matriz;
    matriz = (int **) malloc (l * sizeof(int*));
    for (int i = 0; i < l; i++) {
        matriz[i] = (int *) malloc (c * sizeof(int));
    }
    return matriz;
} 

void ler_matriz(int **matriz, int l, int c){
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("Digite o elemento da linha %i e coluna %i:", l, c);
            scanf("%i", &matriz[i][j]);
        } 
    }
}

void somatorio_submatrizes(int qtdd_submatrizes, int *somas_submatrizes, int **matriz, int l, int c) {
        for (int i = 0; i < l; i += 2) {
        for (int j = 0; j < c; j += 2) {
            if (((i + 1) < l) && ((j + 1) < c )) {
                int primeiro = matriz[i][j];
                int segundo =  matriz[i + 1][j];
                int terceiro = matriz[i][j+1];
                int quarto = matriz[i + 1][j + 1];
                int soma = primeiro + segundo + terceiro + quarto;
                somas_submatrizes[qtdd_submatrizes] = soma;
                qtdd_submatrizes++;
            }
        }
    }
}

void somatorio_linhas(int *somas_linhas, int **matriz, int l, int c) {
    for (int i = 0; i < l; i++){
        int soma_da_linha = 0;
        for (int j = 0; j < c; j++) {
            soma_da_linha += matriz[i][j];
        }
        somas_linhas[i] = soma_da_linha;
    }
}

void somatorio_colunas(int *somas_colunas, int **matriz, int l, int c) {
    for (int j = 0; j < c; j++) {
        int soma_da_coluna = 0;
        for (int i = 0; i < l; i++) {
            soma_da_coluna += matriz[i][j];
        }
        somas_colunas[j] = soma_da_coluna;
    }  
}

void somatorio_diagonais(int *somas_diagonais,int **matriz,int l,int c) {
    int diagonal_esquerda = 0;
    for (int i = 0; i < l; i++) {
        diagonal_esquerda += matriz[i][i]; 
    }
    somas_diagonais[0] = diagonal_esquerda;

    int diagonal_direita = 0;
    for (int i = 0; i < l; i++) {
        for (int j = c - 1; j >= 0; j--){
            diagonal_direita += matriz[i][j];
        }
    }
    somas_diagonais[1] = diagonal_direita;
}

int main()
{
    int l, c;
    printf("Digite o numero de linhas e colunas");
    scanf("%i %i", &l, &c);

    int matriz = alocar_matriz(l, c);
    ler_matriz(matriz, l, c);

    int qtdd_submatrizes = 0;
    int somas_submatrizes[20];
    int somas_linhas[l];
    int somas_colunas[c];
    int somas_diagonais[2];

    somatorio_submatrizes(qtdd_submatrizes, somas_submatrizes, matriz, l, c);
    somatorio_linhas(somas_linhas, matriz, l, c);
    somatorio_colunas(somas_colunas, matriz, l, c);
    somatorio_diagonais(somas_diagonais, matriz, l, c);


    if (somas_diagonais[0] != somas_diagonais) {
        printf("Nao eh quadrado magico");
        return 0;
    } else {
        for (int i = 1; i < l; i++) {
            if (somas_linhas[0] != somas_linhas[i]) {
                printf("Nao eh quadrado magico");
                return 0;
            }
            if(somas_colunas[0] != somas_colunas[i]) {
                printf("Nao e quadrado magico");
                return 0;
            }
        }
    }

    for (int i = 0; i < 20; i++) {
        if (somas_submatrizes[0] != somas_submatrizes[i]) {
            printf("Nao e quadrado magico");
            return 0;
        }
    }

    if (somas_submatrizes[0] != somas_linhas[0] != somas_colunas[0] != somas_diagonais[0]) {
        printf("Nao e quadrado magico");
        return 0 ;
    }

    printf("Eh quadrado magico!");
}