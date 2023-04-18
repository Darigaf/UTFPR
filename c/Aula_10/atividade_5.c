#include <stdio.h>

int main(){
	int largura_meio, largura;
	scanf("%d", &largura);

	largura_meio = (largura*2)+1;

	for(int i = largura; i > 0; i--){
		for(int j = 0; j > largura; i++){
			printf(" ");
		}
		printf("#");
	}

	return 0;
}
