#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    char colunas[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int linhas[10] = {0,1,2,3,4,5,6,7,8,9};

    // Inicializa todo o tabuleiro com água (0)
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            tabuleiro[i][j] = 0;

    // Navio em cone (valor 3)
    tabuleiro[7][2] = 3; tabuleiro[8][1] = 3; tabuleiro[8][2] = 3;
    tabuleiro[8][3] = 3; tabuleiro[9][0] = 3; tabuleiro[9][1] = 3;
    tabuleiro[9][2] = 3; tabuleiro[9][3] = 3; tabuleiro[9][4] = 3;

    // Cruz (valor 2)
    tabuleiro[2][2] = 2; tabuleiro[1][2] = 2; tabuleiro[3][2] = 2;
    tabuleiro[2][1] = 2; tabuleiro[2][3] = 2; tabuleiro[2][0] = 2;
    tabuleiro[4][2] = 2; tabuleiro[0][2] = 2; tabuleiro[2][4] = 2;

    // Octaedro (valor 1)
    tabuleiro[5][7] = 1; tabuleiro[4][7] = 1; tabuleiro[6][7] = 1;
    tabuleiro[5][6] = 1; tabuleiro[5][8] = 1;

    // Matriz da habilidade (forma de cruz simples)
    int habilidade[3][3] = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0}
    };

    // Variáveis de linha e coluna da área a ser atingida
    int linhaOrigem = 5;
    int colunaOrigem = 5;

    // Aplica a habilidade no tabuleiro
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (habilidade[i][j] == 1) {
                int linha = linhaOrigem + (i - 1);
                int coluna = colunaOrigem + (j - 1);
                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
                    tabuleiro[linha][coluna] = 5;  // Marca área afetada
                }
            }
        }
    }

    // Exibe cabeçalho
    printf("    ");
    for (int i = 0; i < 10; i++) {
        printf(" %c ", colunas[i]);
    }
    printf("\n");

    // Exibe tabuleiro com números
    for (int i = 0; i < 10; i++) {
        printf("%2d  ", linhas[i]);
        for (int j = 0; j < 10; j++) {
            int valor = tabuleiro[i][j];
            if (valor == 1 || valor == 2)
                printf(" 3 "); // Para padronizar navio como 3
            else
                printf(" %d ", valor);
        }
        printf("\n");
    }

    return 0;
}
