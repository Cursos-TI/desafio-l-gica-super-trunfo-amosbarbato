#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

// Estrutura de Carta
typedef struct {
    char name[50];
    int population;
    float territory;
    float gdp;
    int touristPoints;
    float density; // populacao / area
} Carta;


int main() {
    // Duas cartas pré-cadastradas
    Carta carta1 = {"Brasil", 214000000, 8515767.0, 1.9e12, 150, 0};
    Carta carta2 = {"Argentina", 46000000, 2780400.0, 5.8e11, 80, 0};

    // Calcular densidade demográfica
    carta1.density = (float)carta1.population / carta1.territory;
    carta2.density = (float)carta2.population / carta2.territory;

    int option;

    printf("===== SUPER TRUNFO =====\n");
    printf("Comparando as cartas: %s x %s\n", carta1.name, carta2.name);
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &option);

    printf("\n--- Resultado da Comparação ---\n");


    switch(option) {
        case 1: // População
            printf("Atributo: População\n");
            printf("%s: %d\n", carta1.name, carta1.population);
            printf("%s: %d\n", carta2.name, carta2.population);
            if (carta1.population > carta2.population) {
                printf("Resultado: %s venceu!\n", carta1.name);
            } else if (carta2.population > carta1.population) {
                printf("Resultado: %s venceu!\n", carta2.name);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2: // Área
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", carta1.name, carta1.territory);
            printf("%s: %.2f km²\n", carta2.name, carta2.territory);
            if (carta1.territory > carta2.territory) {
                printf("Resultado: %s venceu!\n", carta1.name);
            } else if (carta2.territory > carta1.territory) {
                printf("Resultado: %s venceu!\n", carta2.name);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2e\n", carta1.name, carta1.gdp);
            printf("%s: %.2e\n", carta2.name, carta2.gdp);
            if (carta1.gdp > carta2.gdp) {
                printf("Resultado: %s venceu!\n", carta1.name);
            } else if (carta2.gdp > carta1.gdp) {
                printf("Resultado: %s venceu!\n", carta2.name);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4: // Pontos Turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d\n", carta1.name, carta1.touristPoints);
            printf("%s: %d\n", carta2.name, carta2.touristPoints);
            if (carta1.touristPoints > carta2.touristPoints) {
                printf("Resultado: %s venceu!\n", carta1.name);
            } else if (carta2.touristPoints > carta1.touristPoints) {
                printf("Resultado: %s venceu!\n", carta2.name);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5: // Densidade Demográfica (menor vence!)
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.6f hab/km²\n", carta1.name, carta1.density);
            printf("%s: %.6f hab/km²\n", carta2.name, carta2.density);
            if (carta1.density < carta2.density) {
                printf("Resultado: %s venceu!\n", carta1.name);
            } else if (carta2.density < carta1.density) {
                printf("Resultado: %s venceu!\n", carta2.name);
            } else {
                printf("Empate!\n");
            }
            break;

        default:
            printf("Opção inválida! Escolha entre 1 e 5.\n");
            break;
    }

    return 0;
}
