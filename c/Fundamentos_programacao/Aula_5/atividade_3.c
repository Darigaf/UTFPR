#include <stdio.h>

int main(){
	int multiplicador, i;
	i = 0;	

	scanf("%d", &multiplicador);

	while(i < 10){
		printf("%d\n", (i*multiplicador));
		i++;
	}
	for(i = 1; i < 10; i++){
		printf("%d\n", (i*multiplicador));
	}

	return 0;
}

