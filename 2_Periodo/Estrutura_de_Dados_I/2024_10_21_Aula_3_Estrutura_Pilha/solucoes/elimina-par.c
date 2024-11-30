#include "stack.h"
#include <time.h>

void elimina_par (Stack *s) {
  Stack *t = create (s->size);
  while (!empty(s)) {
    int e = pop (s);
    if (e % 2) {
      push (t, e);	    
    }
  }
  while (!empty(t)) {
    push (s, pop(t));	  
  }
}

int main () {
  srand(time(NULL));
  int tam = 6;
  Stack *s = create (tam);
  int i;
  for (i = 0; i < tam; i++) {
    push (s, rand()%10);
  }
  print (s);
  elimina_par (s);
  print (s);
  destroy (s);
}
