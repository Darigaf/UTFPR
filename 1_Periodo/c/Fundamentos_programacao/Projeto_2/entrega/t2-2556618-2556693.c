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
	//Itera pelos 2 vetores de entrada e soma seus valores, a partir deles � gerado um novo vetor com a sa�da
	for(int i = 0; i < n_amostras; i++){
		saida[i] = (dados1[i]+dados2[i]);
	}
}

//15
//quest�o 3
void inverteSinal (double* dados, int n_amostras){
    int i, tamanho_vetor=n_amostras-1;
    //inver � a variavel que ir� auxiliar na inver��o
    double inver;

    //o for vai at� metade de n_amostras pois n�o � necessario mais que isso para a inver��o, pois como o valor de i � mandado para o valor de tamanho_vetor-i e o inverso tamb�m acontece ao chegar no meio do vetor todos os valores ja foram invertidos
    for(i=0; i<n_amostras/2; i++){
        //A vari�vel inver recebe o valor do vetor dados na posi��o tamanho_vetor-i
        inver=dados[tamanho_vetor-i];

        dados[tamanho_vetor-i]=dados[i];

        //A vari�vel dados na posi��o i recebe o valor de dados na posi��o tamanho_vetor-i
        dados[i]=inver;
    }
}


//35
void atrasaSinal (double* dados, int n_amostras, int atraso){
	int i;
	//Para valores de atraso maiores que 0, a itera��o do vetor � feita de tr�s para frente, pois os valores do vetor sofrer�o um "shift" para a direita
	if(atraso > 0){
		for(i = n_amostras; i > atraso; i--){	
			dados[i] = dados[i-atraso];
		}
		//Ap�s o for iterar pelas posi��es e chegar no ultimo valor dos dados de entrada, o restante do vetor � preenchido com 0
		for(i = atraso; i > 0; i--){
			dados[i] = 0;
		}
	}
	//Para valores de atraso menores que 0, que caracterizam um adiantamento, a itera��o do vetor � feita em ordem crescente
	if(atraso < 0){
		//Ocorre o mesmo processo do primeiro if, por�m agora invertido para que o processo ocorra corretamente 
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

    //o for come�a e termina nessas condi��es para n�o passar o limite do vetor quando forem calculadas as medias
    for(i=(largura-1)/2; i<n_amostras-(largura-1)/2; i++){
        media=0;
        med=0;

        //� feita a somatoria dos valores de i-(largura-1)/2 at� i+(largura-1)/2
        for(j=i-(largura-1)/2; j<=i+(largura-1)/2; j++){
            media+=dados[j];
            med++;
        }
        //� calculada a m�dia
        media=media/med;
        dados[i]=media;
    }
}

//EXTRA 05 Pontos
void ecos (double* dados, int n_amostras, int n_repeticoes, int atraso,
int abafamento, double decaimento){


}
