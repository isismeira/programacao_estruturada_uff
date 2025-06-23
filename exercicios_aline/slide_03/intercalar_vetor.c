#include <stdio.h>

// dúvida: usar sizeof dentro de um função 

void intercalar_vetor(int vetor_a[], int vetor_b[]);

int main()
{
    int vetor_a[4] = {1,2,3,4};
    int vetor_b[6] = {10, 20, 30, 40, 50, 60};

    intercalar_vetor(vetor_a, vetor_b);

    return 0;
}

void intercalar_vetor(int vetor_a[], int vetor_b[])
{
    int vetor_c[10] = {0};
    
    int contador_a = 0;
    for (int i = 0; i < 4; i++) {
        vetor_c[contador_a] = vetor_a[i];
        contador_a += 2;
    }

    for (int i = 0;  i < 6; i++){
        for (int j = 0; j < 10; j++){
            if (vetor_c[j] == 0) {
                vetor_c[j] = vetor_b[i];
                break;
            }
        }
    }

    printf("Vetor C =");
    for (int i = 0; i < 10; i++){
        printf(" %i", vetor_c[i]);
    }
}
