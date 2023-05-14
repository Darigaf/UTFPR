#include <stdio.h>
int pegaProximoPixel(int contador){
	unsigned int pixeis[] = {0x12, 0xAF, 0x78, 0xBC, 0x33, 0x51, 0x49, 0xD1, 0xFFFFFFFF};
	return pixeis[contador];
}
void codificaStreamImagem (int n_bits){
        //Declaração das variáveis usadas
	int contador = 0;
	int quantidade_iteracoes;
        unsigned int pixel = 0xFF;
        unsigned char comparison_mask;
        unsigned int compressed_byte = 0x00;
        unsigned int bits_significativos = 0x00;
        // Encerra o Loop somente ao receber o byte de encerramento
        while(pixel != 0xFFFFFFFF){
                //Decisão da máscara usada(para a comparação bit a bit) de acordo com a taxa de redução dada
                if(n_bits == 1){
			quantidade_iteracoes = 8;
                        //1000 0000
                        comparison_mask = 0x80;
                }
                else if(n_bits == 2){
			quantidade_iteracoes = 4;
                        //1100 0000
                        comparison_mask = 0xC0;
                }
                else{
			quantidade_iteracoes = 2;
                        //1111 0000
                        comparison_mask = 0xF0;
                }

		pixel = pegaProximoPixel(contador);
		contador ++;
		//printf("%X\n", pixel);
		//quantidade_iteracoes é a quantidade de vezes que o loop precisa ser executado para se obter um byte completo
		for(int i = 0; i<quantidade_iteracoes; i++){
			// Compara o byte com a mascara e retorna o valor dos bits mais significativos
			bits_significativos = pixel & comparison_mask;
			printf("%X\n", bits_significativos);
			// Adiciona os bits na variavel
			compressed_byte = compressed_byte | bits_significativos;
                printf("%X\n", compressed_byte);
			// Move os bits para a esquerda para que seja possível fazer a próxima comparação
			compressed_byte = compressed_byte << n_bits;
                printf("%X\n", compressed_byte);
		}

                // Move os bits para a direita, para que fiquem na posição devida.
                compressed_byte = compressed_byte >> (n_bits*4);
                printf("%X\n", compressed_byte);
        	compressed_byte = 0x00;
                //enviaByteRBD(compressed_byte);
        }


}

int main(){
	codificaStreamImagem(4);
	return 0;
}
