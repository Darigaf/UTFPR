#include <stdio.h>

unsigned long long potencia (unsigned int base, unsigned int expoente){
	int resultado;
	resultado = base;
	for(int i = expoente-1; i > 0; i--){
		resultado *= base;
	}
	return resultado;
}

int main(){
	int base, expoente;
	scanf("%d %d", &base, &expoente);
	printf("%llu", potencia(base, expoente));
	
	return 0;
}
