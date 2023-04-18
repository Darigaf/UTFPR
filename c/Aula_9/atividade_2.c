#include <stdio.h>

int main(){
	int letras;
	char letra = 'A';
	scanf("%d", &letras);
	for(int i = 0; i < letras; i++){
		printf("%c", letra+i);

	}	

	return 0;
}
