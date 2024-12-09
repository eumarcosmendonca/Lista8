/*
Kcaj e Ansa são dois amigos e estudantes brilhantes que adoram desafios bastante interessantes que envolvem computação e matemática. Em um certo dia os dois decidiram-se inscrever em mais um desafio para competir, o Campeonato Brasileiro de submatrizes organizado pela SBSM (Sociedade Brasileira de Submatrizes).
O torneio que consiste em duelos de um contra um nos quais cada competidor escreve uma matriz K de tamanho NxM e em seguida escolhe a submatriz de K que possui a maior soma de números primos em sua diagonal principal e que tenha tamanho (N-1)x(M-1), o ganhador do duelo será aquele que obter a maior soma na submatriz escolhida.
Como Kcaj e Ansa são bastante inteligentes, eles acabaram chegando a final do campeonato e agora eles terão que se enfrentar pelo titulo.
Com isso, Jvaaa, o diretor da SBSM enviou um convite para que você o ajude ele na missão de definir quem foi o campeão da grande final do Campeonato Brasileiro de submatrizes.

Observações do regulamento do torneio:

1- Os competidores só podem escrever matrizes compostas por números distintos, ou seja, um mesmo número não pode aparecer mais de uma vez na matriz escrita pelo competidor.

2- Em caso de empate na escolha da melhor submatriz do competidor, o critério de desempate será escolher a submatriz de K que possua o maior número primo em sua diagonal principal.

3- Uma matriz NxM tem exatas 4 submatrizes de tamanho (N-1)x(M-1) e o competidor deve sempre escolher a melhor delas para o duelo.

Exemplo:

Para a matriz:

11 2 3
4 5 6
7 8 9

Existem as submatrizes válidas:

11 2
4 5

Com 2 números primos (11 e 5) em sua diagonal principal e com soma total 16.

2 3
5 6

Com 1 número primo (2) em sua diagonal principal e com soma total 2.

4 5
7 8

Com nenhum número primo em sua diagonal principal e com soma total 0.

5 6
8 9

Com 1 número primo (5) em sua diagonal principal e com soma total 5.

Logo a submatriz que deverá ser escolhida pelo competidor é a submatriz 1.
*/

#include <stdio.h>

void print(int linha, int coluna, int matriz[linha][coluna]) {

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            if (j == coluna - 1) {
                printf("%d", matriz[i][j]);
            }
            else {
                printf("%d ", matriz[i][j]);    
            }
        }
        printf("\n");
    }

}

int verificadorNumeroPrimo(int numero) {

    if (numero <= 1) {
        return 1;
    }
    
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return 1;
        }
    }
    
    return 0;
}

int somaDiagonalNumeroPrimo(int tamanhoLinhaSubmatriz, int tamanhoColunaSubmatriz, int matriz[tamanhoLinhaSubmatriz][tamanhoColunaSubmatriz], int soma) {

    int numero;
    for (int i = 0; i < tamanhoLinhaSubmatriz; i++) {
        int divisiveis = 0;
        for (int j = 0; j < tamanhoColunaSubmatriz; j++) {
            if (i == j) {
                numero = matriz[i][j];
                int resultado = verificadorNumeroPrimo(numero);
                if (resultado == 0) {
                    soma = soma + matriz[i][j];
                }
            }
        }
    }

    return soma;

}

int maiorNumeroPrimo(int tamanhoLinhaSubmatriz, int tamanhoColunaSubmatriz, int matriz[tamanhoLinhaSubmatriz][tamanhoColunaSubmatriz], int maiorNumero) {

    int numero;
    for (int i = 0; i < tamanhoLinhaSubmatriz; i++) {
        int divisiveis = 1;
        for (int j = 0; j < tamanhoColunaSubmatriz; j++) {
            if (i == j) {
                numero = matriz[i][j];
                int resultado = verificadorNumeroPrimo(numero);
                if (resultado == 0) {
                    if (matriz[i][j] > maiorNumero) {
                        maiorNumero = matriz[i][j];
                    }
                }
            }
        }
    }

    return maiorNumero;

}

int main() {

    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);
    int matrizKcaj[linhas][colunas];
    int matrizAnsa[linhas][colunas];

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matrizKcaj[i][j]);
        }
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matrizAnsa[i][j]);
        }
    }

    int tamanhoLinhaSubmatriz = linhas - 1;
    int tamanhoColunaSubmatriz = colunas - 1;
    int subMatrizKcaj1[tamanhoLinhaSubmatriz][tamanhoColunaSubmatriz];
    int subMatrizKcaj2[tamanhoLinhaSubmatriz][tamanhoColunaSubmatriz];
    int subMatrizKcaj3[tamanhoLinhaSubmatriz][tamanhoColunaSubmatriz];
    int subMatrizKcaj4[tamanhoLinhaSubmatriz][tamanhoColunaSubmatriz];
    int subMatrizAnsa1[tamanhoLinhaSubmatriz][tamanhoColunaSubmatriz];
    int subMatrizAnsa2[tamanhoLinhaSubmatriz][tamanhoColunaSubmatriz];
    int subMatrizAnsa3[tamanhoLinhaSubmatriz][tamanhoColunaSubmatriz];
    int subMatrizAnsa4[tamanhoLinhaSubmatriz][tamanhoColunaSubmatriz];

    for (int i = 0; i < tamanhoLinhaSubmatriz; i++) {
        for (int j = 0; j < tamanhoColunaSubmatriz; j++) {
            subMatrizKcaj1[i][j] = matrizKcaj[i][j];
        }
    }

    for (int i = 0; i < tamanhoLinhaSubmatriz; i++) {
        for (int j = 0; j < tamanhoColunaSubmatriz; j++) {
            subMatrizKcaj2[i][j] = matrizKcaj[i][j + 1];
        }
    }

    for (int i = 0; i < tamanhoLinhaSubmatriz; i++) {
        for (int j = 0; j < tamanhoColunaSubmatriz; j++) {
            subMatrizKcaj3[i][j] = matrizKcaj[i + 1][j];
        }
    }

    for (int i = 0; i < tamanhoLinhaSubmatriz; i++) {
        for (int j = 0; j < tamanhoColunaSubmatriz; j++) {
            subMatrizKcaj4[i][j] = matrizKcaj[i + 1][j + 1];
        }
    }

    for (int i = 0; i < tamanhoLinhaSubmatriz; i++) {
        for (int j = 0; j < tamanhoColunaSubmatriz; j++) {
            subMatrizAnsa1[i][j] = matrizAnsa[i][j];
        }
    }

    for (int i = 0; i < tamanhoLinhaSubmatriz; i++) {
        for (int j = 0; j < tamanhoColunaSubmatriz; j++) {
            subMatrizAnsa2[i][j] = matrizAnsa[i][j + 1];
        }
    }

    for (int i = 0; i < tamanhoLinhaSubmatriz; i++) {
        for (int j = 0; j < tamanhoColunaSubmatriz; j++) {
            subMatrizAnsa3[i][j] = matrizAnsa[i + 1][j];
        }
    }

    for (int i = 0; i < tamanhoLinhaSubmatriz; i++) {
        for (int j = 0; j < tamanhoColunaSubmatriz; j++) {
            subMatrizAnsa4[i][j] = matrizAnsa[i + 1][j + 1];
        }
    }

    int resultadoSomaDiagonalNumeroPrimoKcaj1 = somaDiagonalNumeroPrimo(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizKcaj1, 0);
    int resultadoSomaDiagonalNumeroPrimoKcaj2 = somaDiagonalNumeroPrimo(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizKcaj2, 0);
    int resultadoSomaDiagonalNumeroPrimoKcaj3 = somaDiagonalNumeroPrimo(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizKcaj3, 0);
    int resultadoSomaDiagonalNumeroPrimoKcaj4 = somaDiagonalNumeroPrimo(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizKcaj4, 0);
    int resultadoSomaDiagonalNumeroPrimoAnsa1 = somaDiagonalNumeroPrimo(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizAnsa1, 0);
    int resultadoSomaDiagonalNumeroPrimoAnsa2 = somaDiagonalNumeroPrimo(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizAnsa2, 0);
    int resultadoSomaDiagonalNumeroPrimoAnsa3 = somaDiagonalNumeroPrimo(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizAnsa3, 0);
    int resultadoSomaDiagonalNumeroPrimoAnsa4 = somaDiagonalNumeroPrimo(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizAnsa4, 0);

    int maiorValorKcaj = 0;
    int maiorValorAnsa = 0;
    int maiorMatrizKcaj = 0;
    int maiorMatrizAnsa = 0;
    if (resultadoSomaDiagonalNumeroPrimoKcaj1 > maiorValorKcaj) {
        maiorValorKcaj = resultadoSomaDiagonalNumeroPrimoKcaj1;
        maiorMatrizKcaj = 1;
    }
    if (resultadoSomaDiagonalNumeroPrimoKcaj2 > maiorValorKcaj) {
        maiorValorKcaj = resultadoSomaDiagonalNumeroPrimoKcaj2;
        maiorMatrizKcaj = 2;
    }
    if (resultadoSomaDiagonalNumeroPrimoKcaj3 > maiorValorKcaj) {
        maiorValorKcaj = resultadoSomaDiagonalNumeroPrimoKcaj3;
        maiorMatrizKcaj = 3;
    }
    if (resultadoSomaDiagonalNumeroPrimoKcaj4 > maiorValorKcaj) {
        maiorValorKcaj = resultadoSomaDiagonalNumeroPrimoKcaj4;
        maiorMatrizKcaj = 4;
    }
    if (resultadoSomaDiagonalNumeroPrimoAnsa1 > maiorValorAnsa) {
        maiorValorAnsa = resultadoSomaDiagonalNumeroPrimoAnsa1;
        maiorMatrizAnsa = 1;
    }
    if (resultadoSomaDiagonalNumeroPrimoAnsa2 > maiorValorAnsa) {
        maiorValorAnsa = resultadoSomaDiagonalNumeroPrimoAnsa2;
        maiorMatrizAnsa = 2;
    }
    if (resultadoSomaDiagonalNumeroPrimoAnsa3 > maiorValorAnsa) {
        maiorValorAnsa = resultadoSomaDiagonalNumeroPrimoAnsa3;
        maiorMatrizAnsa = 3;
    }
    if (resultadoSomaDiagonalNumeroPrimoAnsa4 > maiorValorAnsa) {
        maiorValorAnsa = resultadoSomaDiagonalNumeroPrimoAnsa4;
        maiorMatrizAnsa = 4;
    }

    if (maiorMatrizKcaj == 1) {
        print(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizKcaj1);
        printf("\n");
    }
    if (maiorMatrizKcaj == 2) {
        print(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizKcaj2);
        printf("\n");
    }
    if (maiorMatrizKcaj == 3) {
        print(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizKcaj3);
        printf("\n");
    }
    if (maiorMatrizKcaj == 4) {
        print(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizKcaj4);
        printf("\n");
    }
    if (maiorMatrizAnsa == 1) {
        print(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizAnsa1);
        printf("\n");
    }
    if (maiorMatrizAnsa == 2) {
        print(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizAnsa2);
        printf("\n");
    }
    if (maiorMatrizAnsa == 3) {
        print(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizAnsa3);
        printf("\n");
    }
    if (maiorMatrizAnsa == 4) {
        print(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizAnsa4);
        printf("\n");
    }
    if (maiorValorKcaj > maiorValorAnsa) {
        printf("Kcaj ganhou");
    }
    if (maiorValorAnsa > maiorValorKcaj) {
        printf("Ansa ganhou");
    }
    
    int resultadorMaiorNumeroPrimoKcaj;
    int resultadorMaiorNumeroPrimoAnsa;
    if (maiorValorKcaj == maiorValorAnsa) {

        if (maiorMatrizKcaj == 1) {
            resultadorMaiorNumeroPrimoKcaj = maiorNumeroPrimo(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizKcaj1, 0);
        }
        if (maiorMatrizKcaj == 2) {
            resultadorMaiorNumeroPrimoKcaj = maiorNumeroPrimo(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizKcaj2, 0);
        }
        if (maiorMatrizKcaj == 3) {
            resultadorMaiorNumeroPrimoKcaj = maiorNumeroPrimo(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizKcaj3, 0);
        }
        if (maiorMatrizKcaj == 4) {
            resultadorMaiorNumeroPrimoKcaj = maiorNumeroPrimo(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizKcaj4, 0);
        }
        if (maiorMatrizAnsa == 1) {
            resultadorMaiorNumeroPrimoAnsa = maiorNumeroPrimo(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizAnsa1, 0);
        }
        if (maiorMatrizAnsa == 2) {
            resultadorMaiorNumeroPrimoAnsa = maiorNumeroPrimo(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizAnsa2, 0);
        }
        if (maiorMatrizAnsa == 3) {
            resultadorMaiorNumeroPrimoAnsa = maiorNumeroPrimo(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizAnsa3, 0);
        }
        if (maiorMatrizAnsa == 4) {
            resultadorMaiorNumeroPrimoAnsa = maiorNumeroPrimo(tamanhoLinhaSubmatriz, tamanhoColunaSubmatriz, subMatrizAnsa4, 0);
        }

        if (resultadorMaiorNumeroPrimoKcaj > resultadorMaiorNumeroPrimoAnsa) {
            printf("Kcaj ganhou");
        }
        if (resultadorMaiorNumeroPrimoAnsa > resultadorMaiorNumeroPrimoKcaj) {
            printf("Ansa ganhou");
        }
        if (resultadorMaiorNumeroPrimoKcaj == resultadorMaiorNumeroPrimoAnsa) {
            printf("Empate");
        }

    }

    return 0;

}