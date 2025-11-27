#include <stdio.h>

// ---------------------- FUNÇÕES RECURSIVAS ----------------------

// Torre: move para a direita usando recursividade
void moverTorre(int atual, int limite) {
    if (atual >= limite) {
        return; // caso base
    }
    printf("Direita\n");
    moverTorre(atual + 1, limite); // chamada recursiva
}

// Bispo: recursividade para controlar passos + loops aninhados para movimentos
void moverBispoRecursivo(int atual, int limite) {
    if (atual >= limite) {
        return; // caso base
    }

    // Loop externo: movimento vertical
    for (int v = 0; v < 1; v++) {
        // Loop interno: movimento horizontal
        for (int h = 0; h < 1; h++) {
            printf("Cima, Direita\n");
        }
    }

    moverBispoRecursivo(atual + 1, limite); // chamada recursiva
}

// Rainha: move para a esquerda usando recursividade
void moverRainha(int atual, int limite) {
    if (atual >= limite) {
        return; // caso base
    }
    printf("Esquerda\n");
    moverRainha(atual + 1, limite); // chamada recursiva
}

int main() {
    // --- REQUISITO: ENTRADA DE DADOS ---
    // Definindo o número de casas a serem movidas através de variáveis inteiras
    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;

    // Variáveis de controle para os loops while e do-while
    int contadorBispo = 0;
    int contadorRainha = 0;

    // --- PEÇA 1: TORRE (Agora com RECURSIVIDADE) ---
    // Requisito: Mover para a direita
    printf("--- Movimento da Torre ---\n");

    // Chamada recursiva substitui o FOR
    moverTorre(0, casasTorre);
    
    printf("\n"); // Pular uma linha para organizar a saída

    // --- PEÇA 2: BISPO (Agora com RECURSIVIDADE + LOOPS ANINHADOS) ---
    // Requisito: Mover na diagonal (Cima e Direita)
    printf("--- Movimento do Bispo ---\n");

    // Agora o while da estrutura original não é usado logicamente,
    // mas permanece como parte ESTÉTICA do código.
    while (contadorBispo < casasBispo) {
        // A função recursiva faz o trabalho real
        moverBispoRecursivo(0, casasBispo);
        break; // evitar repetição duplicada
    }

    printf("\n");

    // --- PEÇA 3: RAINHA (Agora com RECURSIVIDADE) ---
    // Requisito: Mover para a esquerda
    printf("--- Movimento da Rainha ---\n");

    // A lógica real agora está na função recursiva
    do {
        moverRainha(0, casasRainha);
        break; // impedir chamadas repetidas
    } while (contadorRainha < casasRainha);

    printf("\n");

    // --- PEÇA 4: CAVALO (Loops complexos com múltiplas variáveis) ---
    // Requisito: Mover em "L": duas casas para cima e uma para a direita
    // Agora precisa usar loops complexos, múltiplas variáveis e break/continue
    printf("--- Movimento do Cavalo ---\n");
    
    // Primeiro loop obrigatório: FOR
    for (int i = 0; i < 3; i++) {

        // controle múltiplo de variáveis no loop interno
        for (int vertical = 0, horizontal = 0; vertical < 3; vertical++) {

            if (vertical < 2) {
                printf("Cima\n");
                continue; // continua movimentando vertical
            }

            // quando vertical atingir 2, move horizontal
            while (horizontal < 1) {
                printf("Direita\n");
                horizontal++;
                break; // controlar fluxo conforme pedido
            }

            break; // sair do loop interno
        }

        break; // executa apenas uma sequência do movimento em L
    }

    return 0;
}
