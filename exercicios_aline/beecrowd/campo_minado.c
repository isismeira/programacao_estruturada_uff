#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int tabuleiro[50];
    for (int i = 0; i < N; i++) {
        scanf("%d", &tabuleiro[i]);
    }

    for (int i = 0; i < N; i++) {
        int minas = 0;

        if (i > 0 && tabuleiro[i - 1] == 1) {
            minas++;
        }

        if (tabuleiro[i] == 1) {
            minas++;
        }

        if (i < N - 1 && tabuleiro[i + 1] == 1) {
            minas++;
        }

        printf("%d\n", minas);
    }

    return 0;
}
