#include <stdio.h>

// --- Constantes Globais ---
#define TAM_TABULEIRO 10 
#define TAM_NAVIO 3      
#define VAZIO 0          
#define OCUPADO 3 // Alterado para 3 conforme requisito funcional

// --- Protótipos das Funções ---
void inicializar_tabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
int validar_posicionamento(const int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao);
void posicionar_navio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao);
void exibir_tabuleiro(const int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    // Inicializa a matriz com zeros
    inicializar_tabuleiro(tabuleiro);
    
    printf("--- Batalha Naval ---\n\n");

    // Definição dos 4 navios (2 H/V e 2 Diagonais)
    
    // Navio 1: Horizontal
    if (validar_posicionamento(tabuleiro, 1, 1, 'H')) {
        posicionar_navio(tabuleiro, 1, 1, 'H');
    }

    // Navio 2: Vertical
    if (validar_posicionamento(tabuleiro, 5, 2, 'V')) {
        posicionar_navio(tabuleiro, 5, 2, 'V');
    }

    // Navio 3: Diagonal Principal (Linha e Coluna aumentam)
    if (validar_posicionamento(tabuleiro, 2, 6, 'D')) {
        posicionar_navio(tabuleiro, 2, 6, 'D');
    }

    // Navio 4: Diagonal Secundaria (Linha aumenta, Coluna diminui)
    if (validar_posicionamento(tabuleiro, 7, 8, 'S')) {
        posicionar_navio(tabuleiro, 7, 8, 'S');
    }
    
    // Exibe o tabuleiro final
    exibir_tabuleiro(tabuleiro);

    return 0;
}

// --- Implementação das Funções ---

void inicializar_tabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = VAZIO;
        }
    }
}

/**
 * Valida se o navio cabe e se não há sobreposição.
 * 'H' = Horizontal, 'V' = Vertical, 'D' = Diagonal Principal, 'S' = Diagonal Secundária.
 */
int validar_posicionamento(const int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha, c = coluna;

        if (orientacao == 'H') c += i;
        else if (orientacao == 'V') l += i;
        else if (orientacao == 'D') { l += i; c += i; } // Diagonal Principal
        else if (orientacao == 'S') { l += i; c -= i; } // Diagonal Secundária

        // Verifica limites do tabuleiro
        if (l < 0 || l >= TAM_TABULEIRO || c < 0 || c >= TAM_TABULEIRO) return 0;

        // Verifica sobreposição
        if (tabuleiro[l][c] != VAZIO) return 0;
    }
    return 1;
}

void posicionar_navio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha, c = coluna;

        if (orientacao == 'H') c += i;
        else if (orientacao == 'V') l += i;
        else if (orientacao == 'D') { l += i; c += i; }
        else if (orientacao == 'S') { l += i; c -= i; }
        
        tabuleiro[l][c] = OCUPADO; // Define como 3
    }
}

void exibir_tabuleiro(const int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("    A B C D E F G H I J\n");
    printf("  +---------------------\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d|", i + 1);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}
