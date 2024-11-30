#include "queue.h"
#include <time.h>

int main () {
  int iter = 0;	
  int size = 10;	
  Queue *p = create(size);
  Queue *i = create(size);
  srand(time(NULL));
  while (iter < size) {
    int sorteio = rand() % 30;
    if (sorteio % 2)
       enqueue (i, sorteio);
    else    
       enqueue (p, sorteio);
    iter++;
  }
  print (p);
  print (i);
  destroy (p);
  destroy (i);
  return 0;
}
