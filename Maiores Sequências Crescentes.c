/*
Dado uma matriz, você deverá informar qual o tamanho da maior sequência crescente daquela linha.
OBS: Não você não poderá aplicar os conceitos de array/matriz circular para essa questão.
*/

#include <stdio.h>

int main() {

    int linha, coluna;
    scanf("%d %d", &linha, &coluna);
    int matriz[linha][coluna];
    int maiorSequencia = 1;

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < linha; i++) {
        int contadorMaior = 1;
        int contador = 1;
        for (int j = 0; j < coluna - 1; j++) {
            if (j + 1 == coluna) {
                break;
            }
            else if (matriz[i][j] - matriz[i][j+1] <= 0) {
                contador++;
            }
            else {
                if (contador >= maiorSequencia) {
                    maiorSequencia = contador;
                }
                contador = 1;
            }
            if (contador > contadorMaior) {
                contadorMaior = contador;
            }
        }
        printf("Linha %d: %d\n", i, contadorMaior);
        if (contador > maiorSequencia) {
            maiorSequencia = contador;
        }
    }

    printf("Maior Sequencia: %d", maiorSequencia);

    return 0;

}