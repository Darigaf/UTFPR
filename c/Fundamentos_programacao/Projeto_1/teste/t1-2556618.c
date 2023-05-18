// Código criado pelo aluno Mateus Bernardo      RA: 2556618
#include "trabalho1.h"
void codificaStreamImagem (int n_bits){
        //Declaração das variáveis usadas
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
	//inicializa a variavel com o primeiro pixel
	pixel = pegaProximoPixel();

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
			pixel = pegaProximoPixel();
			}	

                // Move os bits para a direita, para que fiquem na posição devida.
		// Sendo que a quantidade de casas a ser movida depende de n_bits
                compressed_byte = compressed_byte >> (n_bits*quantidade_iteracoes);
                enviaByteRBD(compressed_byte);
		printf("%X\n", compressed_byte);

		// Zera a variavel compressed_byte para possibilitar o uso no próximo loop
        	compressed_byte = 0x00;
        }


}
void decodificaStreamRBD (int n_bits, int preenche){
	// Inicializa as variaveis que serão usadas
	int quantidade_iteracoes;
	int i;
        int comparison_mask;
	int shifted_comparison_mask;
	unsigned long int uncompressed_byte = 0x00;
        unsigned long int bits_significativos = 0x00;
	unsigned int compressed_byte = pegaProximoByteRBD();
	//Seleciona a máscara de acordo com o valor de n_bits
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
	// Finaliza o loop ao receber o byte de encerramento
	while(compressed_byte != 0xFFFFFFFF){
		// Reinicializa a variavel para que ela possa ser usada no próximo loop de forma correta
		shifted_comparison_mask = comparison_mask;
		for(i = 0; i < (quantidade_iteracoes); i++){
			// Compara o byte com a mascara e retorna o valor dos bits mais significativos
			bits_significativos = compressed_byte & shifted_comparison_mask;
			// Move os bits para a esquerda de para formarem um byte completo
			bits_significativos = bits_significativos << (i*n_bits);
			// Adiciona os bits na variavel
			uncompressed_byte = uncompressed_byte | bits_significativos;
			// Move os bits da máscara para a direita para que seja possível fazer a próxima comparação
			shifted_comparison_mask = shifted_comparison_mask >> n_bits;
			// Zera a variavel para que possa ser usada no próximo loop

			enviaPixel(uncompressed_byte);
			uncompressed_byte = 0x00;
		}	
		compressed_byte = pegaProximoByteRBD();
			
	}
}
