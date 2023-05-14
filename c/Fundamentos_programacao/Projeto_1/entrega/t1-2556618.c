// Código criado pelo aluno Mateus Bernardo      RA: 2556618
#include "trabalho1.h"
void codificaStreamImagem (int n_bits){
	//Declaração das variáveis usadas
        unsigned int pixel = 0xFF;
	unsigned char comparison_mask;
	unsigned int compressed_byte = 0x00;
	unsigned int bits_significativos = 0x00;
	// Encerra o Loop somente ao receber o byte de encerramento
        while(pixel != 0xFFFFFFFF){
		//Decisão da máscara usada(para a comparação bit a bit) de acordo com a taxa de redução dada
		if(n_bits == 1){
			//1000 0000
			comparison_mask = 0x80;
		}
		else if(n_bits == 2){
			//1100 0000
			comparison_mask = 0xC0;
		}
		else{
			//1111 0000
			comparison_mask = 0xF0;
		}

		pixel = pegaProximoPixel();
		// Compara o byte com a mascara e retorna o valor dos bits mais significativos
		bits_significativos = pixel & comparison_mask;
		// Adiciona os bits na variavel
		compressed_byte = compressed_byte | bits_significativos;
		// Move os bits para a esquerda para que seja possível fazer a próxima comparação
		compressed_byte = compressed_byte << n_bits;

		// Move os bits para a direita, para que fiquem na posição devida.
		compressed_byte = compressed_byte >> (n_bits*4);
		//printf("%X\n", compressed_byte);
		enviaByteRBD(compressed_byte);
	}


}
void decodificaStreamRBD (int n_bits, int preenche){

}


