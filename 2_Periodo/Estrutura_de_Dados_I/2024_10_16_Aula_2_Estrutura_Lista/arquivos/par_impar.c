#include "queue.h"
#include <time.h>
int main () {
	int i, n = 10, iteracoes = 0;
	int random_number;
	srand(time(NULL));

	Queue *par, *impar;
	par = create(n);	
	impar = create(n);	

	while(iteracoes <= n){
		iteracoes ++;
		random_number = rand() % 100;
		if((random_number%2) == 0){
			enqueue(par, random_number);
		}
		if((random_number%2) == 1){
			enqueue(impar, random_number);
	}
  }
  printf("Lista dos pares:");
  print(par);
  printf("\nLista dos impares:");
  print(impar);

  /*Use somente as operações definidas em queue.h*/
  /*Não use para resolver esse exercício o operador -> aqui!*/
  /*Terminar*/
  return 0;
}

