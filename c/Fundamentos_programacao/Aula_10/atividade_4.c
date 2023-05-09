#include <stdio.h>

int main(){
	int horizontal, vertical, tamanho;
	char letra = 'A';
	scanf("%d", &horizontal);
	letra += horizontal;
	vertical = horizontal;
	for(int i = 0; i < vertical; i++){
		letra --;
		for(int j = horizontal; j > 0; j--){
			printf("%c ", letra);
		}
		printf("\n");
		horizontal --;
	}	

	return 0;
}
