#include <stdlib.h>
#include <stdio.h>

int main()
{
	int valor_inserido = 0;
	printf("Digite um número inteiro não decimal e pressione a tecla ENTER\n");
	scanf("%d", &valor_inserido);

	if(valor_inserido >= 0){
		printf("O valor absoluto do número inserido é: %d\n", valor_inserido);
		return 0;
	}
	printf("O valor absoluto do número inserido é: %d\n", (valor_inserido * -1));

	return 0;
}
