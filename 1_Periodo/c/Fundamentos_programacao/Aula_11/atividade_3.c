#include <stdio.h>

	int fibonacci(int n){
		int n_1, n_2, n_3;
		n_1 = 0;
		n_2 = 1;
		n_3 = 2;

		while(n > n_3){
			n_1 = n_2;
			n_2 = n_3;
			n_3 = (n_1+n_2);
		}

		return(n_3);
	}

int main(){
	int n, menor_fibo;
	scanf("%d", &n);
	menor_fibo = fibonacci(n);
	printf("%d", menor_fibo);


	
	return 0;
}
