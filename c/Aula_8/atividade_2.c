#include <stdio.h>
#define META 100

int main(){
	int dias, i, visitantes_totais, visitantes, atingiu;

	scanf("%d", &dias);
	i = 0;
	atingiu = 0;
	visitantes_totais = 0;
	while(dias>i){
		scanf("%d", &visitantes);
		visitantes_totais += visitantes;
		i++;
		if(visitantes_totais >= META && atingiu == 0)
			atingiu = i;
	}
	if(atingiu){
		printf("%d", atingiu);
	}
	else{
		printf("-1");
	}

	return 0;
}
