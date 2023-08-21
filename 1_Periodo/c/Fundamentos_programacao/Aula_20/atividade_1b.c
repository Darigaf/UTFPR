#include <stdio.h>
		
typedef struct{
	float menor;
	float maior;
	float meio;
} MaMeMe;
void classifica(MaMeMe *valores){
	if(n2 > valores->maior){
		valores->maior = n2;
	}
	if(n3 > valores->maior){
		valores->maior = n3;
	}
	if(n2 < valores->menor){
		valores->menor = n2;
	}
	if(n1 < valores->menor){
		valores->menor = n1;
	}
	if(n1 > valores->menor && n1 < valores->maior){
		valores->meio = n1;
	}
	if(n2 > valores->menor && n2 < valores->maior){
		valores->meio = n2;
	}
	if(n3 > valores->menor && n3 < valores->maior){
		valores->meio = n3;
	}

		
}


int main(){
	MaMeMe valores;
	valores.maior = 430.32;
	valores.menor = 484.32;
	valores.meio = 394.32;
	classifica(&valores);

	printf("maior = %f", valores.maior);
	printf("meio = %f", valores.meio);
	printf("menor = %f", valores.menor);

	return 0;
}
	
	

