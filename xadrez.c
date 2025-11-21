#include <stdio.h>

int main() {
    // --- REQUISITO: ENTRADA DE DADOS ---
    // Definindo o número de casas a serem movidas através de variáveis inteiras
    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;

    // Variáveis de controle para os loops while e do-while
    int contadorBispo = 0;
    int contadorRainha = 0;

    // --- PEÇA 1: TORRE (Utilizando FOR) ---
    // Requisito: Mover para a direita
    printf("--- Movimento da Torre ---\n");
    
    // O 'for' é ideal quando sabemos exatamente quantas vezes queremos repetir
    for (int contadorTorre = 0; contadorTorre < casasTorre; contadorTorre++) {
        printf("Direita\n");
    }
    
    printf("\n"); // Pular uma linha para organizar a saída

    // --- PEÇA 2: BISPO (Utilizando WHILE) ---
    // Requisito: Mover na diagonal (Cima e Direita)
    printf("--- Movimento do Bispo ---\n");
    
    // O 'while' verifica a condição ANTES de executar o bloco
    while (contadorBispo < casasBispo) {
        // Imprimindo a combinação de direções para simular a diagonal
        printf("Cima, Direita\n");
        contadorBispo++; // Incrementamos o contador manualmente
    }
    
    printf("\n");

    // --- PEÇA 3: RAINHA (Utilizando DO-WHILE) ---
    // Requisito: Mover para a esquerda
    printf("--- Movimento da Rainha ---\n");
    
    // O 'do-while' executa o bloco pelo menos uma vez e verifica a condição DEPOIS
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha < casasRainha);

    printf("\n");

    // --- PEÇA 4: CAVALO (Usando LOOPS ANINHADOS) ---
    // Requisito: Mover em "L": duas casas para baixo e uma para a esquerda
    // É obrigatório usar pelo menos DOIS LOOPS ANINHADOS
    printf("--- Movimento do Cavalo ---\n");

    // Primeiro loop obrigatório: FOR
    for (int i = 0; i < 1; i++) {

        int passosVerticais = 0;

        // Segundo loop: WHILE (movimento vertical - duas casas para baixo)
        while (passosVerticais < 2) {
            printf("Baixo\n");
            passosVerticais++;
        }

        // Movimento horizontal – uma casa para a esquerda
        printf("Esquerda\n");
    }

    return 0;
}
