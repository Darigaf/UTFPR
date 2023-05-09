#! /bin/bash

echo "Qual o número da aula?"
read Nome_Pasta
echo "Qual a quantidade de exercícios?"
read Numero_Exercicios
mkdir Fundamentos_programacao/Aula_$Nome_Pasta
cd Fundamentos_programacao/Aula_$Nome_Pasta
touch Makefile
echo $Numero_Exercicios
for ((i = 1; i < $Numero_Exercicios+1; i++))
do
	echo $i': atividade_'$i'.c' >> Makefile
	echo '	gcc atividade_'$i'.c -o atividade'$i' -lm  -W -Wall -pedantic'>> Makefile

	echo "#include <stdio.h>
		
int main(){

	return 0;
}
	
	" >> atividade_$i.c
done

