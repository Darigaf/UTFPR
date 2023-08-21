#include <stdio.h>
		
typedef struct{
	float menor;
	float maior;
	float meio;
} MaMeMe;
MaMeMe classifica(float n1, float n2, float n3){
	MaMeMe classificacao;
	int maior = n1;
	int menor = n3;
	int meio = n2;
	if(n2 > maior){
		maior = n2;
	}
	if(n3 > maior){
		maior = n3;
	}
	if(n2 < menor){
		menor = n2;
	}
	if(n1 < menor){
		menor = n1;
	}
	if(n1 > menor && n1 < maior){
		meio = n1;
	}
	if(n2 > menor && n2 < maior){
		meio = n2;
	}
	if(n3 > menor && n3 < maior){
		meio = n3;
	}

	classificacao.maior = maior;
	classificacao.menor = menor;
	classificacao.meio = meio;
	
	
		
	return classificacao;
}


int main(){
	MaMeMe valores_ordenados = classifica(2.3, 342.2, 0.1);
	printf("maior = %f", valores_ordenados.maior);
	printf("meio = %f", valores_ordenados.meio);
	printf("menor = %f", valores_ordenados.menor);

	return 0;
}
	
	

