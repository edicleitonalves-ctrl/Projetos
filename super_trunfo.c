#include <stdio.h>

int main() {

    // --- VARIÁVEIS DO CARTÃO 1: Recife/Pernambuco ---
    char p_estado[] = "Pernambuco";
    char p_codigo[20] = "A01";
    char p_capital[50] = "Recife";
    int p_populacao = 1488920; 
    float p_area = 218.8;       // km²      
    float p_pib = 54.97;        // PIB em Bilhões R$      
    int p_turismo = 20;
    
    // 1. CÁLCULO DA DENSIDADE POPULACIONAL (população / área)
    float p_densidade_pop = (float)p_populacao / p_area;
    
    // 2. CÁLCULO DO PIB PER CAPITA ((PIB em Bilhões * 1.000.000.000) / população)
    double p_pib_reais = p_pib * 1000000000.0;
    float p_pib_per_capita = p_pib_reais / (double)p_populacao;

    // CÁLCULO DO SUPER PODER
    float p_super_poder = (float)p_populacao + (float)p_area + (float)p_pib + (float)p_turismo + (float)p_pib_per_capita + (1.0 / (float)p_densidade_pop);


    // --- VARIÁVEIS DO CARTÃO 2: Maceió/Alagoas ---
    char a_estado[] = "Alagoas";
    char a_codigo[20] = "B01";
    char a_capital[50] = "Maceió";
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
    
    
    // --- EXIBIÇÃO DOS CARTÕES ---
    printf("*** Super Trunfo ***\n");

    // Card 1
    printf("--- Card 1 ---\n");
    printf("Código: %s\n", p_codigo);
    printf("Estado: %s\n", p_estado);
    printf("Capital: %s\n", p_capital);
    printf("População: %d habitantes\n", p_populacao);
    printf("Área: %.1f km²\n", p_area);
    printf("PIB: R$ %.2f (Bilhões)\n", p_pib);
    printf("Pontos Turísticos: %d\n", p_turismo);
    printf("Densidade Populacional: %.2f hab/km²\n", p_densidade_pop);
    printf("PIB per Capita: %.2f reais\n", p_pib_per_capita);
    printf("Super Poder: %.2f\n", p_super_poder);
    printf("---------------------------\n");

    // Card 2
    printf("--- Card 2 ---\n");
    printf("Código: %s\n", a_codigo);
    printf("Estado: %s\n", a_estado);
    printf("Capital: %s\n", a_capital);
    printf("População: %d habitantes\n", a_populacao);
    printf("Área: %.1f km²\n", a_area);
    printf("PIB: R$ %.2f (Bilhões)\n", a_pib);
    printf("Pontos Turísticos: %d\n", a_turismo);
    printf("Densidade Populacional: %.2f hab/km²\n", a_densidade_pop);
    printf("PIB per Capita: %.2f reais\n", a_pib_per_capita);
    printf("Super Poder: %.2f\n", a_super_poder);
    printf("---------------------------\n");


    // --- NOVO NÍVEL NOVATO: COMPARAR UM ATRIBUTO ESCOLHIDO ---
    
    // Escolha: POPULAÇÃO (Maior valor vence)
    
    //EXIBIR O RESULTADO DA COMPARAÇÃO (Formato do Requisito)
    printf("\nComparação de cartas (Atributo: População):\n");
    printf("\nCard 1 - %s (%s): %d habitantes\n", p_capital, p_estado, p_populacao);
    printf("Card 2 - %s (%s): %d habitantes\n", a_capital, a_estado, a_populacao);
    
    //DETERMINAR A CARTA VENCEDORA usando if/else
    // Regra da População: O MAIOR valor vence.
    if (p_populacao > a_populacao) {
        // Carta 1 vence, pois tem a maior população.
        printf("Resultado: Card 1 (%s) venceu!\n", p_capital);
    } else if (a_populacao > p_populacao) {
        // Carta 2 vence, pois tem a maior população.
        printf("Resultado: Card 2 (%s) venceu!\n", a_capital);
    } else {
        // Empate
        printf("Resultado: Empate!\n");
    }

    printf("----------------------------\n");

    return 0;
}