#include "list.h"
#include <limits.h>

/* */
int position (List *l, int k) {
	if(l == NULL){
		return -1;
	}
	if(l->data == k){
		return 0;
	}
	int pos = position(l->next,k);
	
	if(pos == -1){
		return -1;
	}
	return pos + 1;
}

/* */
int main () {
  List *l = NULL;
  int k;
  for (k = 6; k <= 9; k++) {
    l = insert_back (l, k);
  }
  for (k = 4; k >= 0; k--) {
    l = insert_back (l, k);
  }
  printf("Lista = ");
  print (l);
  printf("\n");
  printf("Position of %d = %d\n", 9, position(l, 9));
  printf("Position of %d = %d\n", 10, position(l, 10));
  destroy (l);
  return 0;
}
