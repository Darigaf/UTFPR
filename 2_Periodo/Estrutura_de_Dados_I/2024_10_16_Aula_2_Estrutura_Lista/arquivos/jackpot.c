#include "queue.h"
#include <time.h>

int verify_win(Queue** carreteis, int rows){
	int first_value = front(carreteis[0]);
	for(int i = 1; i < rows; i++){
		if(front(carreteis[i]) != first_value){
			return 0;
		}
	}
	printf("==========================================\n");
	for(int i = 0; i < rows; i++){
		print(carreteis[i]);
	}
	printf("PARABÉNS, VOCÊ GANHOU 5 BITCOINS\n");
	return 1;
}
void shuffle(Queue** carreteis, int rows){
	for(int i = 0; i < rows-1; i++){
		int shuffle_iterations = (rand()%100);	
		for(int j = 0; j < shuffle_iterations; j++){
			enqueue(carreteis[i], dequeue(carreteis[i]));
		}
	}
	
}

void jackpot (int n, int r) {
	Queue **carreteis = (Queue **)malloc(n * sizeof(Queue*));
	for(int i = 0; i <= n; i++){
		carreteis[i] = create(r);
	}
	for(int i = 0; i <= n; i++){
		for(int j = 1; j < r; j++){
			enqueue(carreteis[i], j);
		}
	}
	for(int i = 0; i < n; i++){
		print(carreteis[i]);
	}
	shuffle(carreteis, n);
	while(!verify_win(carreteis, n)){
		shuffle(carreteis, n );

		for(int i = 0; i < n-1; i++){
			print(carreteis[i]);
		}
	}
}

int main () {
  srand(time(NULL));	
  int n = 3;  /*número de carretéis*/ 
  int r = 10; /*sequência de números em cada carretel*/ 
  jackpot (n, r);
}
