#include <stdio.h>
int eh_letra(char caracter){
	if(caracter >= 'a' && caracter <= 'z')
		return 1;
	if(caracter >= 'A' && caracter <= 'Z')
		return 1;

	return 0;
}
		
int main(){
	char texto[1000] = "isso d umackck,,,,, sd frase";	
	int palavras = 0;
	for(int i = 0; i < 1000; i++){
		if(eh_letra(texto[i-1]) && !(eh_letra(texto[i]))){
			palavras++;
		}
	}
	printf("%d", palavras);
	

	return 0;
}
	
	
