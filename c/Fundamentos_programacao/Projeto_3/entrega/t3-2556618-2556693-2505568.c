// Trabalho feito pelos alunos Mateus Bernardo - A2556618 | Vitor Ribeiro Gomes - A2556693 | Ana JÃºlia Letchacovski - A2505568

#include "imagem.h"

#include "trabalho3.h"
#include <stdlib.h>
#include <stdio.h>
#include "gerador_de_testes.h"

#define FILTRO 40
#define INTERVALO_CONTINUIDADE 1
#define LARGURA_BORDA 10

#define MEDIA 127
#define REPETICOES 10
Imagem1C* subtraiImagem(Imagem3C* img, Imagem3C* bg);
void retiraRuido(Imagem1C* red);
int tiraMedia(Imagem1C* red, int altura, int largura);

int contaVeiculos(Imagem3C* img, Imagem3C* bg, int contagem[N_TIPOS_DE_VEICULOS]){
	char* caminho_imagem="imagem_sem_ruido.bmp";
	Imagem1C* imagem_tratada;
	imagem_tratada = subtraiImagem(img, bg);
	imagem_tratada = retiraRuido(imagem_tratada);
	salvaImagem1C (imagem_tratada, caminho_imagem);
	
	int pixeis_continuos = 0;
	int espaco_vazio = 0;
	int borda_esquerda[300], borda_direita, altura_veiculo[300];
	int veiculos_totais = 0;
	for(int i = 0; i < 4;i++){
		contagem[i] = 0;
	}

	for(int altura=0; altura < bg->altura; altura++){
		for(int largura=0; largura < bg->largura; largura++){
			if(imagem_tratada->dados[altura][largura] == 255){
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
			if(pixeis_continuos >= LARGURA_BORDA && veiculos_totais < 300){
				borda_esquerda[veiculos_totais] = largura;	
				altura_veiculo[veiculos_totais] = altura;
				veiculos_totais ++;
			}

		}
	}
	return contagem[N_TIPOS_DE_VEICULOS];
}

Imagem1C* subtraiImagem(Imagem3C* img, Imagem3C* bg){
	char* caminho_imagem="imagem_de_teste.bmp";
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
				imagem_diferenca->dados[altura][largura]=255;
        		}
			else{
				imagem_diferenca->dados[altura][largura]=0;
        		}
	
		}
	
	}
	
	salvaImagem1C (imagem_diferenca, caminho_imagem);
	return imagem_diferenca;
	
}



#define FILTRO 40

#define MEDIA 127

#define REPETICOES 10

Imagem1C* subtraiImagem(Imagem3C* img, Imagem3C* bg);

void retiraRuido(Imagem1C* red);

int tiraMedia(Imagem1C* red, int altura, int largura);

int contaVeiculos(Imagem3C* img, Imagem3C* bg, int contagem[N_TIPOS_DE_VEICULOS]){
    char* caminho_imagem="imagem_sem_ruido.bmp";
    Imagem1C* sub;
    sub=subtraiImagem(img, bg);
    retiraRuido(sub);
    salvaImagem1C (sub, caminho_imagem);
    return 0;
}

//função que subtrai img por bg
Imagem1C* subtraiImagem(Imagem3C* img, Imagem3C* bg){
    char* caminho_imagem="imagem_de_teste.bmp";
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
                imagem_diferenca->dados[altura][largura]=255;
            }else{
                imagem_diferenca->dados[altura][largura]=0;
            }

        }

    }

    salvaImagem1C (imagem_diferenca, caminho_imagem);
    return imagem_diferenca;
}

//função responsavel por tirar o ruido da imagem
void retiraRuido(Imagem1C* red){
    int media;
    //o tamanho de REPETICOES vai definir a qualidade da imagem no final da função
    for(int rep=0; rep<REPETICOES; rep++){
        for(int altura=1; altura<red->altura-1; altura++){
            for(int largura=1; largura<red->largura-1; largura++){
                //chamar a função que calcula a media
                media=tiraMedia(red, altura, largura);

                if(media>=MEDIA){
                    red->dados[altura][largura]=255;
                }else{
                    red->dados[altura][largura]=0;
                }
            }
        }
    }
}

int tiraMedia(Imagem1C* red, int altura, int largura){
    int media=0;
    //tira a media do pixels ao redor da posição atual
    for(int i=altura-1; i<=altura+1; i++){
        for(int j=largura-1; j<=largura+1; j++){
            if(j!=largura||i!=altura){
                media+=red->dados[i][j];
            }
        }
    }
    media=media/8;

    return media;
}


