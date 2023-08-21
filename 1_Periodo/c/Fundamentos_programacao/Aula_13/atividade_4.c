#include <stdio.h>
		
int ehPardeFoolano (unsigned int n1, unsigned int n2){

	unsigned int digitos_n1 [10], digitos_n2 [10], i, digito;

	for(i=0; i < 9; i++){
		digitos_n1[i] = 0;
		digitos_n2[i] = 0;
	}
	while(n1){
		digito = n1%10;
		digitos_n1[digito] ++;
		n1 /= 10;
	}
	while(n2){
		digito = n2%10;
		digitos_n2[digito] ++;
		n2 /= 10;
	}
	for(i=0; i < 9; i++){
		if(digitos_n1[i] != digitos_n2[i]){
			return 0;
		}
		return 1;
	}
}
int main(){
	int n1, n2;
	//scanf("%d", &n1);
	//scanf("%d", &n2);
	n1 = 102;
	n2 = 201;
	printf("%d", ehPardeFoolano(n1, n2));
	return 0;
}
	
	
