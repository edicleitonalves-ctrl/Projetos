#include <stdio.h>

// --- Constantes Globais ---
#define TAM_TABULEIRO 10 
#define TAM_NAVIO 3      
#define TAM_HABILIDADE 5 // Matriz de habilidade de tamanho fixo 5x5
#define VAZIO 0          
#define OCUPADO 3        
#define AFETADO 5        // Valor para representar a área da habilidade

// --- Protótipos das Funções ---
void inicializar_tabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
void posicionar_navio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao);
int validar_posicionamento(const int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao);
void exibir_tabuleiro(const int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);

// Novas funções para o Nível Mestre
void aplicar_habilidade_cone(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int origemL, int origemC);
void aplicar_habilidade_cruz(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int origemL, int origemC);
void aplicar_habilidade_octaedro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int origemL, int origemC);

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    inicializar_tabuleiro(tabuleiro);
    
    printf("--- Batalha Naval: Nível Mestre ---\n\n");

    // 1. Posicionamento de Navios (Mantendo sua lógica anterior)
    posicionar_navio(tabuleiro, 1, 1, 'H'); // Navio Horizontal
    posicionar_navio(tabuleiro, 5, 2, 'V'); // Navio Vertical

    // 2. Aplicação das Habilidades Especiais
    // O ponto de origem será o topo do cone ou o centro das outras formas.
    
    printf("Aplicando Habilidade em Cone...\n");
    aplicar_habilidade_cone(tabuleiro, 0, 4);

    printf("Aplicando Habilidade em Cruz...\n");
    aplicar_habilidade_cruz(tabuleiro, 5, 5);

    printf("Aplicando Habilidade em Octaedro...\n");
    aplicar_habilidade_octaedro(tabuleiro, 8, 2);
    
    // Exibe o tabuleiro final com navios (3) e habilidades (5)
    exibir_tabuleiro(tabuleiro);

    return 0;
}

// --- Implementação das Habilidades ---

/**
 * Habilidade Cone:
 * A lógica usa loops aninhados para criar uma forma que expande a cada linha.
 */
void aplicar_habilidade_cone(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int origemL, int origemC) {
    // Matriz de habilidade 5x5 definida dinamicamente com condicionais
    for (int i = 0; i < 3; i++) { // O cone terá 3 linhas de altura
        for (int j = 0; j < 5; j++) {
            // Lógica para formar o desenho do cone:
            // Linha 0: apenas o centro | Linha 1: 3 colunas | Linha 2: 5 colunas
            if (j >= 2 - i && j <= 2 + i) {
                int l_tab = origemL + i;
                int c_tab = origemC + (j - 2);
                
                // Validação de limites do tabuleiro
                if (l_tab >= 0 && l_tab < TAM_TABULEIRO && c_tab >= 0 && c_tab < TAM_TABULEIRO) {
                    tabuleiro[l_tab][c_tab] = AFETADO;
                }
            }
        }
    }
}

/**
 * Habilidade Cruz:
 * Afeta a linha central e a coluna central da área de efeito.
 */
void aplicar_habilidade_cruz(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int origemL, int origemC) {
    for (int i = 0; i < 3; i++) { // Tamanho da cruz
        for (int j = 0; j < 5; j++) {
            // Lógica: Se estiver na linha central (1) ou coluna central (2)
            if (i == 1 || j == 2) {
                int l_tab = origemL + (i - 1);
                int c_tab = origemC + (j - 2);
                
                if (l_tab >= 0 && l_tab < TAM_TABULEIRO && c_tab >= 0 && c_tab < TAM_TABULEIRO) {
                    tabuleiro[l_tab][c_tab] = AFETADO;
                }
            }
        }
    }
}

/**
 * Habilidade Octaedro:
 * Forma de losango. A distância da soma das coordenadas define o preenchimento.
 */
void aplicar_habilidade_octaedro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int origemL, int origemC) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Lógica para formato de losango 3x3
            // Apenas posições específicas formam o octaedro frontal
            if ((i == 1) || (j == 1)) {
                int l_tab = origemL + (i - 1);
                int c_tab = origemC + (j - 1);
                
                if (l_tab >= 0 && l_tab < TAM_TABULEIRO && c_tab >= 0 && c_tab < TAM_TABULEIRO) {
                    tabuleiro[l_tab][c_tab] = AFETADO;
                }
            }
        }
    }
}

// --- Funções Auxiliares (Baseadas no seu código original) ---

void inicializar_tabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = VAZIO;
        }
    }
}

void posicionar_navio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao) {
    if (!validar_posicionamento(tabuleiro, linha, coluna, orientacao)) return;
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha, c = coluna;
        if (orientacao == 'H') c += i;
        else if (orientacao == 'V') l += i;
        tabuleiro[l][c] = OCUPADO;
    }
}

int validar_posicionamento(const int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha, c = coluna;
        if (orientacao == 'H') c += i;
        else if (orientacao == 'V') l += i;
        if (l < 0 || l >= TAM_TABULEIRO || c < 0 || c >= TAM_TABULEIRO) return 0;
        if (tabuleiro[l][c] != VAZIO) return 0;
    }
    return 1;
}

void exibir_tabuleiro(const int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("    0 1 2 3 4 5 6 7 8 9\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d|", i);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}