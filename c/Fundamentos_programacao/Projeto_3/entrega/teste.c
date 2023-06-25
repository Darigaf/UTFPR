#include <stdio.h>
#define INTERVALO_CONTINUIDADE 4
#define LARGURA_BORDA 4
int main(){
	int vetor_teste[30] = {0, 0, 0, 0, 0, 0, 255, 0, 255, 255, 0, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};	
	int pixeis_continuos = 0;
	int espaco_vazio = 0;
	int borda_esquerda;
	for(int largura=0; largura < 30; largura++){
		if(vetor_teste[largura] == 255){
			pixeis_continuos++;
			espaco_vazio = 0;
		}
		else{
			espaco_vazio++;
		}
		if(espaco_vazio > INTERVALO_CONTINUIDADE){
			espaco_vazio = 0;
			pixeis_continuos = 0;
		}
		if(pixeis_continuos >= LARGURA_BORDA){
			borda_esquerda = largura;
			printf("%d", borda_esquerda);
			break;
		}

	}
}
