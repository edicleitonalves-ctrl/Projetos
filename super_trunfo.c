#include <stdio.h>

int main() {
    // Definindo variáveis para o resultado da comparação (1 para Card 1 vence, 0 para Card 2 vence)
    int comp_populacao, comp_area, comp_pib, comp_turismo, comp_densidade, comp_pib_per_capita, comp_super_poder;

    // Variáveis do Cartão "Super Trunfo" - Recife/Pernambuco
    char p_estado[] = "Pernambuco";
    char p_codigo[20] = "A01";
    char p_capital[50] = "Recife";
    unsigned long int p_populacao = 1488920;
    float p_area = 218.8;        // km²      
    float p_pib = 54.97;          // PIB em Bilhões R$       
    int p_turismo = 20;
    float p_densidade_pop = (float)p_populacao / p_area;
    float p_pib_reais = p_pib * 1000000000.0;
    float p_pib_per_capita = p_pib_reais / (float)p_populacao;
    // NOVO NÍVEL MESTRE: CÁLCULO DO SUPER PODER
    float p_super_poder = (float)p_populacao + (float)p_area + (float)p_pib + (float)p_turismo + (float)p_pib_per_capita + (1.0 / (float)p_densidade_pop);

    // Variáveis do Cartão "Super Trunfo" - Maceió/Alagoas
    char a_estado[] = "Alagoas";
    char a_codigo[20] = "B01";
    char a_capital[50] = "Maceió";
    unsigned long int a_populacao = 3127511;
    float a_area = 27843.2;        // km²
    float a_pib = 63.202;          // PIB em Bilhões R$
    int a_turismo = 9;
    float a_densidade_pop = (float)a_populacao / a_area;
    float a_pib_reais = a_pib * 1000000000.0;
    float a_pib_per_capita = a_pib_reais / (float)a_populacao;
    // NOVO NÍVEL MESTRE: CÁLCULO DO SUPER PODER
    float a_super_poder = (float)a_populacao + (float)a_area + (float)a_pib + (float)a_turismo + (float)a_pib_per_capita + (1.0 / (float)a_densidade_pop);

    //título do jogo ( Super Trunfo)
    printf("*** Super Trunfo ***\n");
    // Imprimindo o valor da string "Pernambuco"
    printf("--- Card 1 ---\n");
    printf("Código: %s\n", p_codigo);
    printf("Estado: %s\n", p_estado);
    printf("Capital: %s\n", p_capital);
    printf("População: %lu habitantes\n", p_populacao); // %lu para unsigned long int
    printf("Área: %.1f km²\n", p_area); // Use %.1f para formatar float com 1 casa decimal
    printf("PIB: R$ %.2f  (Bilhões)\n", p_pib); // Use %.2f para formatar float com 2 casas decimais
    printf("Pontos Turísticos: %d\n", p_turismo);
    printf("Densidade Populacional: %.2f hab/km²\n", p_densidade_pop);
    printf("PIB per Capita: %.2f reais\n", p_pib_per_capita);
    printf("Super Poder: %.2f\n", p_super_poder); // Novo atributo
    printf("---------------------------\n");

    // Imprimindo o valor da string "Alagoas"
    printf("--- Card 2 ---\n");
    printf("Código: %s\n", a_codigo);
    printf("Estado: %s\n", a_estado);
    printf("Capital: %s\n", a_capital);
    printf("População: %lu habitantes\n", a_populacao); // %lu para unsigned long int    printf("Área: %.1f km²\n", a_area); // Use %.1f para formatar float com 1 casa decimal
    printf("PIB: R$ %.2f  (Bilhões)\n", a_pib); // Use %.2f para formatar float com 2 casas decimais
    printf("Pontos Turísticos: %d\n", a_turismo);
    printf("Densidade Populacional: %.2f hab/km²\n", a_densidade_pop);
    printf("PIB per Capita: %.2f reais\n", a_pib_per_capita);
    printf("Super Poder: %.2f\n", a_super_poder); // Novo atributo
    printf("---------------------------\n");


    // --- NOVO NÍVEL MESTRE: COMPARAÇÃO DAS CARTAS ---
    // Regra: MAIOR valor vence, EXCETO para Densidade Populacional (MENOR valor vence)
    
    // População (Maior vence)
    comp_populacao = (p_populacao > a_populacao) ? 1 : 0;
    
    // Área (Maior vence)
    comp_area = (p_area > a_area) ? 1 : 0;
    
    // PIB (Maior vence)
    comp_pib = (p_pib > a_pib) ? 1 : 0;
    
    // Pontos Turísticos (Maior vence)
    comp_turismo = (p_turismo > a_turismo) ? 1 : 0;

    // Densidade Populacional (Menor vence)
    comp_densidade = (p_densidade_pop < a_densidade_pop) ? 1 : 0;
    
    // PIB per Capita (Maior vence)
    comp_pib_per_capita = (p_pib_per_capita > a_pib_per_capita) ? 1 : 0;
    
    // Super Poder (Maior vence)
    comp_super_poder = (p_super_poder > a_super_poder) ? 1 : 0;


    // --- NOVO NÍVEL MESTRE: EXIBIÇÃO DOS RESULTADOS DAS COMPARAÇÕES ---
    printf("\n--- Comparação de Cartas ---\n");
    
    printf("População: Card %d venceu (%d)\n", comp_populacao == 1 ? 1 : 2, comp_populacao);
    printf("Área: Card %d venceu (%d)\n", comp_area == 1 ? 1 : 2, comp_area);
    printf("PIB: Card %d venceu (%d)\n", comp_pib == 1 ? 1 : 2, comp_pib);
    printf("Pontos Turísticos: Card %d venceu (%d)\n", comp_turismo == 1 ? 1 : 2, comp_turismo);
    printf("Densidade Populacional: Card %d venceu (%d)\n", comp_densidade == 1 ? 1 : 2, comp_densidade);
    printf("PIB per Capita: Card %d venceu (%d)\n", comp_pib_per_capita == 1 ? 1 : 2, comp_pib_per_capita);
    printf("Super Poder: Card %d venceu (%d)\n", comp_super_poder == 1 ? 1 : 2, comp_super_poder);
    
    printf("----------------------------\n");

    return 0;
}