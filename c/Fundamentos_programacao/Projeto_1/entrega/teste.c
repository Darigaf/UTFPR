#include <stdio.h>
int pegaProximoPixel(int contador){
	long int pixeis[] = {0x12, 0xAF, 0x78, 0xBC, 0x33, 0x51, 0x49, 0xD1, 0xFFFFFFFF};
	return pixeis[contador];
}
void codificaStreamImagem (int n_bits){
        //Declaração das variáveis usadas
	int contador = 0;
	int quantidade_iteracoes;
        unsigned int pixel = 0xFF;
        unsigned long int comparison_mask;
        unsigned long int compressed_byte = 0x00;
        unsigned long int bits_significativos = 0x00;
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
        // Encerra o Loop somente ao receber o byte de encerramento
        while(pixel != 0xFFFFFFFF){

		//quantidade_iteracoes é a quantidade de vezes que o loop precisa ser executado para se obter um byte completo
		for(int i = 0; i < quantidade_iteracoes; i++){
			// Compara o byte com a mascara e retorna o valor dos bits mais significativos
			bits_significativos = pixel & comparison_mask;
			// Adiciona os bits na variavel
			compressed_byte = compressed_byte | bits_significativos;
			// Move os bits para a esquerda para que seja possível fazer a próxima comparação
			compressed_byte = compressed_byte << n_bits;
			//printf("%X \n", bits_significativos);
			pixel = pegaProximoPixel(contador);
			contador ++;
		}	

                // Move os bits para a direita, para que fiquem na posição devida.
                compressed_byte = compressed_byte >> (n_bits*quantidade_iteracoes);
                //printf("%X \n", compressed_byte);
                //enviaByteRBD(compressed_byte);
        	compressed_byte = 0x00;
        }


}

int pegaProximoByteRBD(int contador){
	//long int pixeis[] = {0x1A, 0x7B, 0x35, 0x4D, 0xFFFFFFFF};
	long int pixeis[] = {0x26, 0x17, 0xFFFFFFFF};
	//long int pixeis[] = {0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0xFFFFFFFF};
	return pixeis[contador];
}
void decodificaStreamRBD (int n_bits, int preenche){
	int contador = 0;
	int quantidade_iteracoes;
	int i;
	unsigned long int uncompressed_byte = 0x00;
        int comparison_mask;
	int shifted_comparison_mask;
        unsigned long int bits_significativos = 0x00;
	unsigned int compressed_byte = pegaProximoByteRBD(contador);
	contador++;
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
	
	while(compressed_byte != 0xFFFFFFFF){
		shifted_comparison_mask = comparison_mask;
		for(i = 0; i < (quantidade_iteracoes); i++){
			// Compara o byte com a mascara e retorna o valor dos bits mais significativos
			bits_significativos = compressed_byte & shifted_comparison_mask;
			bits_significativos = bits_significativos << (i*n_bits);
			// Adiciona os bits na variavel
			uncompressed_byte = uncompressed_byte | bits_significativos;
			//uncompressed_byte = uncompressed_byte << 8;
			// Move os bits para a esquerda para que seja possível fazer a próxima comparação
			printf("Compressed: %X \n", compressed_byte);
			printf("Comparison: %X \n", shifted_comparison_mask);
			printf("Significativos :%X \n", bits_significativos);
			printf("Uncompressed: %X \n", uncompressed_byte);
			shifted_comparison_mask = shifted_comparison_mask >> n_bits;
                	//uncompressed_byte = uncompressed_byte >> (i+2);
			printf("%X \n", uncompressed_byte);
			uncompressed_byte = 0x00;
		//enviaPixel(uncompressed_byte);
		}	
		compressed_byte = pegaProximoByteRBD(contador);
		contador ++;
			
	}
}
 

int main(){
	int n_bits = 4;
	codificaStreamImagem(n_bits);
	decodificaStreamRBD(n_bits, 0);
	n_bits = 2;
	decodificaStreamRBD(n_bits, 0);
	return 0;
}
