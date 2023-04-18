#include <stdio.h>

int main(){
	int tamanho, n_1, n_2, n_3;
	scanf("%d", &tamanho);
	n_1 = 0;
	n_2 = 1;
	n_3 = (n_1+n_2);
	printf("%d, ", n_1);
	printf("%d, ", n_2);
	for(int i = 0; (tamanho-2) > i; i++){
		printf("%d, ", n_3);
		n_1 = n_2;
		n_2 = n_3;
		n_3 += n_1;
	}

	return 0;
}
