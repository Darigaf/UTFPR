// Trabalho feito pelos alunos Mateus Bernardo - A2556618 & Vitor Ribeiro Gomes - A2556693

#include "trabalho2.h"

//05
void mudaGanho (double* dados, int n_amostras, double ganho){
	for(int i = 0; i < n_amostras; i++){
		dados[i] *=ganho;
	}
}

//05
void misturaDados (double* dados1, double* dados2, double* saida,
int n_amostras){
	for(int i = 0; i < n_amostras; i++){
		saida[i] = (dados1[i]+dados2[i]);
	}
}

//15
void inverteSinal (double* dados, int n_amostras){



}

//35
void atrasaSinal (double* dados, int n_amostras, int atraso){
	for(int i = n_amostras; i > 0; i--){
		dados[i] = dados[i-atraso];
	}

}

//35
void filtroDaMedia (double* dados, int n_amostras, int largura){


}

//EXTRA 05 Pontos
void ecos (double* dados, int n_amostras, int n_repeticoes, int atraso,
int abafamento, double decaimento){


}
