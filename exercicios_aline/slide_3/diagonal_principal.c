#include <stdio.h>

void multiplicar_diagonal(int l, int c, int m[l][c], int k);

int main()
{
    int m[3][3] = {{1,2,3},
               {4,5,6}, 
               {7,8,9}};

    int k = 2;
    multiplicar_diagonal(3,3,m,k);
    return 0;
}

void multiplicar_diagonal(int l, int c, int m[l][c], int k)
{
    for (int i = 0; i < l; i ++) {
        m[i][i] = m[i][i] * k;
    }
    for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++) {
            printf("%i ", m[i][j]);
        }
        printf("\n");
    }
}