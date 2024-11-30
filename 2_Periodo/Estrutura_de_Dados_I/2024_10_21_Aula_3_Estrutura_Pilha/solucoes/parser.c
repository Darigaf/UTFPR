#include "stack.h"

int parser (char *c) {
  Stack *s = create(strlen(c));
  int i = 0;
  while (c[i] != '\0') {
    if ( (c[i] == '(') || (c[i] == '[') ) 
      push (s, c[i]);
    else {
      if (c[i] == ')') {
        if (empty(s) || pop(s) != '(') 
          return 0;	
      }	
      else if (c[i] == ']')
        if (empty(s) || pop(s) != '[') 
          return 0;	
    }
    i++;    
  }
  if (!empty(s)) { return 0; }
  else { return 1; }
}

int main () {
  //char *c = "( ( ) [ ( ) ] )";
  //char *c = "( [ ) ]";
  //char *c = "( ) [ ]";
  //char *c = "( [ ]";
  char *c = ") (";
  if (parser(c)) 
    printf("true  (bem formada)\n");
  else  
    printf("false (mal formada)\n");
  return 0;
}
