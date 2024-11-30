#include "stack.h"

/*int parser (char *c) {
	Stack *aberto = create(strlen(c));
	int i = 0;
	while (c[i] != '\0') {
		if(c[i] == ' '){
			continue;
		}
		if(c[i] == '('){
			push(aberto, c[i]);	
			continue;
		}
		if(c[i] == '['){
			push(aberto, c[i]);	
			continue;
		}
		if(c[i] == ')'){
			if(empty(aberto)){
				return 0;
			}
			/*
			if(pop(aberto) == '('){
				continue;
			}
			/
			if(get_peek(aberto) == '('){
				pop(aberto);
				continue;
			}
		}
		if(c[i] == ']'){
			if(empty(aberto)){
				return 0;
			}
			/*if(pop(aberto) == '['){
				continue;
			}
			/
			if(get_peek(aberto) == '['){
				pop(aberto);
				continue;
			}
			return 0;
		}
		i++;    
	}
	return 1;
}
*/
int parser(char *c) {
    Stack *aberto = create(strlen(c)); // Criação da pilha
    int i = 0;

    while (c[i] != '\0') {
        // Ignorar espaços em branco
        if (c[i] == ' ') {
            i++;
            continue;
        }

        // Se for um caractere de abertura, empurre para a pilha
        if (c[i] == '(' || c[i] == '[') {
            push(aberto, c[i]);
        } 
        // Se for um caractere de fechamento
        else if (c[i] == ')' || c[i] == ']') {
            // Verifique se a pilha está vazia
            if (empty(aberto)) {
                return 0; // Sequência mal formada
            }

            // Verifique se o topo da pilha é o caractere correspondente de abertura
            if ((c[i] == ')' && get_peek(aberto) == '(') || (c[i] == ']' && get_peek(aberto) == '[')) {
                pop(aberto); // Remova o topo da pilha
            } else {
                return 0; // Sequência mal formada
            }
        }
        i++; // Avança para o próximo caractere
    }

    // Se a pilha estiver vazia no final, a sequência está bem formada
    return empty(aberto) ? 1 : 0;
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
