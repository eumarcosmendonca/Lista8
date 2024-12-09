/*
Dada uma matriz NxN representando um mapa do jogo bomberman, onde '#' são paredes inquebráveis, '_' caminhos vazios e '&' paredes quebráveis.
Será dado uma sequência de coordenadas de bombas que destruirão em cruz(uma para cima, uma para a direita, uma para a esquerda e uma para baixo).
Nesse novo bomberman, no lugar das bordas existem buracos de minhoca que levarão a explosão para o outro lado do mapa.
As bombas só serão válidas se forem jogadas em caminhos vazios, caso não seja, ela não terá efeito nenhum no mapa.
*/

#include <stdio.h>

void mapa(int ordemMatriz, char matriz[ordemMatriz][ordemMatriz], int coordenadaX, int coordenadaY) {

    if (matriz[coordenadaX][coordenadaY] == '_') {

        if (coordenadaX - 1 < 0) {
            if (matriz[ordemMatriz - 1][coordenadaY] == '&') {
                matriz[ordemMatriz - 1][coordenadaY] = '_';
            }
        }

        else if (matriz[coordenadaX - 1][coordenadaY] == '&') {
             matriz[coordenadaX - 1][coordenadaY] = '_';
        }

        if (coordenadaX + 1 >= ordemMatriz) {
            if (matriz[0][coordenadaY] == '&') {
                matriz[0][coordenadaY] = '_';
            }
        }
        
        else if (matriz[coordenadaX + 1][coordenadaY] == '&') {
            matriz[coordenadaX + 1][coordenadaY] = '_';
        }

        if (coordenadaY - 1 < 0) {
            if (matriz[coordenadaX][ordemMatriz - 1] == '&') {
                matriz[coordenadaX][ordemMatriz - 1] = '_';
            }
        }

        else if (matriz[coordenadaX][coordenadaY - 1] == '&') {
            matriz[coordenadaX][coordenadaY - 1] = '_';
        }

        if (coordenadaY + 1 >= ordemMatriz) {
            if (matriz[coordenadaX][0] == '&') {
                matriz[coordenadaX][0] = '_';
            }
        }

        else if (matriz[coordenadaX][coordenadaY + 1] == '&') {
            matriz[coordenadaX][coordenadaY + 1] = '_';
        }

    }
    else {
        return;
    }

}

int main() {

    int ordemMatriz;
    scanf("%d", &ordemMatriz);
    char matriz[ordemMatriz][ordemMatriz];

    for (int i = 0; i < ordemMatriz; i++) {
        for (int j = 0; j < ordemMatriz; j++) {
            scanf(" %c", &matriz[i][j]);
        }
    }

    int quantidadeBombas;
    scanf("%d", &quantidadeBombas);

    int coordenadaX, coordenadaY;
    for (int i = 0; i < quantidadeBombas; i++) {
        scanf("%d %d", &coordenadaX, &coordenadaY);
        mapa(ordemMatriz, matriz, coordenadaX, coordenadaY);
    }

    for (int i = 0; i < ordemMatriz; i++) {
        for (int j = 0; j < ordemMatriz; j++) {
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;

}