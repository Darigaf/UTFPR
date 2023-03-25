#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	float valor_inserido = 0;
	float resultado = 0;
	printf("Insira um número real positivo\n");
	scanf("%f", &valor_inserido);

	if(valor_inserido <= 0){
		printf("O valor inserido não pode ser computado pois não é um número positivo\n");
		return 0;
	}
	
	//resultado = sqrt(valor_inserido);
	//resultado = sqrt (valor_inserido);
	printf("A raíz de %.2f é aproximadamente %.2f\n", valor_inserido, sqrt(valor_inserido)); 

	return 0;
}
