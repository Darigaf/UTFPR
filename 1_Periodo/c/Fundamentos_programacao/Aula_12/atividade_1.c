#include <stdio.h>
void segundosParaHMS (int total_segundos, int *h, int *m, int *s){
	*h = (total_segundos / 3600);
	*m = ((total_segundos % 3600) / 60);
	total_segundos -= ((*h*3600) + (*m*60));
	*s = total_segundos;
}
		
int main(){
	int hora, minuto, segundo, total_segundos;	
	total_segundos = 10000;
	segundosParaHMS(total_segundos, &hora, &minuto, &segundo);
	printf("%d:%d:%d", hora, minuto, segundo);

	return 0;
}
	
	
