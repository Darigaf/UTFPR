#include <stdio.h>
		
void removeExtremos (int *n, int *pri, int *ult)
{
	int tn, pot = 1;

	tn = *n;
	while(tn >= 10)
	{
		tn = tn/10;
		pot *= 10;
	}

	*pri = *n / pot;
	*ult = *n % 10;
	*n = *n % pot;
	*n = *n / 10;
}

int main(){
	int numero, primeiro, ultimo, is_palindromo; 
	scanf("%d", &numero);
	is_palindromo = 1;
	while(numero >= 10 && is_palindromo == 1){
		removeExtremos(&numero, &primeiro, &ultimo);
		if(primeiro != ultimo)
			is_palindromo = 0 ;
	}
	if(is_palindromo){
		printf("numero é um palindromo");
	}
	else
		printf("numero não é um palindromo");


	return 0;
}
	
	
