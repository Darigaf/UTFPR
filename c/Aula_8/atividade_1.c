#include <stdio.h>

int main(){
	int numero;
	scanf("%d", &numero);

	int i = 0;
	while(numero!=1){

		if(numero%2==0){
			numero /= 2;
		}
		else{
			numero = (numero*3)+1;
		}
		printf("%d → ", numero);
		i++;

	}
	printf("\nForam gerados %d", i+1);
	return 0;
}
