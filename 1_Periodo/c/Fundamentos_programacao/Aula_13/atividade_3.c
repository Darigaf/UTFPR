#include <stdio.h>
#define N 3
		
int main(){
	int valores[N], i;
	for(i = 0; i < N; i++){
		scanf("%d", &valores[i]);
	}
	for(i = N-1; i >= 0; i--){
		printf("%d\n", valores[i]);
	}

	return 0;
}
	
	
