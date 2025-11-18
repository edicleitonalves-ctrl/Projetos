#include <stdio.h>
#include <stdlib.h> // Para system("clear") ou system("cls")

// Variável global para armazenar a primeira escolha (usada no segundo menu)
int escolha1 = 0; 
int escolha2 = 0;
// Variáveis para armazenar o resultado da comparação (1 para Card 1 vence, 0 para Card 2 vence)
int resultado1, resultado2; 
// Variáveis para somar os pontos (um ponto por vitória em cada atributo)
int soma_card1 = 0;
int soma_card2 = 0;

// --- FUNÇÃO PARA OBTER O NOME DO ATRIBUTO ---
const char* get_atributo_nome(int escolha) {
    switch (escolha) {
        case 1: return "População (Maior vence)";
        case 2: return "Área (Maior vence)";
        case 3: return "PIB (Maior vence)";
        case 4: return "Pontos Turísticos (Maior vence)";
        case 5: return "Densidade Demográfica (Menor vence)";
        case 6: return "PIB per Capita (Maior vence)";
        default: return "Inválido";
    }
}

// --- FUNÇÃO PARA OBTER O VALOR DO ATRIBUTO (Ajudando na Estrutura) ---
// Retorna o valor do Card 1 ou Card 2 para a comparação
double get_atributo_valor(int escolha, int card_num, 
                          unsigned long int p_populacao, float p_area, float p_pib, int p_turismo, float p_densidade_pop, float p_pib_per_capita, 
                          unsigned long int a_populacao, float a_area, float a_pib, int a_turismo, float a_densidade_pop, float a_pib_per_capita) {
    
    // Se for o Card 1 (Recife/Pernambuco)
    if (card_num == 1) {
        switch (escolha) {
            case 1: return (double)p_populacao;
            case 2: return (double)p_area;
            case 3: return (double)p_pib;
            case 4: return (double)p_turismo;
            case 5: return (double)p_densidade_pop;
            case 6: return (double)p_pib_per_capita;
        }
    } 
    // Se for o Card 2 (Maceió/Alagoas)
    else if (card_num == 2) {
        switch (escolha) {
            case 1: return (double)a_populacao;
            case 2: return (double)a_area;
            case 3: return (double)a_pib;
            case 4: return (double)a_turismo;
            case 5: return (double)a_densidade_pop;
            case 6: return (double)a_pib_per_capita;
        }
    }
    return 0.0;
}

int main() {
    
    // --- VARIÁVEIS DO CARTÃO 1: Recife/Pernambuco ---
    char p_estado[] = "Pernambuco";
    char p_codigo[20] = "A01";
    char p_capital[50] = "Recife";
    // População como unsigned long int (Requisito Mestre)
    unsigned long int p_populacao = 1488920; 
    float p_area = 218.8;       // km²      
    float p_pib = 54.97;        // PIB em Bilhões R$      
    int p_turismo = 20;
    
    // Cálculos
    float p_densidade_pop = (float)p_populacao / p_area;
    double p_pib_reais = p_pib * 1000000000.0;
    float p_pib_per_capita = p_pib_reais / (double)p_populacao;
    double p_super_poder = (double)p_populacao + (double)p_area + (double)p_pib + (double)p_turismo + (double)p_pib_per_capita + (1.0 / (double)p_densidade_pop);


    // --- VARIÁVEIS DO CARTÃO 2: Maceió/Alagoas ---
    char a_estado[] = "Alagoas";
    char a_codigo[20] = "B01";
    char a_capital[50] = "Maceió";
    // População como unsigned long int (Requisito Mestre)
    unsigned long int a_populacao = 3127511;
    float a_area = 27843.2;         // km²
    float a_pib = 63.202;           // PIB em Bilhões R$
    int a_turismo = 9;
    
    // Cálculos
    float a_densidade_pop = (float)a_populacao / a_area;
    double a_pib_reais = a_pib * 1000000000.0;
    float a_pib_per_capita = a_pib_reais / (double)a_populacao;
    double a_super_poder = (double)a_populacao + (double)a_area + (double)a_pib + (double)a_turismo + (double)a_pib_per_capita + (1.0 / (double)a_densidade_pop);
    
    // --- INTRODUÇÃO E EXIBIÇÃO COMPLETA DAS CARTAS ---
    printf("*** Super Trunfo ***\n");
    printf("--------------------------------------------------\n");

    // Card 1
    printf("--- Card 1: %s (%s) ---\n", p_capital, p_estado);
    printf("Código: %s\n", p_codigo);
    printf("População: %lu habitantes\n", p_populacao); 
    printf("Área: %.1f km²\n", p_area);
    printf("PIB: R$ %.2f (Bilhões)\n", p_pib);
    printf("Pontos Turísticos: %d\n", p_turismo);
    printf("Densidade Populacional: %.2f hab/km²\n", p_densidade_pop);
    printf("PIB per Capita: %.2f reais\n", p_pib_per_capita);
    printf("Super Poder: %.2f\n", p_super_poder);
    printf("---------------------------\n");

    // Card 2
    printf("--- Card 2: %s (%s) ---\n", a_capital, a_estado);
    printf("Código: %s\n", a_codigo);
    printf("População: %lu habitantes\n", a_populacao); 
    printf("Área: %.1f km²\n", a_area);
    printf("PIB: R$ %.2f (Bilhões)\n", a_pib);
    printf("Pontos Turísticos: %d\n", a_turismo);
    printf("Densidade Populacional: %.2f hab/km²\n", a_densidade_pop);
    printf("PIB per Capita: %.2f reais\n", a_pib_per_capita);
    printf("Super Poder: %.2f\n", a_super_poder);
    printf("--------------------------------------------------\n");
    
    // --- INTRODUÇÃO ---
    printf("*** Super Trunfo: Nível Mestre (Decisões Encadeadas) ***\n");
    printf("---------------------------\n");
    printf("Card 1: %s (%s) | Card 2: %s (%s)\n", p_capital, p_estado, a_capital, a_estado);
    printf("---------------------------\n");

    
    // --- PRIMEIRA ESCOLHA (1. População a 6. PIB per Capita) ---
    printf("\nEscolha o PRIMEIRO atributo para a batalha:\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Demográfica\n6. PIB per Capita\n");
    printf("---------------------------\n");
    printf("Opção 1: ");
    
    // Entrada de dado (Sem tratamento robusto de erro, como pedido nas simplificações)
    scanf("%d", &escolha1);

    // Validação da Escolha 1 (Simples)
    if (escolha1 < 1 || escolha1 > 6) {
        printf("\nErro: Primeira opção (%d) inválida. O programa será encerrado.\n", escolha1);
        return 1;
    }

    // --- SEGUNDA ESCOLHA (Usando if/else if/else para garantir que seja diferente) ---
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    
    // Menu Dinâmico Simples via if/else
    if (escolha1 != 1) printf("1. População\n");
    if (escolha1 != 2) printf("2. Área\n");
    if (escolha1 != 3) printf("3. PIB\n");
    if (escolha1 != 4) printf("4. Pontos Turísticos\n");
    if (escolha1 != 5) printf("5. Densidade Demográfica\n");
    if (escolha1 != 6) printf("6. PIB per Capita\n");
    printf("---------------------------\n");
    printf("Opção 2: ");
    
    // Entrada de dado
    scanf("%d", &escolha2);

    // Validação da Escolha 2 (Decisão aninhada/encadeada)
    if (escolha2 < 1 || escolha2 > 6 || escolha2 == escolha1) {
        printf("\nErro: Segunda opção (%d) inválida ou igual à primeira. O programa será encerrado.\n", escolha2);
        return 1;
    }
    
    // --- 2. COMPARAÇÃO DOS ATRIBUTOS (Lógica de Decisão Encadeada) ---
    // Atributo 1
    double valor_p1 = get_atributo_valor(escolha1, 1, p_populacao, p_area, p_pib, p_turismo, p_densidade_pop, p_pib_per_capita, a_populacao, a_area, a_pib, a_turismo, a_densidade_pop, a_pib_per_capita);
    double valor_a1 = get_atributo_valor(escolha1, 2, p_populacao, p_area, p_pib, p_turismo, p_densidade_pop, p_pib_per_capita, a_populacao, a_area, a_pib, a_turismo, a_densidade_pop, a_pib_per_capita);
    
    // OPERADOR TERNÁRIO: (Condição de vitória do Card 1) ? 1 : 0
    // Condição para Densidade Demográfica (5): Card 1 vence se for MENOR (valor_p1 < valor_a1)
    // Condição para os demais: Card 1 vence se for MAIOR (valor_p1 > valor_a1)
    int regra1_card1_vence = (escolha1 == 5) ? (valor_p1 < valor_a1) : (valor_p1 > valor_a1);
    
    resultado1 = regra1_card1_vence ? 1 : 0;
    
    // Atribuição dos pontos do Atributo 1
    soma_card1 += resultado1;
    soma_card2 += (resultado1 == 0); // Soma 1 ponto para Card 2 se Card 1 não venceu

    // Atributo 2
    double valor_p2 = get_atributo_valor(escolha2, 1, p_populacao, p_area, p_pib, p_turismo, p_densidade_pop, p_pib_per_capita, a_populacao, a_area, a_pib, a_turismo, a_densidade_pop, a_pib_per_capita);
    double valor_a2 = get_atributo_valor(escolha2, 2, p_populacao, p_area, p_pib, p_turismo, p_densidade_pop, p_pib_per_capita, a_populacao, a_area, a_pib, a_turismo, a_densidade_pop, a_pib_per_capita);
    
    // OPERADOR TERNÁRIO: (Condição de vitória do Card 1) ? 1 : 0
    // Condição para Densidade Demográfica (5): Card 1 vence se for MENOR (valor_p2 < valor_a2)
    // Condição para os demais: Card 1 vence se for MAIOR (valor_p2 > valor_a2)
    int regra2_card1_vence = (escolha2 == 5) ? (valor_p2 < valor_a2) : (valor_p2 > valor_a2);
    
    resultado2 = regra2_card1_vence ? 1 : 0;
    
    // Atribuição dos pontos do Atributo 2
    soma_card1 += resultado2;
    soma_card2 += (resultado2 == 0); // Soma 1 ponto para Card 2 se Card 1 não venceu
    
    
    // --- 3. EXIBIÇÃO DE RESULTADOS E SOMA FINAL (Decisão Encadeada) ---
    printf("\n\n--- DETALHES DA BATALHA ---\n");
    
    // Exibição do Atributo 1
    printf("\n[ATRIBUTO 1: %s]\n", get_atributo_nome(escolha1));
    printf("Card 1 (%s): %.2f | Card 2 (%s): %.2f\n", p_capital, valor_p1, a_capital, valor_a1);
    printf("Vencedor do Atributo: Card %s (Ponto: %d)\n", resultado1 == 1 ? "1" : "2", resultado1 == 1 ? 1 : 1); // 1 ponto para o vencedor

    // Exibição do Atributo 2
    printf("\n[ATRIBUTO 2: %s]\n", get_atributo_nome(escolha2));
    printf("Card 1 (%s): %.2f | Card 2 (%s): %.2f\n", p_capital, valor_p2, a_capital, valor_a2);
    printf("Vencedor do Atributo: Card %s (Ponto: %d)\n", resultado2 == 1 ? "1" : "2", resultado2 == 1 ? 1 : 1); // 1 ponto para o vencedor

    // Resultado Final (Soma)
    printf("\n--- RESULTADO FINAL POR SOMA ---\n");
    printf("Total de Pontos Card 1 (%s): %d\n", p_capital, soma_card1);
    printf("Total de Pontos Card 2 (%s): %d\n", a_capital, soma_card2);

    // Decisão Final (Maior soma vence)
    if (soma_card1 > soma_card2) {
        printf("Vencedor da Rodada: CARD 1 (%s) VENCEU!\n", p_capital);
    } else if (soma_card2 > soma_card1) {
        printf("Vencedor da Rodada: CARD 2 (%s) VENCEU!\n", a_capital);
    } else {
        // Tratamento de Empate
        printf("Vencedor da Rodada: EMPATE!\n");
    }

    printf("----------------------------\n");

    return 0;
}