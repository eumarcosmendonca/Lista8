/*
O BB-8, vasculhando os destroços de uma nave, encontrou um “dispositivo holograma” que transmitia a batalha de Luke Skywalker e Darth Vader. Por ser um robô, BB-8 só consegue interpretar números binários, então pediu sua ajuda para programá-;lo a fim de entender a batalha.
Sua tarefa é escrever um programa que consiga simular a sequência de rodadas de golpes e, ao final da mesma, dizer quem foi o vencedor (se é que houve um).

Regras da batalha:

A batalha consiste em no máximo 10 rodadas de golpes.
Cada rodada é representada por duas matrizes. A primeira representa o golpe de Luke e a segunda de Vader.
Cada matriz de golpe é composta de 3 linhas e 3 colunas.
Para ser considerada válida, todos os valores da matriz de golpe precisam ser iguais a 0, exceto a diagonal principal ou secundária, nas quais todos os valores precisam ser iguais a 1. Qualquer matriz de golpe que não atenda as exigências é inválida.
Uma matriz de golpe inválida significa que seu autor não conseguiu atacar e pode receber dano se a matriz de golpe do adversário for válida.
Em rodadas que ambas as matrizes de golpes são válidas e com as diagonais iguais, ambos os guerreiros recebem os ataques.
Se as duas matrizes forem válidas e diferentes, nenhum dos guerreiros toma dano na rodada.
Quando um combatente é atingido por um golpe, o mesmo perde 15 pontos de vida.
*/

#include <stdio.h>

int verificacao(int matriz[][3]) {

    int contadorUm = 0;
    int contadorDiagonalPrimaria = 0;
    int contadorDiagonalSecundaria = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                if (i == 1 && j == 1) {
                    if (matriz[i][j] == 1) {
                        contadorDiagonalPrimaria++;
                        contadorDiagonalSecundaria++;
                    }
                }
                else if (matriz[i][j] == 1) {
                    contadorDiagonalPrimaria++;
                }
            }
            else if (i + j == 2) {
                if (matriz[i][j] == 1) {
                    contadorDiagonalSecundaria++;
                }
            }
            else {
                if (matriz[i][j] == 1) {
                    contadorUm++;
                }
            }
        }
    }

    if (contadorDiagonalPrimaria == 3 && contadorUm == 0) {
        return 1;
    }
    if (contadorDiagonalSecundaria == 3 && contadorUm == 0) {
        return 2;
    }
    else {
        return 0;
    }

}

int main() {

    int vidaLuke, vidaVader;
    scanf("%d %d", &vidaLuke, &vidaVader);
    int matrizLuke[3][3];
    int matrizVader[3][3];

    for (int rodadas = 0; rodadas < 10; rodadas++) {

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%d", &matrizLuke[i][j]);
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%d", &matrizVader[i][j]);
            }
        }

        int resultadoLuke = verificacao(matrizLuke);
        int resultadoVader = verificacao(matrizVader);

        if (resultadoLuke == 1 && resultadoVader == 1) {
            vidaVader = vidaVader - 15;
            vidaLuke = vidaLuke - 15;
        }
        if (resultadoLuke == 2 && resultadoVader == 2) {
            vidaVader = vidaVader - 15;
            vidaLuke = vidaLuke - 15;
        }
        if (resultadoLuke == 1 && resultadoVader == 0) {
            vidaVader = vidaVader - 15;
        }
        if (resultadoLuke == 2 && resultadoVader == 0) {
            vidaVader = vidaVader - 15;
        }
        if (resultadoVader == 1 && resultadoLuke == 0) {
            vidaLuke = vidaLuke - 15;
        }
        if (resultadoVader == 2 && resultadoLuke == 0) {
            vidaLuke = vidaLuke - 15;
        }
        if (vidaVader <= 0 && vidaLuke > 0) {
            printf("Luke Skywalker venceu.");
            break;
        }
        if (vidaLuke <= 0 && vidaVader > 0) {
            printf("Darth Vader venceu.");
            break;
        }
        if (vidaLuke <= 0 && vidaVader <= 0) {
            printf("Houve empate.");
            break;
        }

    }

    if (vidaLuke > 0 && vidaVader > 0) {
        if (vidaLuke > vidaVader) {
            printf("Luke Skywalker venceu.");
        }
        if (vidaVader > vidaLuke) {
            printf("Darth Vader venceu.");
        }
        if (vidaLuke == vidaVader) {
            printf("Houve empate.");
        }
    }

    return 0;

}