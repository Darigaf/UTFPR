#include <stdio.h>

int main(){
	int tamanho, altura_1, altura_2, altura_3, pico_unico;

	pico_unico = 1;

	scanf("%d", &tamanho);
	scanf("%d", &altura_1);
	scanf("%d", &altura_2);
	scanf("%d", &altura_3);

	for(int i = 0; (tamanho-3) > i; i++){
		altura_1 = altura_2;
		altura_2 = altura_3;
		scanf("%d", &altura_3);

		if((altura_2 < altura_1) && (altura_2 < altura_3)){
			pico_unico = 0;
		}
	}

	if(pico_unico){
		printf("A montanha contém somente um pico");
	}
	else{
		printf("A montanha contém mais de um pico");
	}

	return 0;
}
