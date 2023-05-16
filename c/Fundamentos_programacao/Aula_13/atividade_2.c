#include <stdio.h>
#include <stdlib.h>
#define N 10
		
int main(){
	float valores [N], media;
	int i, qnt_positivos;
	srand(time(NULL));
	media = 0;
	qnt_positivos = 0;
	int maiores = 0;
	int menores = 0;
	for(i = 0; i < N; i++){
		valores[i] = ((rand()/(float)RAND_MAX)*80)-40; 
		if(valores[i] >= 0){
			media += valores[i];
			qnt_positivos ++;
		}
	}
	media = media/qnt_positivos;
	printf("A media é %.2f\n", media);
	for(i = 0; i < N; i++){
		if(valores[i] > media){
			printf("%.2f é maior que a media\n", valores[i]);
			maiores ++;
		}
		else if(valores[i] == media){
			printf("%.2f é igual a media\n", valores[i]);
		}
		else if(valores[i] > 0 && valores[i] < media){
			printf("%.2f é menor que a media\n", valores[i]);
			menores ++;
		}
	}

	printf("%d numeros são maiores que a media\n", maiores);
	printf("%d numeros são menores que a media\n", menores);

	return 0;
}
	
	
