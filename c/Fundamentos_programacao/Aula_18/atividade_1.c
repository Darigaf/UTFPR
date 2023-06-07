#include <stdio.h>
#define N 4
		
void geraMatrizInca (int matriz [N][N]){
	int esquerda, direita, cima, baixo, contador_casas, i,j;
	direita = N-1;
	baixo = N;
	contador_casas = 1;
	int volta = 0;
	i =0;
	j=0;
	while(contador_casas<(N*N)){
		while(j < N-volta){
			matriz[i][j] = contador_casas;
			contador_casas++;
		       	j++;
		}
		direita--;
		while(i < N-volta){
			matriz[i][j] = contador_casas;
			contador_casas++;
			i++;
		}
		i--;
		baixo--;
		while(j > volta+0){
			j--;
			matriz[i][j] = contador_casas;
			contador_casas++;
		}
		while(i > volta+0){
			matriz[i][j] = contador_casas;
			contador_casas++;
			i--;
		}
		i++;
		volta++;
	}
		
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%d\t", matriz[i][j]);
		}
			printf("\n");
	}
}

int main(){
	int matriz[N][N];
	geraMatrizInca(matriz);

	return 0;
}
	
	
