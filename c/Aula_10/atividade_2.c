#include <stdio.h>
#define N 5

int main(){
	int is_primo, primos, num;	
	num = 2;
	while(primos < N){
		is_primo = 1;
		for(int i = 2; i < num; i++){
			if(num%i == 0){
				is_primo = 0;
				break;
			}
		}
		if(is_primo){
			primos++;
			printf("%d\n", num);
		}
		num++;


	}


	return 0;
}
