/*============================================================================*/
/* GERADOR DE CASOS DE TESTE PARA O PROBLEMA DO CLASSIFICADOR DE VE�CULOS     */
/*----------------------------------------------------------------------------*/
/* Autor: Bogdan T. Nassu                                                     */
/*============================================================================*/
/** Um gerador de casos de teste para o problema do classificador de ve�culos.
 * O gerador funciona abrindo uma imagem de refer�ncia e adicionando sobre ela
 * imagens de ve�culos, al�m de algum ru�do. A quantidade e os tipos de
 * ve�culos gerados s�o armazenados, para futura compara��o. O c�digo deste
 * m�dulo ficou um pouco "ing�nuo", porque decidi mant�-lo compacto e sem
 * precisar tratar de fatores como escala e rota��o. */
/*============================================================================*/

#ifndef __GERADOR_DE_TESTES_H
#define __GERADOR_DE_TESTES_H

/*============================================================================*/

#include "imagem.h"
#include "trabalho3.h"

/*============================================================================*/

typedef struct
{
	Imagem3C* background;
	Imagem1C* path;
	Imagem3C** img_veiculos;
	int contagem_de_veiculos [N_TIPOS_DE_VEICULOS];
	int n_gerados;

} GeradorDeTestes;

/*============================================================================*/

GeradorDeTestes* criaGeradorDeTestes ();
void destroiGeradorDeTestes (GeradorDeTestes* g);
Imagem3C* geraCasoDeTeste (GeradorDeTestes* g, int seed);
Imagem3C* getBackground (GeradorDeTestes* g);
int pegaNVeiculosGerados (GeradorDeTestes* g);
int pegaNGerados (GeradorDeTestes* g, int tipo_veiculo);

/*============================================================================*/
#endif /* __GERADOR_DE_TESTES_H */
