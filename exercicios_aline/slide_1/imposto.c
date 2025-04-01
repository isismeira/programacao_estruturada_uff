#include <stdio.h>

void exibir_desconto(float salario);

int main()
{
    float salario;

    printf("Digite aqui seu salario: ");
    scanf("%f", &salario);

    exibir_desconto(salario);

    return 0;
}

void exibir_desconto(float salario)
{
    float desconto;
    if (salario <= 1499.14){
        printf("Você está isento de IR");
    }
    else if (salario <= 2246.75){
        desconto = (salario * 0.075) - 112.44;
        printf("O desconto de IR será %f", desconto);
    } 
    else if (salario <= 2995.70){
        desconto = (salario * 0.15) - 280.94;
        printf("O desconto de IR será %f", desconto);
    }            
    else if (salario <= 3743.20){
        desconto = (salario * 0.225) - 505.62;
        printf("O desconto de IR será %f", desconto);
    }
    else{
        desconto = (salario * 0.275) - 692.78;
        printf("O desconto de IR será %f", desconto);
    }            
}