#include <stdio.h>

// --- Constantes Globais (#define) ---
// Usamos #define para garantir que o compilador aceite os valores
// no dimensionamento dos arrays (exigencia de 'constante de tempo de compilacao').
#define TAM_TABULEIRO 10 // Tamanho do Tabuleiro (10x10)
#define TAM_NAVIO 3      // Navios de tamanho 3

// Representacoes na Matriz Interna (1 e 0 para simplicidade de validacao)
#define VAZIO 0    // 0 representa a AGUA (posicao livre)
#define OCUPADO 1  // 1 representa a PARTE DO NAVIO (posicao ocupada)
#define VALOR_EXIBICAO_NAVIO 3 // Valor de exibicao exigido (3s representando navios)

// --- Protótipos das Funções ---
void inicializar_tabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);
int validar_posicionamento(const int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao);
void posicionar_navio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao);
void exibir_tabuleiro(const int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]);

// ----------------------------------------
// --- Função Principal (main) ---
// ----------------------------------------
int main() {
    // 1. Matriz (Array Bidimensional) para representar o tabuleiro 10x10
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    // Coordenadas Iniciais dos Navios (Indices 0-9) - Definidas diretamente no codigo
    
    // Navio 1: Horizontal, INDICE Linha 2, INDICE Coluna 3
    int n1_linha = 2; 
    int n1_coluna = 3; 
    char n1_orientacao = 'H';
    
    // Navio 2: Vertical, INDICE Linha 5, INDICE Coluna 6
    int n2_linha = 5; 
    int n2_coluna = 6; 
    char n2_orientacao = 'V';

    // Inicializa a matriz com zeros (VAZIO)
    inicializar_tabuleiro(tabuleiro);
    
    printf("--- Posicionamento de Navios em Matriz ---\n\n");
    
    // Tenta posicionar o Navio 1
    if (validar_posicionamento(tabuleiro, n1_linha, n1_coluna, n1_orientacao) == 1) {
        posicionar_navio(tabuleiro, n1_linha, n1_coluna, n1_orientacao);
        printf("Navio Horizontal OK: Linha %d, Coluna %c.\n", n1_linha + 1, 'A' + n1_coluna);
    } else {
        printf("ERRO: Navio Horizontal nao cabe ou sobrepoe.\n");
    }

    // Tenta posicionar o Navio 2
    if (validar_posicionamento(tabuleiro, n2_linha, n2_coluna, n2_orientacao) == 1) {
        posicionar_navio(tabuleiro, n2_linha, n2_coluna, n2_orientacao);
        printf("Navio Vertical OK: Linha %d, Coluna %c.\n", n2_linha + 1, 'A' + n2_coluna);
    } else {
        printf("ERRO: Navio Vertical nao cabe ou sobrepoe.\n");
    }
    
    // Exibe o tabuleiro final
    printf("\n--- Tabuleiro Final (0s para Agua, 3s para Navio) ---\n");
    exibir_tabuleiro(tabuleiro);

    return 0;
}

// ----------------------------------------
// --- Implementação das Funções (Foco em FOR) ---
// ----------------------------------------

/**
 * @brief Inicializa a matriz com o valor VAZIO (0).
 */
void inicializar_tabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    int i, j;
    
    // Loops FOR aninhados: Percorre cada celula da Matriz
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            // Acessa a posicao [i][j] e define como VAZIO (0)
            tabuleiro[i][j] = VAZIO; 
        }
    }
}

/**
 * @brief Valida limites e sobreposição.
 * @return Retorna 1 se valido, ou 0 se houver falha.
 */
int validar_posicionamento(const int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao) {
    int i;
    int l_atual, c_atual; 

    // 1. Validacao de Limites da Matriz (indices 0-9)
    if (linha < 0 || linha >= TAM_TABULEIRO || coluna < 0 || coluna >= TAM_TABULEIRO) {
        return 0;
    }
    
    // Checa se o navio CABE (tamanho 3)
    if (orientacao == 'H' && (coluna + TAM_NAVIO) > TAM_TABULEIRO) {
        return 0;
    } else if (orientacao == 'V' && (linha + TAM_NAVIO) > TAM_TABULEIRO) {
        return 0;
    }

    // 2. Validacao de Sobreposição
    // Loop FOR: Percorre as 3 posicoes que o navio precisa
    for (i = 0; i < TAM_NAVIO; i++) {
        if (orientacao == 'H') {
            l_atual = linha;
            c_atual = coluna + i;
        } else { // Orientacao == 'V'
            l_atual = linha + i;
            c_atual = coluna;
        }

        // Verifica se a posicao ja esta OCUPADA (valor 1)
        if (tabuleiro[l_atual][c_atual] != VAZIO) {
            return 0; // Sobreposicao!
        }
    }

    return 1; // Posicionamento valido
}

/**
 * @brief Posiciona o navio na matriz, marcando com OCUPADO (1).
 */
void posicionar_navio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao) {
    int i;
    int l_atual, c_atual;

    // Loop FOR: Marca as 3 posicoes do navio na Matriz
    for (i = 0; i < TAM_NAVIO; i++) {
        if (orientacao == 'H') {
            l_atual = linha;
            c_atual = coluna + i;
        } else { // Orientacao == 'V'
            l_atual = linha + i;
            c_atual = coluna;
        }
        
        // Atribui o valor 1 (OCUPADO)
        tabuleiro[l_atual][c_atual] = OCUPADO; 
    }
}

/**
 * @brief Exibe o estado da matriz no console.
 * Exibe 0s para agua e 3s para navios. Linhas 1-10, Colunas A-J.
 */
void exibir_tabuleiro(const int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    int i, j;
    
    // 1. Imprime o Cabecalho das COLUNAS (A B C D...)
    printf("   "); 
    for (j = 0; j < TAM_TABULEIRO; j++) {
        printf(" %c", 'A' + j); 
    }
    printf("\n");
    printf("  +-----------------------\n"); 
    
    // 2. Loops FOR aninhados para exibir a Matriz
    for (i = 0; i < TAM_TABULEIRO; i++) {
        // IMPRIME LINHAS 1-10: Adiciona 1 ao indice
        printf("%2d|", i + 1); 
        
        for (j = 0; j < TAM_TABULEIRO; j++) {
            // Verifica o valor na Matriz [i][j]
            if (tabuleiro[i][j] == VAZIO) {
                printf(" %d", VAZIO); // Exibe 0 (Agua)
            } else {
                // Se OCUPADO (valor 1), exibe 3 conforme o requisito
                printf(" %d", VALOR_EXIBICAO_NAVIO); // Exibe 3 (Navio)
            }
        }
        printf(" \n");
    }
    printf("---------------------------\n"); 
}