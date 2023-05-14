#include <stdio.h>

int main(){
	int numero, i, resultado;
	i = 0;	

	scanf("%d", &numero);
	resultado = numero;
	while(i < 10){
		printf("%d\n", resultado);
		resultado ++;
		i++;
	}
	resultado = numero;
	for(i = 1; i < 10; i++){
		printf("%d\n", resultado);
		resultado ++;
	}

	return 0;
}

