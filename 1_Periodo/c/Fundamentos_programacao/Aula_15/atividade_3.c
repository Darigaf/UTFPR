#include <stdio.h>
int tira_repeticoes(int numeros[], int tamanho_vetor, int numeros_unicos[]){
	int qnt_numeros_unicos = 0;
	numeros_unicos[0] = numeros[0];
	qnt_numeros_unicos++;
	for(int i = 1; i < tamanho_vetor; i++){
		for(int j = i; j >= 0; j--){
			 if(numeros_unicos[i] != numeros[j]){
				numeros_unicos[qnt_numeros_unicos] = numeros[j];
				qnt_numeros_unicos++;
			 }
		}
	}
	return qnt_numeros_unicos;
}
		
int main(){

	int tamanho_vetor = 20;
	int numeros[20] = {3, 4, 1, 9, 0, 3, 2, 1, 5, 65, 1, 0}, numeros_unicos[20];
	printf("%d", tira_repeticoes(numeros, tamanho_vetor, numeros_unicos));
	return 0;
}
	
	
