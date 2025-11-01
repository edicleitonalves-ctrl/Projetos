#include <stdio.h>

int main() {
    // Variáveis do Cartão "Super Trunfo" - Recife/Pernambuco
    char estado[] = "Pernambuco";
    char codigo[20] = "A01";
    char capital[50] = "Recife"; // Renomeei "Estado" para "capital" para evitar confusão.
    int populacao = 1488920; 
    float area = 218.8;      
    float pib = 54.97;       
    int turismo = 20;

    // Imprimindo o valor da string "estado"
    printf("--- Cartão Super Trunfo ---\n");
    printf("Código: %s\n", codigo);
    printf("Estado: %s\n", estado);
    printf("Capital: %s\n", capital);
    printf("População: %d habitantes\n", populacao);
    printf("Área: %.1f km²\n", area); // Use %.1f para formatar float com 1 casa decimal
    printf("PIB (Bilhões): R$ %.2f\n", pib); // Use %.2f para formatar float com 2 casas decimais
    printf("Pontos Turísticos: %d\n", turismo);
    printf("---------------------------\n");


    return 0;
}