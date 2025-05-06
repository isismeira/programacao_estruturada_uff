/*
    As declarações abaixo alocam espaço na memória para algumas variáveis. 
    A alocação é estática ou seja, acontece antes que o programa comece a ser executado:
        char c; 
        int i; 
        int v[10]; 

    Em muitas aplicações, a quantidade de memória a alocar só se torna conhecida durante a execução do programa. 
    Para lidar com essa situação é preciso recorrer à alocação dinâmica de memória. 
    A alocação dinâmica é administrada pelas funções malloc, realloc e free, que estão na biblioteca stdlib.
    Para usar essa biblioteca, inclua a correspondente interface no seu programa: 
       #include <stdlib.h>
*/