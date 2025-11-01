#include <stdio.h>

int main() {
    // Variáveis do Cartão "Super Trunfo" - Recife/Pernambuco
    char estado[] = "Pernambuco";
    char codigo[20] = "A01";
    char capital[50] = "Recife";
    int populacao = 1488920; 
    float area = 218.8;        // km²      
    float pib = 54.97;          // PIB em Bilhões R$       
    int turismo = 20;

    // Variáveis do Cartão "Super Trunfo" - Maceió/Alagoas
    char a_estado[] = "Alagoas";
    char a_codigo[20] = "B01";
    char a_capital[50] = "Maceió";
    int a_populacao = 3127511;
    float a_area = 27843.2;        // km²
    float a_pib = 63.202;          // PIB em Bilhões R$
    int a_turismo = 9;

    // Imprimindo o valor da string "Pernambuco"
    printf("--- Card 1 ---\n");
    printf("Código: %s\n", codigo);
    printf("Estado: %s\n", estado);
    printf("Capital: %s\n", capital);
    printf("População: %d habitantes\n", populacao);
    printf("Área: %.1f km²\n", area); // Use %.1f para formatar float com 1 casa decimal
    printf("PIB: R$ %.2f  (Bilhões)\n", pib); // Use %.2f para formatar float com 2 casas decimais
    printf("Pontos Turísticos: %d\n", turismo);
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
    printf("---------------------------\n");


    return 0;
}