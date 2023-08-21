#include "imagem.h"
#include "trabalho3.h"
#include "gerador_de_testes.h"
#include <stdlib.h>

#define FILTRO 35
#define MEDIA 127
#define REPETICOES 60
#define BRANCO 255
#define PRETO 0
#define MIN_MOTO 1000
#define MAX_MOTO 1500
#define MAX_MEDIO 9000
#define MAX_LONGO 22000
#define MAX_MUITO_LONGO 29000

Imagem1C* subtraiImagem(Imagem3C* img, Imagem3C* bg);
void retiraRuido(Imagem1C* red);
int tiraMedia(Imagem1C* red, int altura, int largura);
int acharVeiculo(int altura, int largura, Imagem1C* img, int num_veiculo);

int contaVeiculos(Imagem3C* img, Imagem3C* bg, int contagem[N_TIPOS_DE_VEICULOS]){
	int cont_veiculos=1, area_veiculo, total=0;
	Imagem1C* imagem_tratada;
	imagem_tratada=subtraiImagem(img, bg);
	retiraRuido(imagem_tratada);
	//Os 2 comentarios a seguir salvam a imagem pós processamento, para análise do resultado caso necessário
	//char* caminho_imagem="imagem_sem_ruido.bmp";
	//salvaImagem1C (imagem_tratada, caminho_imagem);
	for(int i=0; i<4; i++){
    		contagem[i]=0;
	}
	for(int i=1; i<(imagem_tratada->altura)-1; i++){
    		for(int j=1; j<(imagem_tratada->largura)-1; j++){
        		//detecta se há algun veiculo
        		if(imagem_tratada->dados[i][j]==BRANCO){
            			//pega a area do veiculo atraves da função acharVeiculo
            			area_veiculo=acharVeiculo(i, j, imagem_tratada, cont_veiculos);
            			//adciona +1 na posição referente a categoria(area) do veiculo
            			if(area_veiculo<=MAX_MOTO&&area_veiculo>=MIN_MOTO){
                			contagem[0]++;
                			total++;
            			}else if(area_veiculo<MAX_MEDIO&&area_veiculo>MAX_MOTO){
                			total++;
                			contagem[1]++;
            			}else if(area_veiculo<=MAX_LONGO&&area_veiculo>MAX_MEDIO){
                			total++;
                			contagem[2]++;
            			}else if (area_veiculo>MAX_LONGO&&area_veiculo<MAX_MUITO_LONGO){
                			total++;
                			contagem[3]++;
            			}
            			cont_veiculos++;
        		}
    		}
	}
	return total;
}

//função que calcula a diferença entre img por bg
Imagem1C* subtraiImagem(Imagem3C* img, Imagem3C* bg){
	int diferenca, e_diferente;
	Imagem1C* imagem_diferenca;
	
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
            			imagem_diferenca->dados[altura][largura]=BRANCO;
        		}else{
            			imagem_diferenca->dados[altura][largura]=PRETO;
        		}
    		}
	}

	//Os 2 comentarios a seguir salvam a imagem pós processamento, para análise do resultado caso necessário
	//char* caminho_imagem="imagem_de_teste.bmp";
	//salvaImagem1C (imagem_diferenca, caminho_imagem);
	return imagem_diferenca;
}

//função responsavel por tirar o ruido da imagem
void retiraRuido(Imagem1C* img){
	int media, altura_img, largura_img;
	altura_img=(img->altura)-1;
	largura_img=(img->largura)-1;
	
	//o tamanho de REPETICOES vai definir a qualidade da imagem no final da função
	for(int rep=0; rep<REPETICOES; rep++){
    		for(int altura=1; altura<altura_img; altura++){
        		for(int largura=1; largura<largura_img; largura++){
            			//chamar a função que calcula a media
            			media=tiraMedia(img, altura, largura);
			
            			if(media>=MEDIA){
                			img->dados[altura][largura]=BRANCO;
            			}else{
                			img->dados[altura][largura]=PRETO;
            			}
        		}
    		}
	}
}

int tiraMedia(Imagem1C* red, int altura, int largura){
	int media=0, altura_img, largura_img;
	altura_img=altura+1;
	largura_img=largura+1;
	
	//tira a media do pixels ao redor da posição atual
	for(int i=altura-1; i<=altura_img; i++){
    		for(int j=largura-1; j<=largura_img; j++){
        		if(j!=largura||i!=altura){
            			media+=red->dados[i][j];
        		}
    		}
	}
	media=media/8;
	
	return media;
}

//função que dá o valor de num_veiculos para toda a area do veiculo detectado e retorna a area do mesmo
int acharVeiculo(int altura, int largura, Imagem1C* img, int num_veiculo){
	int tem_veiculo=1, num_pixel=1, altura_imagem, largura_imagem;
	//coloca o valor de num_veiculo na primeira posição em que o veiculo foi detectado
	img->dados[altura][largura]=num_veiculo;
	
	altura_imagem=(img->altura)-1;
	largura_imagem=(img->largura)-1;
	while(tem_veiculo){
    		tem_veiculo=0;
    		for(int i=1; i<altura_imagem; i++){
        		for(int j=1; j<largura_imagem; j++){
            			//algumas dessa condições devem ser cumpridas para que a posição seja reconhecida como parte do veiculo
            			if(img->dados[i][j]==BRANCO&&img->dados[i-1][j]==num_veiculo){
                			img->dados[i][j]=num_veiculo;
                			tem_veiculo=1;
                			num_pixel++;
            			}
            			if(img->dados[i][j]==BRANCO&&img->dados[i][j+1]==num_veiculo){
                			img->dados[i][j]=num_veiculo;
                			tem_veiculo=1;
                			num_pixel++;
            			}
            			if(img->dados[i][j]==BRANCO&&img->dados[i+1][j]==num_veiculo){
                			img->dados[i][j]=num_veiculo;
                			tem_veiculo=1;
                			num_pixel++;
            			}
            			if(img->dados[i][j]==BRANCO&&img->dados[i][j-1]==num_veiculo){
                			img->dados[i][j]=num_veiculo;
                			tem_veiculo=1;
                			num_pixel++;
            			}
        		}
    		}
	}
	return num_pixel;
}

