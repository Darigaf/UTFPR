#include <stdio.h>
#include <stdlib.h>
int **alocaMatriz(int tam);
void inicializaLabirinto(int **m, int tam);
void preencheMatrizCusto(int **m, int tam, int xqueijo, int yqueijo);
void calculaCaminho (int **m, int tam, int **x, int**y, int *nroPassos, int xrato, int yrato);

int main() {
  // declaração das variaveis
  int tam, **matriz, xqueijo, yqueijo, nroPassos = 0, *x, *y, xrato, yrato;

  //alocação da matriz
  printf("tamanho e qtd de paredes: \n");
  scanf("%d\n",&tam);
  matriz = alocaMatriz(tam);
  inicializaLabirinto(matriz, tam);

  preenche matriz custo e calcula caminho
  printf("posicao x y queijo\n");
  scanf("%d %d",&xqueijo,&yqueijo);
  printf("posicao x y rata:\n");
  scanf("%d %d",&xrato,&yrato);
  preencheMatrizCusto(matriz, tam, xqueijo, yqueijo);
  calculaCaminho(matriz, tam, x, y, nroPassos, xrato, yrato);



  free(matriz);
  return 0;
}

int **alocaMatriz(int tam){
  int **m;

  m = (int **) malloc(tam*sizeof(int*));

  for (int i = 0; i < tam; i++)
    m[i] = (int *) malloc(tam*sizeof(int));

  return m;
}

void imprimeMatriz(int **m, int tam){
  for (int i = 0; i < tam; i++) {
    for (int j = 0; j < tam; j++) {
      printf("%3d",m[i][j]);
    }
    printf("\n");
  }
}

void inicializaLabirinto(int **m, int tam){
    int parede,x,y;
    // printf("Digite a qtd de paredes:\n");
    scanf("%d",&parede);
    for(int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            m[i][j] = 0;
        }
    }
    for(int i = 0; i < parede; i++){
        imprimeMatriz(m, tam);
        printf("Digite as coordenadas da parede %d: ", i+1);
        scanf("%d %d",&x,&y);
        m[x][y]= -1;
        system("clear");
    }
}

void preencheMatrizCusto(int **m, int tam, int xqueijo, int yqueijo){
      int i, j, k=0;

      m[xqueijo][yqueijo]=0;

      while(alt==1){
         alt=0;
         for(i=0;i<tam;i++){
             for(j=0;j<tam;j++){
                   if(m[i][j]==k){
                        if(m[i-1][j]!=-1)
                            m[i-1][j]=k+1;
                        if(m[i+1][j]!=-1)
                            m[i+1][j]=k+1;
                        if(m[i][j-1]!=-1)
                            m[i][j-1]=k+1;
                        if(m[i][j+1]!=-1)
                            m[i][j+1]=k+1;
                   }
                   k++;
             }
         }
      }
}

void calculaCaminho (int **m, int tam, int **x, int**y, int *nroPassos, int xrato, int yrato){
    int  x=0, y=0;
    *nroPassos=m[xrato][yrato];

    *x=(int *)malloc(*nroPassos*sizeof(int));
    *y=(int *)malloc(*nroPassos*sizeof(int));
    //(*x)[i]


    for(i=0; i<*nroPassos; i++){
        if(m[xrato-1][yrato]==m[xrato][yrato])
                xrato--;
        else if(m[xrato+1][yrato]==m[xrato][yrato])
                xrato++;
        else if(m[xrato][yrato-1]==m[xrato][yrato])
                yrato--;
        else if(m[xrato][yrato+1]==m[xrato][yrato])
                yrato++;

        (*x)[i]=xrato;
        (*y)[i]=yrato;
    }
}
