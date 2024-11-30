#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define ERROR -INT_MAX

typedef struct {
  int peek;
  int size;
  int *array;
} Stack;

int empty (Stack *s) {
  return (s->peek == 0);	
}

int full (Stack *s) {
  return (s->peek == s->size);	
}

Stack *create (int size) {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->peek = 0;
  s->size = size;
  s->array = (int *)malloc(size * sizeof(int));
  return s;
}

void push (Stack *s, int elem) {
  if (full(s)) {
    printf ("error: stack overflow!\n");
    exit(1);
  }	  
  s->array[s->peek] = elem;
  s->peek++;
}

int pop (Stack *s) {
  if (empty(s)) {
    printf ("error: stack underflow!\n");
    exit(1);
  }	  
  s->peek--;
  return s->array[s->peek];
}

int get_peek (Stack *s) {
  if (!empty(s)) 
    return s->array[s->peek-1];	  
  else 
    return ERROR;
}


void print (Stack *s) {
  int i;
  printf("Stack (peek): ");
  for (i = s->peek-1; i >= 0; i--) {
    printf ("%d ", s->array[i]);	  
  }
  printf("\n");
}

void destroy (Stack *s) {
  free (s->array);
  free (s);
}

int get_size (Stack *s) {
  return s->size;
}

int main () {
  int tam = 6;
  Stack *s = create (tam);
  srand(time(NULL));
  int i;
  for (i = 0; i < tam; i++) {
    push (s, rand()%10);
  }
  print (s);
  /*TERMINAR*/
  destroy (s);
}
