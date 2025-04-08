#include <stdio.h>

int main()
{
    int lancamentos;
    printf("Quantas vezes voce vai lancar o dado?");
    scanf("%i", &lancamentos);
    
    int vetor[6] = {0};
    printf("Agora, digite qual numero caiu em cada lancamento: \n");
    for (int i = 0; i < lancamentos; i++){
        int valor;
        scanf("%i", &valor);
        vetor[(valor-1)]++;
    }
    printf("Face 1: %i\nFace 2: %i\nFace 3: %i\nFace 4: %i\nFace 5: %i\nFace 6: %i", vetor[0], vetor[1], vetor[2], vetor[3], vetor[4], vetor[5]);
}