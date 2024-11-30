#include "queue.h"
#include <time.h>

void jkinsert (Queue *q, int r) {
  int i;
  for (i = 0; i < r; i++)
    enqueue (q, i);	  
}

void shuffle (Queue *q) {
  int i;	
  int r = rand() % 100;
  for (i = 0; i < r; i++) {
    enqueue (q, dequeue(q)); 	  
  }
}

int not_equal (Queue **q, int n) {
  int i;	
  for (i = 0; i < n-1; i++)
     if (front(q[i]) != front(q[i+1])) 	  
	return 1;     
  return 0;
}

void jackpot (int n, int r) {

  int i;
  
  Queue **q = (Queue **)malloc(n * sizeof(Queue *));

  for (i = 0; i < n; i++)
    q[i] = create (r+1); 	  

  for (i = 0; i < n; i++)
    jkinsert (q[i], r); 	 

  int ntries = 0; 
  
  do {
    for (i = 0; i < n; i++)
      shuffle (q[i]); 	  
    for (i = 0; i < n; i++)
      printf ("%d ", front(q[i]));	    
    printf ("\n");
    ntries++;
  } while (not_equal(q, n));

  for (i = 0; i < n; i++)
    destroy (q[i]);

  printf("Número de tentativas: %d\n", ntries);
}

int main () {
  srand(time(NULL));	
  int n = 6;  /*número de carretéis*/ 
  int r = 10; /*sequência de números em cada carretel*/ 
  jackpot (n, r);
}
