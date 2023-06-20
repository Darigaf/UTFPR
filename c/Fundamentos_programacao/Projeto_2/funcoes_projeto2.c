//quest�o 3
void inverteSinal (double* dados, int n_amostras){
    int i, tam_vet=n_amostras-1;
    //inver � a variavel que vai auxiliar da inver��o
    double inver;

    //o for vai at� metade de n_amostras pois n�o � necessario mais que isso para a inver��o
    for(i=0; i<n_amostras/2; i++){
        //inver recebe o valor de dados na casa tam_vet-i
        inver=dados[tam_vet-i];

        dados[tam_vet-i]=dados[i];

        //dados na posi��o i recebe o valor de dados na posi��o tam_vet-i
        dados[i]=inver;
    }
}
//quest�o 5
void filtroDaMedia (double* dados, int n_amostras, int largura){
    int i, j, med;
    double media;

    //o for come�a e termina nessas condi��es para n�o passar o limite do vetor quando forem calculadas as medias
    for(i=(largura-1)/2; i<n_amostras-(largura-1)/2; i++){
        media=0;
        med=0;

        //� feita a somatoria dos valores de i-(largura-1)/2 at� i+(largura-1)/2
        for(j=i-(largura-1)/2; j<=i+(largura-1)/2; j++){
            media+=dados[j];
            med++;
        }
        //� calculada a m�dia
        media=media/med;
        dados[i]=media;
    }
}
