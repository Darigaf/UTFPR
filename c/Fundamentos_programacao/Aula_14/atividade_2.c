#include <stdio.h>
#include <stdlib.h>
#define N 10
		
int main(){
	int aleatorios[N], posicao, i, tamanho_vetor;
	srand(time(NULL));
	for(i = 0; i < N; i++){
		aleatorios[i] = rand();
	}
	printf("{");
	for(i = 0; i < N; i++){
		printf("%d, ", aleatorios[i]);
	}
	printf("}");
	for(tamanho_vetor = N; tamanho_vetor > 0; tamanho_vetor--){
		scanf("%d", &posicao);
		if(posicao > tamanho_vetor)
			break;
		aleatorios[posicao] = 0;
		for(i = N; posicao < N; posicao++){
			aleatorios[posicao] = aleatorios[posicao+1];
		}
		printf("{");
		for(i = 0; i < N; i++){
			printf("%d, ", aleatorios[i]);
		}
		printf("}");
	}
	return 0;
}
	
	
