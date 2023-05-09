#include <stdio.h>

double resto(double valor){

	valor = (valor - (int) valor);
	return valor;
}

int main(){
	double valor;
	scanf("%lf", &valor);
	valor = resto(valor);
	printf("%.3lf", valor);
	return 0;
}
