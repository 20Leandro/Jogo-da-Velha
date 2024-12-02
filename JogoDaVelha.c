#include <stdio.h>

typedef struct {
    char tabuleiro[3][3]; 
    int jogadorAtual;
    char simboloAtual;
} JogoDaVelha;

main() {
    JogoDaVelha jogo;
    int linha, coluna, i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            jogo.tabuleiro[i][j] = ' ';  
        }
    }

    jogo.jogadorAtual = 1;
    jogo.simboloAtual = 'X';

    int vencedor = 0;
    int jogadas = 0;

    while (!vencedor) {

        printf("\n");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf(" %c ", jogo.tabuleiro[i][j]);
                if (j < 2) printf("|");
            }
            printf("\n");
            if (i < 2) printf("---|---|---\n");
        }

        printf("\nJogador %d (%c), faça sua jogada.\n", jogo.jogadorAtual, jogo.simboloAtual);
        printf("Escolha a linha e a coluna (0 a 2): ");
        scanf("%d %d", &linha, &coluna);

        if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && jogo.tabuleiro[linha][coluna] == ' ') {
            jogo.tabuleiro[linha][coluna] = jogo.simboloAtual;
            jogadas++;
        } else {
            printf("Jogada inválida! Tente novamente.\n");
            continue; 
        }

        for (i = 0; i < 3; i++) {
            if (jogo.tabuleiro[i][0] == jogo.tabuleiro[i][1] && 
                jogo.tabuleiro[i][1] == jogo.tabuleiro[i][2] && 
                jogo.tabuleiro[i][0] != ' ') {
                vencedor = 1;
                break;
            }
        }

        for (i = 0; i < 3; i++) {
            if (jogo.tabuleiro[0][i] == jogo.tabuleiro[1][i] &&
                jogo.tabuleiro[1][i] == jogo.tabuleiro[2][i] && 
                jogo.tabuleiro[0][i] != ' ') {
                vencedor = 1;
                break;
            }
        }

        if (jogo.tabuleiro[0][0] == jogo.tabuleiro[1][1] && 
            jogo.tabuleiro[1][1] == jogo.tabuleiro[2][2] && 
            jogo.tabuleiro[0][0] != ' ') {
            vencedor = 1;
        }
        if (jogo.tabuleiro[0][2] == jogo.tabuleiro[1][1] && 
            jogo.tabuleiro[1][1] == jogo.tabuleiro[2][0] && 
            jogo.tabuleiro[0][2] != ' ') {
            vencedor = 1;
        }

        if (jogadas == 9 && !vencedor) {
            printf("\n");
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    printf(" %c ", jogo.tabuleiro[i][j]);
                    if (j < 2) printf("|");
                }
                printf("\n");
                if (i < 2) printf("---|---|---\n");
            }
            printf("\nO jogo terminou em empate!\n");
            break;
        }

        if (vencedor) {
            printf("\n");
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    printf(" %c ", jogo.tabuleiro[i][j]);
                    if (j < 2) printf("|");
                }
                printf("\n");
                if (i < 2) printf("---|---|---\n");
            }
            printf("\nJogador %d (%c) venceu!\n", jogo.jogadorAtual, jogo.simboloAtual);
        } else {
            if (jogo.jogadorAtual == 1) {
                jogo.jogadorAtual = 2;
                jogo.simboloAtual = 'O';
            } else {
                jogo.jogadorAtual = 1;
                jogo.simboloAtual = 'X';
            }
        }
    }
}