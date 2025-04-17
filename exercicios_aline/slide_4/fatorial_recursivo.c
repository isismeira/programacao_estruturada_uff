#include <stdio.h>

int fat (int n);

int main() {
    int f = fat(5);
    printf("%i", f);
    return 0;
}

int fat (int n) {
    if (n==0) {
        return 1;
    } else {
        return n*fat(n-1);
    }
}