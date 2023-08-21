// Trabalho feito pelos alunos Mateus Bernardo - A2556618 & Vitor Ribeiro Gomes - A2556693

#include "trabalho2.h"

//05
void mudaGanho (double* dados, int n_amostras, double ganho){
	//Itera por cada valor dentro do vetor e multiplica pelo ganho, aumentando ou diminuindo o volume
	for(int i = 0; i < n_amostras; i++){
		dados[i] *= ganho;
	}
}

//05
void misturaDados (double* dados1, double* dados2, double* saida,
int n_amostras){
	//Itera pelos 2 vetores de entrada e soma seus valores, a partir deles é gerado um novo vetor com a saída
	for(int i = 0; i < n_amostras; i++){
		saida[i] = (dados1[i]+dados2[i]);
	}
}

//15
//questão 3
void inverteSinal (double* dados, int n_amostras){
    int i, tamanho_vetor=n_amostras-1;
    //inver é a variavel que irá auxiliar na inverção
    double inver;

    //o for vai até metade de n_amostras pois não é necessario mais que isso para a inverção, pois como o valor de i é mandado para o valor de tamanho_vetor-i e o inverso também acontece ao chegar no meio do vetor todos os valores ja foram invertidos
    for(i=0; i<n_amostras/2; i++){
        //A variável inver recebe o valor do vetor dados na posição tamanho_vetor-i
        inver=dados[tamanho_vetor-i];

        dados[tamanho_vetor-i]=dados[i];

        //A variável dados na posição i recebe o valor de dados na posição tamanho_vetor-i
        dados[i]=inver;
    }
}


//35
void atrasaSinal (double* dados, int n_amostras, int atraso){
	int i;
	//Para valores de atraso maiores que 0, a iteração do vetor é feita de trás para frente, pois os valores do vetor sofrerão um "shift" para a direita
	if(atraso > 0){
		for(i = n_amostras; i > atraso; i--){	
			dados[i] = dados[i-atraso];
		}
		//Após o for iterar pelas posições e chegar no ultimo valor dos dados de entrada, o restante do vetor é preenchido com 0
		for(i = atraso; i > 0; i--){
			dados[i] = 0;
		}
	}
	//Para valores de atraso menores que 0, que caracterizam um adiantamento, a iteração do vetor é feita em ordem crescente
	if(atraso < 0){
		//Ocorre o mesmo processo do primeiro if, porém agora invertido para que o processo ocorra corretamente 
		for(i = 0; i < n_amostras; i++){
			dados[i] = dados[i+atraso];
		}
		for(i = n_amostras; i > n_amostras+atraso; i--){
			dados[i] = 0;
		}

	}

}

//35
void filtroDaMedia (double* dados, int n_amostras, int largura){
    int i, j, med;
    double media;

    //o for começa e termina nessas condições para não passar o limite do vetor quando forem calculadas as medias
    for(i=(largura-1)/2; i<n_amostras-(largura-1)/2; i++){
        media=0;
        med=0;

        //é feita a somatoria dos valores de i-(largura-1)/2 até i+(largura-1)/2
        for(j=i-(largura-1)/2; j<=i+(largura-1)/2; j++){
            media+=dados[j];
            med++;
        }
        //é calculada a média
        media=media/med;
        dados[i]=media;
    }
}

//EXTRA 05 Pontos
void ecos (double* dados, int n_amostras, int n_repeticoes, int atraso,
int abafamento, double decaimento){


}
