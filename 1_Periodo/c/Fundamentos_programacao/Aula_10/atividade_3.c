#include <stdio.h>

int main(){
	int num, dividendo, is_divided;

	scanf("%d", &num);

	dividendo = 1;
	num++;
	while(1){
		is_divided = 1;	
		for(int i = 1; i < num; i++){
			if(dividendo%i)
				is_divided = 0;			
		}
		if(is_divided){	
			break;
		}
		dividendo++;
	}
	printf("MMC = %d", dividendo);

	return 0;
}
