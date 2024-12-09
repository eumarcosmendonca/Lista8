/*
Você está produzindo um jogo de labirinto, ou seja, as colisões com as paredes são muito importante.
Para lidar com elas, você construiu um vetor bidimensional de 0s e 1s, onde "0" representa parede, e "1" representa o caminho por onde você pode se movimentar.
Vamos testar se você construiu o programa para lidar com isso precisamente.
Dadas as seguintes entradas:
Número de linhas;
Número de colunas;
Vetor bidimensional com 0s e 1s;
A quantidade e sequência de comandos, informando a movimentação do seu personagem dentro do "mapa";
Posição (linha e coluna) inicial do personagem.
informe em que posição ele estará ao fim do programa.
Os comandos de direção serão representados por:
Direita: D
Esquerda: E
Cima: C
Baixo: B
*/

#include <stdio.h>

void movimentacao(int linhas, int colunas, int matriz[][colunas], int quantidadeMovimentos, char movimentosPersonagem[], int coordenadaX, int coordenadaY) {

    for (int i = 0; i < quantidadeMovimentos; i++) {

        if (movimentosPersonagem[i] == 'D') {
            if (coordenadaY + 1 >= colunas) {
                continue;
            }
            else {
                if (matriz[coordenadaX][coordenadaY + 1] != 0) {
                    coordenadaY = coordenadaY + 1;
                }
            }
        }

        if (movimentosPersonagem[i] == 'E') {
            if (coordenadaY - 1 < 0) {
                continue;
            }
            else {
                if (matriz[coordenadaX][coordenadaY - 1] != 0) {
                    coordenadaY = coordenadaY - 1;
                }
            }
        }

        if (movimentosPersonagem[i] == 'C') {
            if (coordenadaX - 1 < 0) {
                continue;
            }
            else {
                if (matriz[coordenadaX - 1][coordenadaY] != 0) {
                    coordenadaX = coordenadaX - 1;
                }
            }
        }

        if (movimentosPersonagem[i] == 'B') {
            if (coordenadaX + 1 >= linhas) {
                continue;
            }
            else {
                if (matriz[coordenadaX + 1][coordenadaY] != 0) {
                    coordenadaX = coordenadaX + 1;
                }
            }
        }
            
    }

    printf("(%d,%d)", coordenadaX, coordenadaY);

}

int main() {

    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);
    int matriz[linhas][colunas];
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int quantidadeMovimentos;
    scanf("%d", &quantidadeMovimentos);
    char movimentosPersonagem[quantidadeMovimentos];
    for (int i = 0; i < quantidadeMovimentos; i++) {
        char movimento;
        scanf(" %c", &movimento);
        movimentosPersonagem[i] = movimento; 
    }

    int coordenadaX, coordenadaY;
    scanf("%d %d", &coordenadaX, &coordenadaY);

    movimentacao(linhas, colunas, matriz, quantidadeMovimentos, movimentosPersonagem, coordenadaX, coordenadaY);

    return 0;

}