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

// Função para exibir o menu de atributos
void showMenu(int delete) {
    printf("\nEscolha um atributo para comparar:\n");
    if (delete != 1) printf("1 - População\n");
    if (delete != 2) printf("2 - Área\n");
    if (delete != 3) printf("3 - PIB\n");
    if (delete != 4) printf("4 - Pontos Turísticos\n");
    if (delete != 5) printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
}

// Função para obter valor de atributo de uma carta
float getValueAttribute(Carta c, int attribute) {
    switch(attribute) {
        case 1: return (float)c.population;
        case 2: return c.territory;
        case 3: return c.gdp;
        case 4: return (float)c.touristPoints;
        case 5: return c.density;
        default: return 0.0;
    }
}

// Função para exibir nome do atributo
const char* attributeName(int attribute) {
    switch(attribute) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}



int main() {
    // Duas cartas pré-cadastradas
    Carta carta1 = {"Brasil", 214000000, 8515767.0, 1.9e12, 150, 0};
    Carta carta2 = {"Argentina", 46000000, 2780400.0, 5.8e11, 80, 0};

    // Calcular densidade demográfica
    carta1.density = (float)carta1.population / carta1.territory;
    carta2.density = (float)carta2.population / carta2.territory;

    int attribute1, attribute2;

    int option;

    printf("===== SUPER TRUNFO =====\n");
    printf("Comparando as cartas: %s x %s\n", carta1.name, carta2.name);

    // Escolha do primeiro atributo
    showMenu(0);
    scanf("%d", &attribute1);

    // Escolha do segundo atributo (dinâmico: remove o primeiro da lista)
    showMenu(attribute1);
    scanf("%d", &attribute2);

    // Obter valores
    float value1_attr1 = getValueAttribute(carta1, attribute1);
    float value2_attr1 = getValueAttribute(carta2, attribute1);
    float value1_attr2 = getValueAttribute(carta1, attribute2);
    float value2_attr2 = getValueAttribute(carta2, attribute2);


    // Comparação dos atributos individualmente
    printf("\n--- Comparação Atributo 1 (%s) ---\n", attributeName(attribute1));
    printf("%s: %.2f\n", carta1.name, value1_attr1);
    printf("%s: %.2f\n", carta2.name, value2_attr1);

    int winner_attr1;
    if (attribute1 == 5) { // densidade -> menor vence
        winner_attr1 = (value1_attr1 < value2_attr1) ? 1 : (value2_attr1 < value1_attr1 ? 2 : 0);
    } else {
        winner_attr1 = (value1_attr1 > value2_attr1) ? 1 : (value2_attr1 > value1_attr1 ? 2 : 0);
    }
    winner_attr1 == 0 ? printf("Empate!\n") :
    printf("Vencedor: %s\n", winner_attr1 == 1 ? carta1.name : carta2.name);


    printf("\n--- Comparação Atributo 2 (%s) ---\n", attributeName(attribute2));
    printf("%s: %.2f\n", carta1.name, value1_attr2);
    printf("%s: %.2f\n", carta2.name, value2_attr2);

    int winner_attr2;
    if (attribute2 == 5) { // densidade -> menor vence
        winner_attr2 = (value1_attr2 < value2_attr2) ? 1 : (value2_attr2 < value1_attr2 ? 2 : 0);
    } else {
        winner_attr2 = (value1_attr2 > value2_attr2) ? 1 : (value2_attr2 > value1_attr2 ? 2 : 0);
    }
    winner_attr2 == 0 ? printf("Empate!\n") :
    printf("Vencedor: %s\n", winner_attr2 == 1 ? carta1.name : carta2.name);
    

    // Soma dos atributos (densidade invertida -> transforma em "força" com inverso)
    float soma1 = (attribute1 == 5 ? (1/value1_attr1) : value1_attr1) +
                  (attribute2 == 5 ? (1/value1_attr2) : value1_attr2);

    float soma2 = (attribute1 == 5 ? (1/value2_attr1) : value2_attr1) +
                  (attribute2 == 5 ? (1/value2_attr2) : value2_attr2);

    printf("\n--- Resultado Final (Soma dos Atributos) ---\n");
    printf("%s: %.2f\n", carta1.name, soma1);
    printf("%s: %.2f\n", carta2.name, soma2);

    if (soma1 > soma2) {
        printf("Resultado Final: %s venceu!\n", carta1.name);
    } else if (soma2 > soma1) {
        printf("Resultado Final: %s venceu!\n", carta2.name);
    } else {
        printf("Resultado Final: Empate!\n");
    }

    return 0;
}
