#include "utils.h"

/*Função intercala*/
int merge(int A[], int l, int m, int r, int O[], int rlevel) {
  int i = l, j = m + 1, k = l;

  // Imprime os deslocamentos para indicar o nível de recursão
  for (int level = 0; level < rlevel; level++) {
    printf("  ");  // 2 espaços por nível
  }
  printf("Intercalando = {");
  for (int i = l; i <= r; i++) {
    printf("%d", A[i]);
    if (i < r) printf(", ");
  }
  printf("}\n");

  while (i <= m && j <= r) {
    if (A[i] <= A[j]) {
      O[k] = A[i];
      i++;
    } else {
      O[k] = A[j];
      j++;
    }
    k++;
  }

  while (i <= m) {
    O[k] = A[i];
    i++;
    k++;
  }

  while (j <= r) {
    O[k] = A[j];
    j++;
    k++;
  }

  for (i = l; i <= r; i++) {
    A[i] = O[i];
  }

  return 0;
}

/*Função principal do algoritmo Merge-Sort*/
void merge_sort(int A[], int l, int r, int O[], int rlevel) {
  // Imprime os deslocamentos para indicar o nível de recursão
  for (int level = 0; level < rlevel; level++) {
    printf("  ");  // 2 espaços por nível
  }
  printf("Merge-Sort (%d,%d,%d)\n", l, (l + r) / 2, r);

  if (l < r) {
    int m = (l + r) / 2;

    merge_sort(A, l, m, O, rlevel + 1);
    merge_sort(A, m + 1, r, O, rlevel + 1);

    merge(A, l, m, r, O, rlevel);
  }
}

int main() {
  clock_t start, end;
  double elapsed_time;
  int n = 8; /*quantidade de elementos*/
  int A[] = {5, 2, 7, 4, 8, 1, 9, 8};
  int O[n];  /*vetor auxiliar*/

  start = clock();
  print(A, n, "Input");
  merge_sort(A, 0, n - 1, O, 0);
  print(A, n, "Sorted");
  end = clock();

  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);

  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }

  return 0;
}

