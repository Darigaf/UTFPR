#include <stdio.h>
#include <stdlib.h>
#define N 2
#define M 3
		
int main(){
	int matriz_a[N][M]={{1,2},{1,2,3}}, matriz_b[M][N]={{1,2,3},{1,2}}, matriz_c[N][N], i, j, k;
	//matriz_a={{1,2,3},{1,2,3}};
	//matriz_b={{1,2,3},{1,2,3}};
	//srand(time(NULL));
	//for(i = 0; i < N; i++){
		//for(j = 0; j < M; i++){
			//matriz_a[i][j] = rand();
		//}
	//}
	//for(i = 0; i < M; i++){
		//for(j = 0; j < N; i++){
			//matriz_b[i][j] = rand();
		//}
	//}

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			matriz_c[i][j] = 0;
			for(k = 0; k < N; k++){
					matriz_c[i][j] += (matriz_a[i][k] + matriz_b[k][j]);
			}
		}
	}
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%d", matriz_c[i][j]);
		}
		printf("\n");
	}

	return 0;
}
	
	
