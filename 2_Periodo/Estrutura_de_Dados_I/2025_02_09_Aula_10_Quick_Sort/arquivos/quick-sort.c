#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

/* */
int partition (int A[], int left, int right) {
	int i, j, aux, pivot;
	pivot = A[right];
	i = (left-1);
	
	for(j = left; j <= (right - 1); j++){
		if(A[j] <= pivot){
			i++;
			aux = A[j];
			A[j] = A[i];
			A[i] = aux;
		}

	}	
	aux = A[i+1];
	A[i+1] = A[right];
	A[right] = aux;

	return i+1;

}

/* */
void quick_sort (int *A, int left, int right) {
	int pivot;
	if(left < right){
		pivot = partition(A, left, right);
		quick_sort(A, left, pivot-1);
		quick_sort(A, pivot+1, right);
	}
}

/* */
int main (int argc, char *argv[]) {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  if (argc < 2) {
    printf("run: %s [size]\n", argv[0]);
    exit(1);
  }

  int i;
  int n = atoi(argv[1]);;
  int range = 10; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
  	A[i] = rand() % (n+1); /*valores aleatórios*/
  //A[i] = i; /*ordem crescente*/
  //A[i] = n-i; /*ordem descrente*/
  //A[i] = 0; /*iguais*/
  }




  start = clock();
  print (A, n, "Input");
  quick_sort (A, 0, n-1);
  print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  return 0;
}

