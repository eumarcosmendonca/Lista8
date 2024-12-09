/*
A entidade recebeu um pacote misterioso em sua casa, contendo um quadro e um bilhete. Ao prestar atenção no quadro, a Entidade percebeu que era composto por um tamanho n x m e que cada "posição" do quadro era composto por um número de 0 a 9.
O bilhete dizia que o quadro possuía um dispositivo de bomba-relógio e que, caso a Entidade não resolvesse o seu desafio, o quadro iria explodir toda a sua casa. O desafio consiste em identificar quantos quadrados do tipo 2 x 2 compostos por 0, 1, 2, e 3 (um de cada) existem no quadro. Entretanto, como o quadro era muito grande e era difícil de identificar esses quadrados, ela pediu a ajuda a você!

Por exemplo:

É um quadrado válido:

1 0

2 3       

É um quadrado válido:

3 0

1 2

Não é um quadrado válido:

3 9

1 2

Ainda podemos ter dois quadrados válidos com uma intersecção entre os dois:

3 0 1

1 2 3

*/

#include <stdio.h>

int verificador(int matriz[2][2]) {

    int verificador1 = 0;
    int verificador2 = 0;
    int verificador3 = 0;
    int verificador4 = 0;
    int contador = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (matriz[i][j] == 0 && verificador1 == 0) {
                verificador1++;
                contador++;
            }
            if (matriz[i][j] == 1 && verificador2 == 0) {
                verificador2++;
                contador++;
            }
            if (matriz[i][j] == 2 && verificador3 == 0) {
                verificador3++;
                contador++;
            }
            if (matriz[i][j] == 3 && verificador4 == 0) {
                verificador4++;
                contador++;
            }
        }
    }

    return contador;

}

int main() {

    int linha, coluna;
    int quantidade = 0;
    scanf("%d %d", &linha, &coluna);
    int matriz[linha][coluna];
    int matrizAuxiliar[2][2];

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int i = 0;

    while (i < linha - 1) {
        
        int j = 0;

        while (j < coluna - 1) {

        matrizAuxiliar[0][0] = matriz[i][j];
        matrizAuxiliar[0][1] = matriz[i][j+1];
        matrizAuxiliar[1][0] = matriz[i+1][j];
        matrizAuxiliar[1][1] = matriz[i+1][j+1];

        if (verificador(matrizAuxiliar) == 4) {
            quantidade++;
        }

        j++;

        }

        i++;
        
    }
    

    printf("%d", quantidade);

    return 0;

}