#include <stdio.h>

// observação: revisar

int main()
{
    int ch;
    while ((ch = getchar()) !=  EOF) {
        if (ch >= 32 && ch <= 127) {
            if (ch >= 'a' && ch <= 'z') {
                ch = ch - ('a' - 'A');
            }
            putchar(ch);
        }
    }

    return 0;
}