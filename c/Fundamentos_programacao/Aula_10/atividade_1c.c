#include <stdio.h>

int main(){
	
	for(int i = 1; i < 4; i++){

		for(int j = i; j < 4; j++){
			for(int k = j; k < 4; k++){
				printf("%d %d %d, ", k, j,i);
			}
		}
	}

	return 0;
}
