#include <stdio.h>

int arredondar(double x){
	double resultado = x;
	if(x<0){
		return resultado -= 0.5;	
	}
	if(x>0){
		return resultado += 0.5;	
	}
}
int main(){
	double x;
	int arredondado;
	scanf("%lf", &x);
	arredondado = arredondar(x);
	printf("%d", arredondado);
	

}
