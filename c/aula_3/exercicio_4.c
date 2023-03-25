#include <stdio.h>
#include <stdlib.h>

int main(void){
	int ano_atual = 0;
	int ano_nascimento = 0;
	int idade = 0;

	printf("Insira o ano atual com todos os 4 digitos\n");
	scanf("%d", &ano_atual);

	printf("Insira o seu ano de nascimento com todos os 4 digitos\n");
	scanf("%d", &ano_nascimento);

	idade = ano_atual - ano_nascimento;
	printf("Sua idade atual é de %d anos e ", idade);
	if(idade < 16){
		printf("você ainda não é um eleitor\n");
		return 0;
	}
	if(idade >= 18 && idade <= 65){
		printf("você é um eleitor obrigatório\n");
		return 0;
	}
	printf("você é um eleitor facultativo\n");

	return 0;
}
