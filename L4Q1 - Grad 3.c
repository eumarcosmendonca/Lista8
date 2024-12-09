/*
Um dos problemas mais recorrentes das aulas de IP é a superlotação do Grad3, fazendo com que vários alunos ao chegar percam muito do seu precioso tempo até encontrar um computador livre para que possa resolver a sua lista d exercícios. Como um bom programador, e cansado de perder seu tempo atrás do lugar perfeito, você se incubiu da tarefa de maximizar o tempo de estudo dos alunos durante as aulas de IP. E para garantir o máximo de eficiência no grad, você decidiu criar um programa que encontra o computador mais conveniente para alunos que chegam atrasados.
A conveniência é obtida pelo tempo (em segundos) da entrada no grad até estar sentado com o computador ligado, e esse tempo vai ser calculado da seguinte forma:Tempo = Distância * 20
Tempo = Distância * 20
Distância = √(X²+Y²)
Caso o computador em questão esteja desligado, adiciona-se 40 segundos ao tempo.
X e Y são coordenadas no mapa de computadores que começam em 0, da esquerda pra direita e de cima pra baixo, respectivamente.
Obs: A distância será medida a partir das coordenadas (0,0)
*/

#include <stdio.h>
#include <math.h>

double distanciaTempo(int i, int j) {
    double conta1 = (i * i) + (j * j);
    double conta2 = sqrt(conta1);
    double conta3 = conta2 * 20;
    return conta3;
}

int main() {

    char matriz[5][10];
    double menorResultado = 100000.00;
    int menorPosicaoI;
    int menorPosicaoJ;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            scanf(" %c", &matriz[i][j]);
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            if (matriz[i][j] == '0') {
                double resultado = distanciaTempo(i, j);
                resultado = resultado + 40.0;
                if (resultado < menorResultado) {
                    menorResultado = resultado;
                    menorPosicaoI = i;
                    menorPosicaoJ = j;
                }
            }
            if (matriz[i][j] == '1') {
                double resultado = distanciaTempo(i, j);
                if (resultado < menorResultado) {
                    menorResultado = resultado;
                    menorPosicaoI = i;
                    menorPosicaoJ = j;
                }
            }
        }
    }

    if (menorResultado == 100000.00) {
        printf("Tristemente voce vai ter que aturar os PCs do grad 4");
    }
    else {
        printf("Vai la pro computador %d da fileira %d", menorPosicaoJ, menorPosicaoI);
    }

    return 0;

}