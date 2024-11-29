#include "list.h"
#include <stdio.h>

List* merge (List *A, List *B){
	List *temp_a = A, *temp_b = B, *C=NULL, *temp_c=NULL;
	if(temp_a == NULL){
		return B;
	}
	if(temp_b == NULL){
		return A;
	}
	if(A->data < B->data){
//		printf("A menor B\n");
//		printf("%d menor %d\n", A->data, B->data);
		C = A;
		temp_a = temp_a->next;;
	}
	if(A->data > B->data){
	//	printf("A maior B\n");
	//	printf("%d menor %d\n", A->data, B->data);
		C = B;
		temp_b = temp_b->next;;
	}	
	if(A->data == B->data){
	//	printf("A igual B\n");
	//	printf("%d igual %d\n", A->data, B->data);
		C = A;
		temp_a = temp_a->next;;
	}
	temp_c = C;
	while(temp_a != NULL && temp_b != NULL){
		if(temp_a->data < temp_b->data){
			temp_c->next	= temp_a;
			temp_c = temp_c->next;
			temp_a = temp_a->next;
			continue;
		}
		if(temp_a->data > temp_b->data){
			temp_c->next	= temp_b;
			temp_c = temp_c->next;
			temp_b = temp_b->next;
			continue;
		}	
		if(temp_a->data == temp_b->data){
			temp_c->next = temp_a;
			temp_c = temp_c->next;
			temp_a = temp_a->next;
		}


	}
  	print (C);
//	print("FORA\n");
	if(temp_a == NULL){
		temp_c->next = temp_b;
	}
	if(temp_b == NULL){
		temp_c->next = temp_a;
	}
//	print("FORA2\n");
   //	print (C);
	return C;
}

/**/
int main () {
  int k;
  List *A = NULL, *B = NULL;
  for (k = 10; k >= 0; k -= 2) 
    A = insert (A, k);
  for (k = 19; k >= 0; k -= 2) 
    B = insert (B, k);
  print (A);
  print (B);
  List *C = merge (A, B);
  print (C);
  destroy (C);
  return 0;
}
