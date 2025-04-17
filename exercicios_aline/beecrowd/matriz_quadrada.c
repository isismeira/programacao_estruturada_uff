#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0)
            break;

        int matrix[100][100];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int value = min(min(i, j), min(n - 1 - i, n - 1 - j)) + 1;
                matrix[i][j] = value;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0)
                    printf("%3d", matrix[i][j]);
                else
                    printf(" %3d", matrix[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}

int min(int a, int b) {
    return a < b ? a : b;
}