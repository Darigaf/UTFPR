#include <stdio.h>
unsigned int inverteNum (unsigned int n){
	unsigned int invertido = 0;
	int aux;

	for(; n!=0; n=n/10){
		aux = n % 10;	
		invertido = invertido*10+aux;
	}
	return invertido;
}

int main(){
	unsigned int num;
	int invertido;
	scanf("%u", &num);
	invertido = inverteNum(num);
	printf("%d", invertido);
	
	return 0;
}
