#include "stack.h"

int parser (char *c) {
	Stack *aberto = create(strlen(c));
	int i = 0;
	while (c[i] != '\0') {
		if(c[i] == ' '){
			i++;
			continue;
		}
		if((c[i] == '(') || (c[i] == '[')){
			push(aberto, c[i]);	
			i++;
			continue;
		}
		if(c[i] == ')'){
			if(get_peek(aberto) == '('){
				pop(aberto);
				i++;
				continue;
			}
			return 0;
		}
		if(c[i] == ']'){
			if(get_peek(aberto) == '['){
				pop(aberto);
				i++;
				continue;
			}
			return 0;
		}
		i++;    
	}
	if(!(empty(aberto))){
		return 0;	
	}
	return 1;
}

int main () {
  //char *c = "( ( ) [ ( ) ] )";
  //char *c = "( [ ) ]";
  //char *c = "( ) [ ]";
  //char *c = "( [ ]";
  //char *c = ") (";
  char *c = "()";
  if (parser(c)) 
    printf("true  (bem formada)\n");
  else  
    printf("false (mal formada)\n");
  return 0;
}
