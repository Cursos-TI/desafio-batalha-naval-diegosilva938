#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // ---------- Inicializa o tabuleiro com água ----------
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ---------- Posiciona navio horizontal ----------
    int linhaH = 1, colunaH = 2;
    if (colunaH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != AGUA)
                sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = NAVIO;
            }
        }
    }

    // ---------- Posiciona navio vertical ----------
    int linhaV = 4, colunaV = 6;
    if (linhaV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != AGUA)
                sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = NAVIO;
            }
        }
    }

    // ---------- Posiciona navio diagonal principal ----------
    int linhaD1 = 0, colunaD1 = 0;
    if (linhaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != AGUA)
                sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
            }
        }
    }

    // ---------- Posiciona navio diagonal secundária ----------
    int linhaD2 = 0, colunaD2 = 9;
    if (linhaD2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaD2 - TAMANHO_NAVIO + 1 >= 0) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != AGUA)
                sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
            }
        }
    }

    // ---------- Exibe o tabuleiro ----------
    printf("\nTabuleiro de Batalha Naval (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
