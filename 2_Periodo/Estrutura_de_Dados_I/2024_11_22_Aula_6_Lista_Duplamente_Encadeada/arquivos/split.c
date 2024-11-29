#include "list.h"

List* split (List *l, List *x, List *y) {
  /*Terminar!*/	
	List *split_list = x;
	y->next->prev = x->prev;
	x->prev->next = y->next;
	y->next = NULL;
	x->prev = NULL;

	return split_list;
}

int main () {
  int i;	
  int n = 9;	
  List *l = create ();
  for (i = n; i >= 0; i--) {
    l = insert_front (l, i);
  }
  print (l);
  List *x = search (l, 3);
  List *y = search (l, 7);
  List *ls = split (l, x, y);
  print (l);
  print (ls);
  destroy (l);
  destroy (ls);
  return 0;
} 
