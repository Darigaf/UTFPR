#include <stdio.h>
void zera_array(int array[], int tamanho){
	for(int i = 0; i < tamanho; i++){
		array[i] = 0;
	}
}
		
int main(){
	int qnt_pedras, qnt_sapos, posicao_sapo, pulos_sapo, j, i;
	scanf("%d", &qnt_pedras);
	scanf("%d", &qnt_sapos);
	int pedras[qnt_pedras];
	zera_array(pedras, qnt_pedras);

	for(i = 0; i < qnt_sapos; i++){
		scanf("%d", &posicao_sapo);
		scanf("%d", &pulos_sapo);
		for(j=posicao_sapo; j < qnt_pedras; j += pulos_sapo){
			pedras[j] = 1;
		}
		for(j=posicao_sapo; j > 0 ; j -= pulos_sapo){
			pedras[j] = 1;
		}
	}	
	for(i = 0; i < qnt_pedras; i++){
		printf("%d", pedras[i]);
	}
	

	return 0;
}
	
	
