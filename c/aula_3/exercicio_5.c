#include <stdlib.h>
#include <stdio.h>

int main(void){
	int velocidade_maxima = 0;
	int velocidade_veiculo = 0;
	int multa = 0;
	
	printf("Insira a velocidade máxima da via em km/h\n");
	scanf("%d", &velocidade_maxima);
	printf("\nInsira a velocidade que o carro estava se locomovendo\n");
	scanf("%d", &velocidade_veiculo);

	if(velocidade_veiculo <= velocidade_maxima){
		printf("\nO veículo não estava acima do limite, logo não há multa\n");
		return 0;
	}
	multa = 50*(velocidade_veiculo - velocidade_maxima);
	printf("O motorista estava %d km/h acima do limite, logo deve pagar uma multa de: %.dR$ \n", (velocidade_veiculo - velocidade_maxima), multa);


	return 0;
}
