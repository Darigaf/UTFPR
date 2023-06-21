/*============================================================================*/
/* IF61C - TRABALHO 3                                                         */
/*----------------------------------------------------------------------------*/
/* Autor:Alfons Andrade, Guilherme Koller e André Melani
          RA:1839675        RA:2192950       RA:2190338
/*============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "trabalho3.h"

#define MASK 3                                                                  /*Esta constante define o tamanho da máscara em que será aplicado o filtro da mediana no caso uma máscara de ordem 3x3*/
#define LIMITE 2                                                                /*Define o tamanho da máscara aplicada na função de buscar a coordenada do ponto de cada imagem afetando diretamente a precisão do programa*/
#define VIZINHOS 3

//Função principal

double calculaDistancia (Imagem* bg, Imagem* img1, Imagem* img2){               /*Função principal do programa que efetua o cálculo da distância a partir da soma, do módulo da variação de X e do módulo da variação do ponto Y, efetuando a raiz.*/
    Coordenada ponto1,
               ponto2;
    int x,                                                                      /*Variáveis X e Y que guardam o quadrado do módulo, das variações das coordenadas x e y no ponto 1 e 2.*/
        y,
        n;

    double dist;

    tratamento_imagem(bg,img1,img2);

    ponto1 = procura_coordenada(img1);
    ponto2 = procura_coordenada(img2);

    x=abs(ponto2.x-ponto1.x)*abs(ponto2.x-ponto1.x);

    y=abs(ponto2.y-ponto1.y)*abs(ponto2.y-ponto1.y);

    n=x+y;                                                                      /*Armazena a soma dos módulos para efetuar a raiz apenas de um inteiro.*/

    dist=sqrt(n);

    return dist;
}

//Subfunções

void tratamento_imagem(Imagem* bg, Imagem* img1, Imagem* img2){                 /*Função que reúne todas as funções necessárias para o tratamento das imagens a serem utilizadas verificação.*/
    int i;

    comparaBg(bg,img1);
    comparaBg(bg,img2);

    for(i=0;i<3;i++){
        filtro_mediana(img1);
        filtro_mediana(img2);
    }

    filtro_vizinhos(img1);
    filtro_vizinhos(img2);
}

Coordenada procura_coordenada(Imagem*img){                                      /*Função que percorre os pontos da imagem a procura da primeira matriz de tamanho LIMITExLIMITE com todos os pontos brancos ,ao achar, envia a coordenada para ser utilizada como base para calcular a distância.*/
    int i,
        j,
        verifica_vizinho=0;

    Coordenada ponto;

    for (i = LIMITE  ; i <= img->altura - LIMITE ; i++)
        for (j = LIMITE  ; j <= img->largura - LIMITE ; j++){
            verifica_vizinho=pontos_ao_redor(i,j,LIMITE,img);
            if(verifica_vizinho==1){
                ponto.x=i;
                ponto.y=j;
            }
        }
        return ponto;
}

//Ferramentas de filtro

void comparaBg(Imagem* bg, Imagem* img){                                        /*Função que efetua a subtração da Imagem do caso de teste com o seu respectivo background com uma margem de erro de 41 (pontos para eliminar alguns ruídos) no canal do ponto, caso a diferença seja menor pinta de preto.*/
    int i,
        j,
        k;

    for (i = 0; i < img->altura; i++)
        for (j = 0; j < img->largura; j++){
            if((abs(img->dados[0][i][j] - bg->dados[0][i][j])) < 40)
                for(k = 0 ; k < img->n_canais ; k++)
                    img->dados[k][i][j]=0;

            else{
                for(k = 0 ; k < img->n_canais ; k++)
                    img->dados[k][i][j]=255;
            }
        }
}

void filtro_mediana(Imagem*img){                                                /*Função de filtro aplicada para polir a imagem feita a partir da subtração e calibrar os dados para aumento da precisão*/
    int i,
        j,
        k;

    unsigned char ponto_mediana=0;
    Imagem* img_copia = NULL;
    img_copia = criaImagem (img->largura, img->altura, 3);                      /*Copia a imagem para fazer as verificações de posição e aplica-lás na imagem original*/

    for (i = 0; i < img->altura; i++)
        for (j = 0; j < img->largura; j++)
            for( k = 0 ; k < img->n_canais ; k++)
                img_copia->dados [k][i][j] = img->dados [k][i][j];

    for (i = MASK  ; i <= img->altura - MASK ; i++)                             /*Faz a verificação a partir do tamanho da Máscara, constante que define os pontos a serem avaliados de uma matriz M de tamanho MASKxMASK*/
        for (j = MASK  ; j <= img->largura - MASK ; j++)
        {
           ponto_mediana=ordena_vetor(i,j,img_copia);
           for(k = 0 ; k < img->n_canais ; k++)
                img->dados[k][i][j]=ponto_mediana;
        }

    destroiImagem(img_copia);
}

void filtro_vizinhos(Imagem*img){
  int i,
      j,
      k,
      l,
      m;

  Imagem* img_copia = NULL;
  img_copia = criaImagem (img->largura, img->altura, 3);                        /*Copia a imagem para fazer as verificações de posição e aplica-lás na imagem original*/

  for (i = 0; i < img->altura; i++)
      for (j = 0; j < img->largura; j++)
          for( k = 0 ; k < img->n_canais ; k++)
              img_copia->dados [k][i][j] = img->dados [k][i][j];

  for (i = VIZINHOS; i <= img->altura-VIZINHOS; i++)
      for (j = VIZINHOS; j <= img->largura-VIZINHOS; j++){
          if(pontos_ao_redor(i,j,VIZINHOS,img_copia)==1){
              for(l = i - (VIZINHOS/2);l <= i + (VIZINHOS/2); l++)
                  for(m = j - (VIZINHOS/2); m <=  j + (VIZINHOS/2); m++)
                      for(k=0;k<img->n_canais;k++)
                          img->dados[k][l][m]=255;
          }
          else{
              for(l = i - (VIZINHOS/2) ;l <= i + (VIZINHOS/2); l++)
                  for(m = j - (VIZINHOS/2); m <=  j + (VIZINHOS/2); m++)
                      for(k=0;k<img->n_canais;k++)
                          img->dados[k][l][m]=0;
          }
      }

  destroiImagem(img_copia);
}

void binariza( Imagem* img ){
    int i,
        j,
        k,
        l;

    for (i = 0; i < img->altura; i++)
        for (j = 0; j < img->largura; j++){
            for(k = 0 ; k < img->n_canais ; k++){
                if(img->dados[k][i][j] != 255)
                    for(l = 0 ; l < img->n_canais ; l++)
                       img->dados[l][i][j] = 0;

                else
                    for(l = 0 ; l < img->n_canais ; l++)
                        img->dados[l][i][j]=255;
            }
        }
}

//Cálculos

unsigned char ordena_vetor(int altura,int largura,Imagem* img){                 /*Função que auxilia no filtro aplicado na imagem armazenando os valores em um vetor ordenando-os e retornando a posição do meio.*/
     int i,
         j,
         pos=0;

     unsigned char v[MASK*MASK],
                   aux=0;

     for(i = altura - (MASK/2) ;i <= altura+(MASK/2); i++)
         for(j = largura - (MASK/2); j <=  largura + (MASK/2); j++)
              v[pos++]=img->dados[0][i][j];

     for(i = 0 ;i < pos; i++)
        for(j = 0 ;j < pos; j++)
            if(v[i]>v[j]){
               aux=v[i];
               v[i]=v[j];
               v[j]=aux;
            }

     return v[MASK/2];
}

int pontos_ao_redor(int altura,int largura,int lim,Imagem* img){                        /*Função que determina se o ponto verificado deve ou não ser utilizado como referência para calcular a Distância*/
    int i,
        j;

    for(i = altura - (lim/2) ;i <= altura+(lim/2); i++)
        for(j = largura - (lim/2); j <=  largura + (lim/2); j++)
            if(img->dados[0][i][j]==0)
                return 0;

    return 1;
}
