/*
Coloque aqui o seu nome
*/

#include <stdio.h>
#define N 11

int ehValido(int *cpf){
	int digito = 0;
	int posicao = 0;
	for(int i = 10; i >= 2; i--){
		
		digito += (cpf[]*posicao);
		posicao++;	
	}
	digito = digito % 11;
	if(digito < 2){
		digito = 0;
	}
	else{
		digito = 11 - digito;
	}
	return 1;
}

int main()
{

    int cpf[N] = {1,2,3,4,5,6,7,8,9,0,0};

    if(eh_Valido(&cpf))
        printf("Eh valido");
    else
        printf("Nah eh valido");

    return 0;
}
