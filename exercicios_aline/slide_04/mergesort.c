#include <stdio.h>

void merge_sort(int a[], int len);
void recursao_merge_sort(int a[], int esq, int dir);
void juntar_arrays(int a[], int esq, int meio, int dir);

int main()
{
  int array[] = { 9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
  int len = 10;
  
  merge_sort(array, len);
  
  for (int i = 0; i < len; i++)
    printf("%d ", array[i]);
  printf("\n");
  
  return 0;
}

void merge_sort(int a[], int len)
{
  recursao_merge_sort(a, 0, len - 1); // chamamos a função recursiva para o array todo
}

void recursao_merge_sort(int a[], int esq, int dir)
{
  if (esq < dir) // paramos a recursão quando esq >= dir
  {
    int meio = esq + (dir - esq) / 2;
  
    recursao_merge_sort(a, esq, meio); // primeira metade
    recursao_merge_sort(a, meio + 1, dir); // segunda metade
  
    juntar_arrays(a, esq, meio, dir); // após as duas partes estarem ordenadas, juntá-las 
  }
}

void juntar_arrays(int a[], int esq, int meio, int dir)
{
  int len_esq = meio - esq + 1;
  int len_dir = dir - meio;

  int temp_esq[len_esq];
  int temp_dir[len_dir];
  
  // i percorre temp_esq, j percorre temp_dir, k percorre o array original
  int i, j, k;
  
  // aqui, fazemos duas cópias temporárias, uma da primeira metade e outra da segunda metade
  for (int i = 0; i < len_esq; i++)
    temp_esq[i] = a[esq + i];
  
  for (int i = 0; i < len_dir; i++)
    temp_dir[i] = a[meio + 1 + i];
  
  // nesse loop, a cada "rodada", o menor dos números de temp_esq ou temp_dir, entra pro array original e avança um índice  
  for (i = 0, j = 0, k = esq; k <= dir; k++)
  {
    // se ainda há elementos na esquerda e esgotamos os da direita 
    // ou o valor atual da esquerda é menor ou igual ao da direita
    if ((i < len_esq) && (j >= len_dir || temp_esq[i] <= temp_dir[j])) {
      a[k] = temp_esq[i]; // escolhemos o elemento da esquerda
      i++; // avançamos i
    }

    else // caso contrário...
    {
      a[k] = temp_dir[j]; // escolhemos o elemento da direita 
      j++; // avançamos j
    }
  }  
}


/*  Visualização do algoritmo MergeSort:

          [38, 27, 43, 3, 9, 82, 10]
                     /   \
       [38, 27, 43, 3]   [9, 82, 10]
        /         |         |      \
   [38, 27]    [43, 3]   [9, 82]   [10]
    /   |      /    |    /    \      |
 [38]  [27]  [43]  [3]  [9]   [82]  [10]
    \  /       \   /     \     /     |
   [27, 38]    [3, 43]   [9, 82]    [10]
       \         /          \        /
     [3, 27, 38, 43]        [9, 10, 82]
           \                  /
          [3, 9, 10, 27, 38, 43, 82]           */