#include "list.h"

/* */
int sum (List *l) {
	List *temp;
	int sum_total = 0;
	for(temp = l; temp != NULL; temp = temp->next){ 
		sum_total += temp->data;
	}
	return sum_total;
}

/* */
int main () {
  int k;
  List *l = NULL;
  for (k = 0; k <= 4; k++) 
	l = insert_back (l, k);
//	l = insert (l, k);
  for (k = 9; k >= 5; k--) 
	l = insert_back (l, k);
//	l = insert (l, k);
  print (l);
  printf("Sum = %d\n", sum(l));
  destroy (l);
  return 0;
}
