#include <stdio.h>
#include <stdlib.h> // Necessário para a função system("clear") ou system("cls")
#include<time.h>


int main() {
    // Variável para armazenar a escolha do jogador no menu
    int escolha;
    
    // --- VARIÁVEIS DO CARTÃO 1: Recife/Pernambuco ---
    char p_estado[] = "Pernambuco";
    char p_codigo[20] = "A01";
    char p_capital[50] = "Recife";
    // Usando int (padrão dos níveis Novato/Aventureiro)
    int p_populacao = 1488920; 
    float p_area = 218.8;       // km²      
    float p_pib = 54.97;        // PIB em Bilhões R$      
    int p_turismo = 20;
    
    // 1. CÁLCULO DA DENSIDADE POPULACIONAL (população / área)
    float p_densidade_pop = (float)p_populacao / p_area;
    
    // 2. CÁLCULO DO PIB PER CAPITA ((PIB em Bilhões * 1.000.000.000) / população)
    double p_pib_reais = p_pib * 1000000000.0;
    float p_pib_per_capita = p_pib_reais / (double)p_populacao;

    // CÁLCULO DO SUPER PODER (Mantido, mas não usado no menu do Aventureiro)
    float p_super_poder = (float)p_populacao + (float)p_area + (float)p_pib + (float)p_turismo + (float)p_pib_per_capita + (1.0 / (float)p_densidade_pop);


    // --- VARIÁVEIS DO CARTÃO 2: Maceió/Alagoas ---
    char a_estado[] = "Alagoas";
    char a_codigo[20] = "B01";
    char a_capital[50] = "Maceió";
    // Usando int (padrão dos níveis Novato/Aventureiro)
    int a_populacao = 3127511;
    float a_area = 27843.2;         // km²
    float a_pib = 63.202;           // PIB em Bilhões R$
    int a_turismo = 9;
    
    // 1. CÁLCULO DA DENSIDADE POPULACIONAL (população / área)
    float a_densidade_pop = (float)a_populacao / a_area;
    
    // 2. CÁLCULO DO PIB PER CAPITA ((PIB em Bilhões * 1.000.000.000) / população)
    double a_pib_reais = a_pib * 1000000000.0;
    float a_pib_per_capita = a_pib_reais / (double)a_populacao;

    // CÁLCULO DO SUPER PODER
    float a_super_poder = (float)a_populacao + (float)a_area + (float)a_pib + (float)a_turismo + (float)a_pib_per_capita + (1.0 / (float)a_densidade_pop);
    
    
    // --- EXIBIÇÃO DOS CARTÕES (Introdução) ---
    printf("*** \nSuper Trunfo: Nível Aventureiro ***\n");
    printf("---------------------------\n");
    printf("Card 1: %s (%s) | Card 2: %s (%s)\n", p_capital, p_estado, a_capital, a_estado);
    printf("---------------------------\n");

    // --- NOVO NÍVEL AVENTUREIRO: 1. MENU INTERATIVO ---
    printf("\nEscolha o atributo para a batalha:\n");
    printf("1. População (Maior vence)\n");
    printf("2. Área (Maior vence)\n");
    printf("3. PIB (Maior vence)\n");
    printf("4. Pontos Turísticos (Maior vence)\n");
    printf("5. Densidade Demográfica (Menor vence)\n");
    printf("6. PIB per Capita (Maior vence)\n");
    printf("---------------------------\n");
    printf("Opção: ");
    
    if (scanf("%d", &escolha) != 1) {
        // Tratar entrada não numérica
        printf("\nOpção inválida. O programa será encerrado.\n");
        return 1;
    }

    // Limpa a tela antes de exibir o resultado (opcional, pode ser removido se não funcionar no seu terminal)
    // system("clear"); 

    // --- NOVO NÍVEL AVENTUREIRO: 2. COMPARAÇÃO DE ATRIBUTOS (Switch) ---
    switch (escolha) {
        case 1: // População (Maior vence)
            printf("\nComparação: População\n");
            printf("Card 1 (%s): %d habitantes\n", p_capital, p_populacao);
            printf("Card 2 (%s): %d habitantes\n", a_capital, a_populacao);
            // Lógica de comparação (Maior vence)
            if (p_populacao > a_populacao) {
                printf("Resultado: Card 1 (%s) venceu!\n", p_capital);
            } else if (a_populacao > p_populacao) {
                printf("Resultado: Card 2 (%s) venceu!\n", a_capital);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // Área (Maior vence)
            printf("\nComparação: Área\n");
            printf("Card 1 (%s): %.1f km²\n", p_capital, p_area);
            printf("Card 2 (%s): %.1f km²\n", a_capital, a_area);
            // Lógica de comparação (Maior vence)
            if (p_area > a_area) {
                printf("Resultado: Card 1 (%s) venceu!\n", p_capital);
            } else if (a_area > p_area) {
                printf("Resultado: Card 2 (%s) venceu!\n", a_capital);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // PIB (Maior vence)
            printf("\nComparação: PIB (Bilhões R$)\n");
            printf("Card 1 (%s): R$ %.2f\n", p_capital, p_pib);
            printf("Card 2 (%s): R$ %.2f\n", a_capital, a_pib);
            // Lógica de comparação (Maior vence)
            if (p_pib > a_pib) {
                printf("Resultado: Card 1 (%s) venceu!\n", p_capital);
            } else if (a_pib > p_pib) {
                printf("Resultado: Card 2 (%s) venceu!\n", a_capital);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Pontos Turísticos (Maior vence)
            printf("\nComparação: Pontos Turísticos\n");
            printf("Card 1 (%s): %d\n", p_capital, p_turismo);
            printf("Card 2 (%s): %d\n", a_capital, a_turismo);
            // Lógica de comparação (Maior vence)
            if (p_turismo > a_turismo) {
                printf("Resultado: Card 1 (%s) venceu!\n", p_capital);
            } else if (a_turismo > p_turismo) {
                printf("Resultado: Card 2 (%s) venceu!\n", a_capital);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Densidade Demográfica (Menor vence - REGRA INVERSA)
            printf("\nComparação: Densidade Demográfica\n");
            printf("Card 1 (%s): %.2f hab/km²\n", p_capital, p_densidade_pop);
            printf("Card 2 (%s): %.2f hab/km²\n", a_capital, a_densidade_pop);
            // Lógica de comparação (MENOR vence)
            if (p_densidade_pop < a_densidade_pop) {
                printf("Resultado: Card 1 (%s) venceu!\n", p_capital);
            } else if (a_densidade_pop < p_densidade_pop) {
                printf("Resultado: Card 2 (%s) venceu!\n", a_capital);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 6: // PIB per Capita (Maior vence)
            printf("\nComparação: PIB per Capita\n");
            printf("Card 1 (%s): %.2f reais\n", p_capital, p_pib_per_capita);
            printf("Card 2 (%s): %.2f reais\n", a_capital, a_pib_per_capita);
            // Lógica de comparação (Maior vence)
            if (p_pib_per_capita > a_pib_per_capita) {
                printf("Resultado: Card 1 (%s) venceu!\n", p_capital);
            } else if (a_pib_per_capita > p_pib_per_capita) {
                printf("Resultado: Card 2 (%s) venceu!\n", a_capital);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("\nErro: Opção %d inválida. Por favor, escolha um número de 1 a 6.\n", escolha);
            break;
    }

    printf("----------------------------\n");

    return 0;
}