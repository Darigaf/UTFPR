#include "stack.h"

int main () {
	int tam = 6;
	Stack *s = create (tam);
	srand(time(NULL));
	int i;
	for (i = 0; i < tam; i++) {
		push (s, rand()%10);
	}
	print (s);


	Stack *temp = create(tam);

	while(!(empty(s))){
		if((get_peek(s)%2) == 0){
			push(temp, (pop(s)));
		}
		if((get_peek(s)%2) == 1){
			pop(s);
		}
	}
	while(!(empty(temp))){
			push(s, (pop(temp)));
	}
	print (s);

	/*TERMINAR*/
	destroy (s);
}
