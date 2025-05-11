#include <stdio.h>
#include <stdlib.h> //necessário para usarmos as funções "malloc", "calloc", "realloc" e "free"

/* casting: é o processo de converter um valor de um tipo de dado para outro
    int x = 16
    int y = 3
    float resultado = (float)x/y
*/

// sizeof(dado) retorna tamanho em bytes do tipo de dado


void malloc_e_free()
{
    // malloc(): pede ao SO um bloco de memória de uma tamanho que vamos especificar, retorna um ponteiro do endereço do bloco reservado.
    int *ponteiro = (int *) malloc(sizeof(int)); 

    if (ponteiro == NULL) {
        printf("'malloc' nao funcionou");
    }
    *ponteiro = 10;
    printf("%i", *ponteiro);

    // free() a memória vai permanecer reservada até o programa acabar ou quando a função free() for chamada
    free(ponteiro);
}

void calloc()
{
    // calloc(): trabalha com dois parâmetros sendo o primeiro que indica quantos elementos do tamanho do segundo parâmetros devemos separar 
    int *p = (int *) calloc(10, sizeof(int)); // obs. inicializa todos os valores com 0

    *(p) = 1;
    *(p+1) = 2;
    p[2] = 3;

    for (int i =0; i < 5; ++i){
        printf("Endereco de p%i = %p / Valor de p%i - %i\n", i, &p[i], i, *(p+i));
    }

    printf("%i", p[2]);

}

void realloc()
{
    // realloc(): pode ser necessário, durante a execução de um programa, alterar o tamanho de um bloco alocado
    int *ponteiro = (int *) malloc(sizeof(int));

    ponteiro = (int *) realloc(ponteiro, 20*sizeof(int));
}

int main()
{
    return 0;
}