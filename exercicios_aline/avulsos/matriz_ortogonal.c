#include <stdio.h>
 
void ler_matriz(int l, int c, int matriz[l][c]);
void transposta(int l, int c, int matriz[l][c], int matriz_t[l][c]);
void identidade(int l, int c, int matriz_i[l][c]);
void produto(int l, int c, int matriz[l][c], int matriz_t[l][c], int matriz_produto[l][c]);
int compara_matrizes(int l, int c, int matriz_i[l][c], int matriz_produto[l][c]);

int main()
{
    int l, c;
    printf("Numero de linhas e colunas da matriz: ");
    scanf("%i %i", &l, &c);
    int matriz[l][c];
    int matriz_t[l][c];
    int matriz_i[l][c];
    int matriz_produto[l][c];
    ler_matriz(l,c,matriz);
    transposta(l,c,matriz,matriz_t);
    identidade(l,c,matriz_i);
    produto(l, c, matriz, matriz_t, matriz_produto);
    int resposta = compara_matrizes(l, c, matriz_i, matriz_produto);
    if (resposta) {
        printf("A matriz e ortogonal");
    } else {
        printf("A matriz nao e ortogonal");
    }
}

void ler_matriz(int l, int c, int matriz[l][c]){
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++){
      printf("Digite o número: ");
      scanf("%i", &matriz[i][j]);
  }}
}

void transposta(int l, int c, int matriz[l][c], int matriz_t[l][c])
{
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            matriz_t[j][i] = matriz[i][j];
        }
    }
}

void identidade(int l, int c, int matriz_i[l][c])
{
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (i == j) {
                matriz_i[i][j] = 1;
            } else {
                matriz_i[i][j] = 0;
            }
        }
    }
}

void produto(int l, int c, int matriz[l][c], int matriz_t[l][c], int matriz_produto[l][c])
{
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            matriz_produto[i][j] = 0;
            for (int k = 0; k < l; k++) {
                matriz_produto[i][j] += matriz[i][k] * matriz_t[k][j];
            }
        }
    }
}

int compara_matrizes(int l, int c, int matriz_i[l][c], int matriz_produto[l][c]) 
{
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (matriz_i[i][j] != matriz_produto[i][j]) {
                return 0; // não são iguais
                break;
            }
        }
    }
    return 1; // são iguais
}