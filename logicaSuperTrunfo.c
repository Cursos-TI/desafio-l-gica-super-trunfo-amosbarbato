#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    char state1, state2;
    char code1[4], code2[4];
    char city1[50], city2[50];
    int population1, population2;
    float territory1, territory2;
    float gdp1, gdp2;
    int touristPoints1, touristPoints2;
    float density1, density2;
    float gdpPerCapita1, gdpPerCapita2;

    // Carta 1
    printf("Cadastro da carta 1:\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &state1);

    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%s", code1);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", city1); // permite ler com espaços

    printf("Digite a População: ");
    scanf("%d", &population1);

    printf("Digite a Área (em km²): ");
    scanf("%f", &territory1);

    printf("Digite o PIB: ");
    scanf("%f", &gdp1);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &touristPoints1);


    // Carta 2
    printf("Cadastro da carta 2:\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &state2);

    printf("Digite o Código da Carta (ex: B01): ");
    scanf("%s", code2);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", city2); // permite ler com espaços

    printf("Digite a População: ");
    scanf("%d", &population2);

    printf("Digite a Área (em km²): ");
    scanf("%f", &territory2);

    printf("Digite o PIB: ");
    scanf("%f", &gdp2);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &touristPoints2);


    // Calculo
    density1 = population1 / territory1;
    gdpPerCapita1 = (gdp1 * 1000000000.0) / population1;

    density2 = population2 / territory2;
    gdpPerCapita2 = (gdp2 * 1000000000.0) / population2;


    // Comparação das cartas
    printf("\nComparação de Cartas (Atributo: População):\n");
    printf("Carta 1 - %s (%s): %d habitantes\n", city1, state1, population1);
    printf("Carta 2 - %s (%s): %d habitantes\n", city2, state2, population2);

    if (population1 > population2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", city1);
    } else if (population2 > population1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", city2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
