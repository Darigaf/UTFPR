#include <stdio.h>
#include <stdlib.h>

typedef struct coordenada {
    int x;
    int y;
} Coordenada;

int** alocaMatriz(int nl, int nc);
void imprimeMatriz(int **m, int tam);
void desalocaMatriz(int **mat, int nl);
void imprimeCriativ(int **m, int nl, int nc, Coordenada *c, int tamc); //a ser implementada na fase das tarefas
void inicializaLabirinto(int **m, int tam);
void preencheMatrizCusto(int **m, int tam, int xQueijo, int yQueijo);
Coordenada* calculaCaminho (int **m, int tam, int xRato, int yRato, int *nroPassos);
//int testaCoordenadas(Coordenada c, int tam, char alvo[]); //a ser implementada na fase dos desafios

int main() {
    int **lab,
        tam,     //tamanho fixo para fase de testes
        nPassos; //vai armazenar o tamanho do caminho c

    Coordenada *c,      //armazena as coordenadas do caminho
               cRato,   //coordenadas do Rato
               cQueijo; //coordenadas do Queijo

    tam = 10;

    cQueijo.x = 5;
    cQueijo.y = 2;

    cRato.x = 8;
    cRato.y = 8;

    lab = alocaMatriz(tam, tam);    //aloca labirinto
    inicializaLabirinto(lab, tam);  //inicializa com configuração padrão
    imprimeMatriz(lab, tam);        //imprime
    preencheMatrizCusto(lab, tam, cQueijo.x, cQueijo.y);
                //preenche a matriz de custo, considerando a
                //(5,2) como localização do queijo - configuração fixa
                // para facilitar os testes

    imprimeMatriz(lab, tam);

    //c = calculaCaminho(lab, tam, cRato.x, cRato.y, &nPassos);
                // preenche c com coordenadas do caminho entre as coordenadas
                // do rato (8,8). Depois, alterar de tal forma
                // a ler do teclado.

    //imprimir caminho de forma criativa
    //imprimeCriativ(lab, tam, tam, c, nPassos);

    desalocaMatriz(lab, tam);
    free(c);
    return 0;
}

int** alocaMatriz(int nl, int nc) {
    int **m, i;

    m = (int**) malloc(sizeof (int*) * nl);

    for (i = 0; i < nl; ++i)
        m[i] = (int*) malloc(sizeof (int) * nc);

    return m;
}

void desalocaMatriz(int **mat, int nl) {
    int i;
    for (i = 0; i < nl; ++i) free(mat[i]);
    free(mat);
}

void imprimeMatriz(int **m, int tam) {
    int i, j;

    for (i = 0; i < tam; ++i){
        for (j = 0; j < tam; ++j)
            printf("%4d", m[i][j]);
        printf("\n");
    }
    printf("\n");
}

void inicializaLabirinto(int **m, int tam) {
    int i, j;

    for (i = 0; i < tam; ++i)
        for (j = 0; j < tam; ++j)
            m[i][j] = -1;

    m[2][1] = -2;
    m[2][2] = -2;
    m[2][3] = -2;
    m[3][3] = -2;
    m[3][4] = -2;
    m[4][4] = -2;
    m[5][4] = -2;
    m[6][4] = -2;
}


void preencheMatrizCusto(int **m, int tam, int xQueijo, int yQueijo) {

    int i, j,
        dist = 0,
        deNovo = 1;

    m[xQueijo][yQueijo] = 0;
    while (deNovo == 1) {
        deNovo = 0;
        for (i = 1; i < tam - 1; ++i) {
            for (j = 1; j < tam - 1; ++j) {
                if (m[i][j] == dist) {
                    if (m[i-1][j] == -1)
                        m[i-1][j] = dist + 1;
                    if (m[i+1][j] == -1)
                        m[i+1][j] = dist + 1;
                    if (m[i][j-1] == -1)
                        m[i][j-1] = dist + 1;
                    if (m[i][j+1] == -1)
                        m[i][j+1] = dist + 1;
                    deNovo = 1;
                }
            }
        }
        ++dist;
    }
}



Coordenada* calculaCaminho (int **m, int tam, int xRato, int yRato, int *nroPassos) {
    printf("A ser implementada")!
}

void imprimeCriativ(int **m, int nl, int nc, Coordenada *c, int tamc) {
   printf("A ser implementada")!
}
