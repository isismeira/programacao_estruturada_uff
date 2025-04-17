include <stdio.h>
include <math.h>
int num_digits(unsigned int num) { if (num == 0) return 1; // Para o número 0, há 1 dígito int length = 0; while (num > 0) { num /= 10; length++; } return length; }

int main() { unsigned short casos, qtsCaso = 4, ordem; unsigned short linha, coluna, qtsDigitosAtual, k; unsigned int maior;

scanf(&quot;%hu&quot;, &amp;casos);
while (casos--) {
    scanf(&quot;%hu&quot;, &amp;ordem);

    unsigned int matriz[ordem][ordem];

    // Preenche a matriz e já faz o quadrado do termo
    for (linha = 0; linha &lt; ordem; linha++) {
        for (coluna = 0; coluna &lt; ordem; coluna++) {
            unsigned int valor;
            scanf(&quot;%u&quot;, &amp;valor);
            matriz[linha][coluna] = valor * valor;
        }
    }

    // Imprime o cabeçalho
    printf(&quot;Quadrado da matriz #%hu:\n&quot;, qtsCaso);

    // Calcula a largura máxima de cada coluna
    for (coluna = 0; coluna &lt; ordem; coluna++) {
        maior = 0;
        for (linha = 0; linha &lt; ordem; linha++) {
            if (matriz[linha][coluna] &gt; maior) {
                maior = matriz[linha][coluna];
            }
        }
        // Acha o número de dígitos do maior elemento da coluna
        qtsDigitosAtual = num_digits(maior);

        // Imprime cada linha da matriz
        for (linha = 0; linha &lt; ordem; linha++) {
            if (coluna == 0 &amp;&amp; linha != 0) {
                printf(&quot;\n&quot;);
            }
            // Imprime o valor com o alinhamento correto
            if (coluna != 0) {
                printf(&quot; &quot;);
            }
            printf(&quot;%*u&quot;, qtsDigitosAtual, matriz[linha][coluna]);
        }
        printf(&quot;\n&quot;);
    }

    qtsCaso++;

    // Linha em branco condicional
    if (casos &gt; 0) {
        printf(&quot;\n&quot;);
    }
}

return 0;
}