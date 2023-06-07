#include <stdio.h>
int analisa (int*** in, int largura, int altura, int** out){
	avaliaDado(in[1][1]

}

int avaliaDado(int* rolagens, int n){
	int valores[6], i, resultado;
	for(i = 0; i < 6; i++){
		valores[i] = 0;
	}
	for(i = 0; i < n; i++){
		resultado = rolagens[i];
		resultado --;
		valores[resultado]++;
	}
	for(i = 0; i < 6; i++){
		if(valores[i] > 15 && valores[i] < 18){
			return 0;	
		}
	}
			return 1;
}

int main(){

	return 0;
}
	
	
