/*
Ambrosino, um programador aposentado, começou a criar caracois. Mas não são caracóis comuns, eles vieram de um planeta distante onde os caracois sabem  falar e ler. Entretanto, Ambrosino começou a perceber que os caracois estão exibindo um comportamento muito estranho. Eles estão andando em um movimento espiral. Rapidamente, ele se lembrou dos primeiros algoritmos para percorrer matrizes. Normalmente o seu professor de programação mostrava como percorrer uma matriz horizontalmente (linha por linha) ou verticalmente (coluna por coluna). Então ele pensou, e se eu quiser percorrer a matriz da mesma maneira que os caracóis estão andando?
Você irá receber a dimensão e depois os números inteiros de uma matriz quadrada como entrada. Mas os números serão dados na ordem do "caminho de caracol". As figuras abaixo mostram como seria esse caminho. Sua missão é receber essa matriz e depois imprimir linha por linha.

No primeiro caso, na matriz 2X2, você receberá
2
8
5
3
7

e deve imprimir:
8
7
5
3

Já na matriz 4x4 você receberá:
4
3
1
6
12
14
30
20
15
77
76
56
34
2
8
9
65

e deve imprimir:
3
34
56
76
1
2
65
77
6
8
9
15
12
14
30
20
*/

#include <stdio.h>

void entradaDeDados(int ordemMatriz, int matriz[ordemMatriz][ordemMatriz], int inicioLinha, int inicioColuna, int finalLinha, int finalColuna, int quantidadeElementos, int contador) {

    for (int i = 0; i < 999; i++) {

        int lin;
        int col;

        if (contador < quantidadeElementos) {
            for (lin = inicioLinha; lin <= finalLinha; lin++) {
                scanf("%d", &matriz[lin][inicioColuna]);
                contador = contador + 1;
                if (contador == quantidadeElementos) {
                    break;
                }
            }
        }
        if (contador == quantidadeElementos) {
            break;
        }
        inicioColuna = inicioColuna + 1;

        if (contador < quantidadeElementos) {
            for (col = inicioColuna; col <= finalColuna; col++) {
                scanf("%d", &matriz[finalLinha][col]);
                contador = contador + 1;
                if (contador == quantidadeElementos) {
                    break;
                }
            }
        }
        if (contador == quantidadeElementos) {
            break;
        }
        finalLinha = finalLinha - 1;

        if (contador < quantidadeElementos) {
            for (lin = finalLinha; lin >= inicioLinha; lin--) {
                scanf("%d", &matriz[lin][finalColuna]);
                contador = contador + 1;
                if (contador == quantidadeElementos) {
                    break;
                }
            }
        }
        if (contador == quantidadeElementos) {
            break;
        }
        finalColuna = finalColuna - 1;

        if (contador < quantidadeElementos) {
            for (col = finalColuna; col >= inicioColuna; col--) {
                scanf("%d", &matriz[inicioLinha][col]);
                contador = contador + 1;
                if (contador == quantidadeElementos) {
                    break;
                }
            } 
        }
        if (contador == quantidadeElementos) {
            break;
        }
        inicioLinha = inicioLinha + 1;

    }

}

void leituraDeDados(int ordemMatriz, int matriz[ordemMatriz][ordemMatriz]) {

    for (int i = 0; i < ordemMatriz; i++) {
        for (int j = 0; j < ordemMatriz; j++) {
            printf("%d\n", matriz[i][j]);
        }
    }

}

int main() {

    int ordemMatriz;
    scanf("%d", &ordemMatriz);
    int matriz[ordemMatriz][ordemMatriz];

    int inicioLinha = 0;
    int inicioColuna = 0;
    int finalLinha = ordemMatriz - 1;
    int finalColuna = ordemMatriz - 1;

    entradaDeDados(ordemMatriz, matriz, inicioLinha, inicioColuna, finalLinha, finalColuna, ordemMatriz * ordemMatriz, 0);
    leituraDeDados(ordemMatriz, matriz);

    return 0;

}