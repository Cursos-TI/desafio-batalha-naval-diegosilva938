#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

void inicializaTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

void posicionaNavios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Exemplo de navio horizontal
    for (int i = 0; i < 3; i++) tabuleiro[1][2 + i] = NAVIO;

    // Exemplo de navio vertical
    for (int i = 0; i < 3; i++) tabuleiro[4 + i][6] = NAVIO;

    // Diagonal principal
    for (int i = 0; i < 3; i++) tabuleiro[0 + i][0 + i] = NAVIO;

    // Diagonal secundária
    for (int i = 0; i < 3; i++) tabuleiro[0 + i][9 - i] = NAVIO;
}

void aplicaHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origemLinha, int origemColuna) {
    int offset = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTabuleiro = origemLinha - offset + i;
            int colunaTabuleiro = origemColuna - offset + j;

            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO &&
                colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO &&
                habilidade[i][j] == 1 &&
                tabuleiro[linhaTabuleiro][colunaTabuleiro] != NAVIO) {
                tabuleiro[linhaTabuleiro][colunaTabuleiro] = HABILIDADE;
            }
        }
    }
}

void geraCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int meio = TAMANHO_HABILIDADE / 2;
            matriz[i][j] = (j >= meio - i && j <= meio + i) ? 1 : 0;
        }
    }
}

void geraCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int meio = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            matriz[i][j] = (i == meio || j == meio) ? 1 : 0;
        }
    }
}

void geraOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int meio = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            matriz[i][j] = (abs(i - meio) + abs(j - meio) <= meio) ? 1 : 0;
        }
    }
}

void exibeTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nLegenda: 0 = água, 3 = navio, 5 = habilidade\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    inicializaTabuleiro(tabuleiro);
    posicionaNavios(tabuleiro);

    geraCone(cone);
    geraCruz(cruz);
    geraOctaedro(octaedro);

    // Aplica habilidades
    aplicaHabilidade(tabuleiro, cone, 2, 2);       // Cone com origem em (2,2)
    aplicaHabilidade(tabuleiro, cruz, 5, 5);       // Cruz com origem em (5,5)
    aplicaHabilidade(tabuleiro, octaedro, 7, 7);   // Octaedro com origem em (7,7)

    exibeTabuleiro(tabuleiro);

    return 0;
}
