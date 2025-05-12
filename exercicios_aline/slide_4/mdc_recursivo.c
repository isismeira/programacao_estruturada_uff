#include <stdio.h>

int mdc(int x, int y);

int main() {
    int a = 48, b = 18;
    printf("MDC de %d e %d é %d\n", a, b, mdc(a, b));
    return 0;
}

int mdc(int x, int y) {
    if (y <= x && x % y == 0) {
        return y;
    } else if (x < y) {
        return mdc(y, x);
    } else {
        return mdc(y, x % y);
    }
}
    