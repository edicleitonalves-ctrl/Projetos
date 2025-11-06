#include <stdio.h>

int main() {
    // Variáveis do Cartão "Super Trunfo" - Recife/Pernambuco
    char p_estado[] = "Pernambuco";
    char p_codigo[20] = "A01";
    char p_capital[50] = "Recife";
    int p_populacao = 1488920; 
    float p_area = 218.8;        // km²      
    float p_pib = 54.97;          // PIB em Bilhões R$       
    int p_turismo = 20;
    // 1. CÁLCULO DA DENSIDADE POPULACIONAL (população / área)
    // O resultado deve ser float para precisão.
    float p_densidade_pop = (float)p_populacao / p_area;
    // 2. CÁLCULO DO PIB PER CAPITA ((PIB em Bilhões * 1.000.000.000) / população)
    float p_pib_reais = p_pib * 1000000000.0;
    float p_pib_per_capita = p_pib_reais / (float)p_populacao;

    // Variáveis do Cartão "Super Trunfo" - Maceió/Alagoas
    char a_estado[] = "Alagoas";
    char a_codigo[20] = "B01";
    char a_capital[50] = "Maceió";
    int a_populacao = 3127511;
    float a_area = 27843.2;        // km²
    float a_pib = 63.202;          // PIB em Bilhões R$
    int a_turismo = 9;
    // 1. CÁLCULO DA DENSIDADE POPULACIONAL (população / área)
    float a_densidade_pop = (float)a_populacao / a_area;
    // 2. CÁLCULO DO PIB PER CAPITA ((PIB em Bilhões * 1.000.000.000) / população)
    float a_pib_reais = a_pib * 1000000000.0;
    float a_pib_per_capita = a_pib_reais / (float)a_populacao;

    //título do jogo ( Super Trunfo)
    printf("*** Super Trunfo ***\n");
    // Imprimindo o valor da string "Pernambuco"
    printf("--- Card 1 ---\n");
    printf("Código: %s\n", p_codigo);
    printf("Estado: %s\n", p_estado);
    printf("Capital: %s\n", p_capital);
    printf("População: %d habitantes\n", p_populacao);
    printf("Área: %.1f km²\n", p_area); // Use %.1f para formatar float com 1 casa decimal
    printf("PIB: R$ %.2f  (Bilhões)\n", p_pib); // Use %.2f para formatar float com 2 casas decimais
    printf("Pontos Turísticos: %d\n", p_turismo);
    // Novos atributos - FORMATADO COM DUAS CASAS DECIMAIS (%.2f)
    printf("Densidade Populacional: %.2f hab/km²\n", p_densidade_pop);
    printf("PIB per Capita: %.2f reais\n", p_pib_per_capita);
    printf("---------------------------\n");

    // Imprimindo o valor da string "Alagoas"
    printf("--- Card 2 ---\n");
    printf("Código: %s\n", a_codigo);
    printf("Estado: %s\n", a_estado);
    printf("Capital: %s\n", a_capital);
    printf("População: %d habitantes\n", a_populacao);
    printf("Área: %.1f km²\n", a_area); // Use %.1f para formatar float com 1 casa decimal
    printf("PIB: R$ %.2f  (Bilhões)\n", a_pib); // Use %.2f para formatar float com 2 casas decimais
    printf("Pontos Turísticos: %d\n", a_turismo);
    // Novos atributos - FORMATADO COM DUAS CASAS DECIMAIS (%.2f)
    printf("Densidade Populacional: %.2f hab/km²\n", a_densidade_pop);
    printf("PIB per Capita: %.2f reais\n", a_pib_per_capita);
    printf("---------------------------\n");


    return 0;
}