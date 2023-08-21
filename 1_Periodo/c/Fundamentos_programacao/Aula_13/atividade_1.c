#include <stdio.h>
#include <stdlib.h>
#define N 10
		
int main(){
	int valores [N], media;
	int i;
	srand(321);
	media = 0;
	int maiores = 0;
	int menores = 0;
	for(i = 0; i < N; i++){
		valores[i] = (rand()%(80-20+1)+20); 
		media += valores[i];
	}
	media = media/N;
	printf("A media é %d\n", media);
	for(i = 0; i < N; i++){
		if(valores[i] > media){
			printf("%d é maior que a media\n", valores[i]);
			maiores ++;
		}
		else if(valores[i] == media){
			printf("%d é menor que a media\n", valores[i]);
			menores ++;
		}
		else{
			printf("%d é menor que a media\n", valores[i]);
		}
	}

	printf("%d numeros são maiores que a media", maiores);
	printf("%d numeros são menores que a media", menores);

	return 0;
}
	
	
