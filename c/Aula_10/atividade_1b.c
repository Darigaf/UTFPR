#include <stdio.h>

int main(){
	
	for(int i = 1; i < 7; i++){

		for(int j = 1; j < 7; j++){
			for(int k = 1; k < 7; k++){
				printf("%d %d %d, ", k, j,i);
			}
		}
	}

	return 0;
}
