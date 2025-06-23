#include <stdio.h>

void runLengthEncoding(int arr[], int n) {
    int count = 1;

    for (int i = 1; i <= n; i++) {
        if (i < n && arr[i] == arr[i - 1]) {
            count++;
        } else {
            // Imprime a contagem seguida do número
            printf("%d %d ", count, arr[i - 1]);
            count = 1; // reinicia contagem
        }
    }

    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 5, 5, 5, 7, 7, 7, 7, 2, 2, 2, 0, 0, 0, 0, 9, 9, 9, 12, 12, 12, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    runLengthEncoding(arr, n);

    return 0;
}
