#include <stdio.h>
#include <stdlib.h>
#define N 5
#define STRING_SIZE 128
		
int main(){
	char texto[N][STRING_SIZE];
	int i;
	for(i = 0; i < N; i++){
		scanf("%s", texto[i]);
	}

	for(i = N; i >= 0; i--){
		printf("%s\n", texto[i]);
	}


	return 0;
}
	
	
