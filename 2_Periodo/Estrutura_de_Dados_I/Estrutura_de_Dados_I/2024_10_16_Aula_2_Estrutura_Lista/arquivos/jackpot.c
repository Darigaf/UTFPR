#include "queue.h"
#include <time.h>
int verify_win(**Queue){
	
}
void shuffle(Queue *carretel){
	int iterations = rand()%100;
	for(int i = 0; i < iterations; i++){
		enqueue(dequeue(carretel));
	}	
}
void jackpot (int n, int r) {
	Queue **carreteis = (Queue **)malloc(n * sizeof(Queue*));
	for(int i = 0; i < n; i++){
		carreteis[i] = create(r);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < r; j++){
			enqueue(carreteis[i], j);
		}
	}
	while(!verify_win()){
		shuffle();
	}

}

int main () {
  srand(time(NULL));	
  int n = 3;  /*número de carretéis*/ 
  int r = 10; /*sequência de números em cada carretel*/ 
  jackpot (n, r);
}
