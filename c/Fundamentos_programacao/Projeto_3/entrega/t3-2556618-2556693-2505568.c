// Trabalho feito pelos alunos Mateus Bernardo - A2556618 | Vitor Ribeiro Gomes - A2556693 | Ana Júlia Letchacovski - A2505568

#include "imagem.h"

#include "trabalho3.h"
#include <stdlib.h>

#include "gerador_de_testes.h"

#define FILTRO 35
#define INTERVALO_CONTINUIDADE 4
int contaVeiculos(Imagem3C* img, Imagem3C* bg, int contagem[N_TIPOS_DE_VEICULOS]){
	for(int i = 0; i < 4;i++){
		contagem[i] = 0;
	}
	Imagem3C* sub;
	sub=(Imagem3C*)malloc(sizeof(Imagem3C));
	Imagem1C* imagem_diferenca;
	for(int altura=0; altura<bg->altura; altura++){
		for(int largura=0; largura<bg->largura; largura++){
			if(imagem_diferenca->dados[altura][largura] == 255){

			}
			else()

		}
	}
	return contagem;
}

void subtraiImagem(Imagem3C* img, Imagem3C* bg, Imagem1C* imagem_diferenca){
	char* caminho_imagem="imagem_de_teste.bmp";
	int diferenca, e_diferente;
	//Imagem1C* imagem_diferenca;
	imagem_diferenca=(Imagem1C*)malloc(sizeof(Imagem1C));
	
	imagem_diferenca=criaImagem1C(img->largura, img->altura);
	
	
	
	for(int altura=0; altura<bg->altura; altura++){
	
		for(int largura=0; largura<bg->largura; largura++){
	
        	e_diferente=0;
	
        	for(int canal=0; canal<3; canal++){
	
			diferenca=img->dados[canal][altura][largura]-bg->dados[canal][altura][largura];
		
			if(diferenca<0){
				diferenca*=-1;
			}
		
			if(diferenca>FILTRO){
				e_diferente=1;
			}
		}
	
        	if(e_diferente){
			imagem_diferenca->dados[altura][largura]=255;
        	}else{
			imagem_diferenca->dados[altura][largura]=0;
        	}
	
		}
	
	}
	
	salvaImagem1C (imagem_diferenca, caminho_imagem);
	
}


