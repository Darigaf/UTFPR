#include "list.h"

/* */
List* merge (List *A, List *B) {
	List *C = NULL, *temp_c = NULL;

	if((A != NULL)&&(B != NULL)){
		if(A->data < B->data){
			C->next = merge(A->next, B);
		}	
		if(A->data > B->data){
			C->next = merge(A, B->next);
		}	
		if(A->data == B->data){
			C->next = merge(A->next, B);
		}	
	}
	if(A == NULL){
		temp_c->next = B;
	}	
	if(B == NULL){
		temp_c->next = A;
	}	
	
	
	return C;
}

/* */
int main () {
  int k;
  List *A = NULL;
  for (k = 0; k <= 14; k += 2) {
    A = insert_back (A, k);
  }
  printf("Lista = ");
  print (A);
  printf("\n");

  List *B = NULL;
  for (k = 1; k <= 9; k += 2) {
    B = insert_back (B, k);
  }
  printf("Lista = ");
  print (B);
  printf("\n");

  List *C = merge (A, B);
  printf("Lista = ");
  print (C);
  printf("\n");

  destroy (C);
  return 0;
}


