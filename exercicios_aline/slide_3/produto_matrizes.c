#include <stdio.h>

void produto_matrizes(int l1, int c1, int matriz_a[l1][c1], int l2, int c2, int matriz_b[l2][c2], int matriz_c[l1][c2]);

int main()
{
    int l1 = 3;
    int c1 = 2;
    int l2 = 2;
    int c2 = 3;

    int matriz_a[l1][c1] = {{1,2},{3,4},{5,6}}; // em compiladores mais antigos, (como o gcc em modo C89 ou C90), não aceita VLA (Variáveis como Tamanho de Matriz).

    int matriz_b[l2][c2] = {{7,8,9},{10,11,12}};

    int matriz_c[l1][c2];                      

    produto_matrizes(l1,c1,matriz_a,l2,c2,matriz_b,matriz_c);
}

void produto_matrizes(int l1, int c1, int matriz_a[l1][c1], int l2, int c2, int matriz_b[l2][c2], int matriz_c[l1][c2])
{
    if (c1 == l2) {
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < c2; j++) {
                matriz_c[i][j]  = 0;
                for (int k = 0; k < c1; k++) {
                    matriz_c[i][j] += matriz_a[i][k] * matriz_b[k][j];
                }
            }
        }
    }

    for (int i = 0; i < l1; i++){
        for (int j=0; j < c2; j++) {
            printf("%i ", matriz_c[i][j]);
        }
        printf("\n");
    }
}