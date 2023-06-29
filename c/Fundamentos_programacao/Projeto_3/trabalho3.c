#include "imagem.h"
#include "trabalho3.h"
#include "gerador_de_testes.h"
#include <stdio.h>
#include <stdlib.h>

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


