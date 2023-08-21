#include <stdio.h>
#define N 6
		
int main(){
	int i, j, qnt_pretos;
	int tabuleiro [N][N] = {{0,0,1,0,0,0},
				{1,9,9,9,9,9},
				{0,9,9,9,9,9},
				{0,9,9,9,9,9},
				{1,9,9,9,9,9},
				{1,9,9,9,9,9}};
	for(i = 1; i < N; i++){
		for(j = 1; j < N; j++){
			qnt_pretos = 0;
			qnt_pretos += tabuleiro[i-1][j-1];
			qnt_pretos += tabuleiro[i][j-1];
			qnt_pretos += tabuleiro[i-1][j];
			if(qnt_pretos > 1){
				tabuleiro[i][j] = 0;
			}
			else{
				tabuleiro[i][j] = 1;
			}
						
		}
	}
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%d", tabuleiro[i][j]);
		}
			printf("\n");
	}

	return 0;
}
	
	
