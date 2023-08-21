//questão 3
void inverteSinal (double* dados, int n_amostras){
    int i, tam_vet=n_amostras-1;
    //inver é a variavel que vai auxiliar da inverção
    double inver;

    //o for vai até metade de n_amostras pois não é necessario mais que isso para a inverção
    for(i=0; i<n_amostras/2; i++){
        //inver recebe o valor de dados na casa tam_vet-i
        inver=dados[tam_vet-i];

        dados[tam_vet-i]=dados[i];

        //dados na posição i recebe o valor de dados na posição tam_vet-i
        dados[i]=inver;
    }
}
//questão 5
void filtroDaMedia (double* dados, int n_amostras, int largura){
    int i, j, med;
    double media;

    //o for começa e termina nessas condições para não passar o limite do vetor quando forem calculadas as medias
    for(i=(largura-1)/2; i<n_amostras-(largura-1)/2; i++){
        media=0;
        med=0;

        //é feita a somatoria dos valores de i-(largura-1)/2 até i+(largura-1)/2
        for(j=i-(largura-1)/2; j<=i+(largura-1)/2; j++){
            media+=dados[j];
            med++;
        }
        //é calculada a média
        media=media/med;
        dados[i]=media;
    }
}
