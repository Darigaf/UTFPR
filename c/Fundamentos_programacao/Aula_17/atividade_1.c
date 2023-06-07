#include <stdio.h>
#define N_LINHAS 3
#define N_COLUNAS 4
int conta_minhocas(int campo[N_LINHAS][N_COLUNAS]){
	int max_minhocas, qnt_minhocas, i, j;
	qnt_minhocas = 0;
	max_minhocas = 0;
	for(i = 0; i < N_LINHAS; i++){
		for(j = 0; j < N_COLUNAS; j++){
			qnt_minhocas += campo[i][j];
		}
			if(qnt_minhocas > max_minhocas)
				max_minhocas = qnt_minhocas;
			qnt_minhocas = 0;
	}
	for(i = 0; i < N_COLUNAS; i++){
		for(j = 0; j < N_LINHAS; j++){
			qnt_minhocas += campo[j][i];
		}
			if(qnt_minhocas > max_minhocas)
				max_minhocas = qnt_minhocas;
			qnt_minhocas = 0;
	}
	printf("%d", max_minhocas);
	return max_minhocas;
}
		
int main(){
	int campo [N_LINHAS][N_COLUNAS] = {{81, 28, 240, 10},
					{40, 10, 100, 240},
					{20, 180, 110, 35}};
	printf("%d", conta_minhocas(campo));



	return 0;
}
	
	
