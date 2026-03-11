
#include <stdio.h>

typedef struct {
    char estado[50];
    char sigla[3];
    char cidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

int main() {
    Carta c1, c2;
    float densidade1, densidade2;
    int opcao;

    // --- Cadastro Simplificado (Exemplo Carta 1) ---
    printf("Cidade 1: "); scanf(" %[^\n]s", c1.cidade);
    printf("Populacao: "); scanf("%lu", &c1.populacao);
    printf("Area (km2): "); scanf("%f", &c1.area);
    printf("PIB (bilhoes): "); scanf("%f", &c1.pib);

    // --- Cadastro Simplificado (Exemplo Carta 2) ---
    printf("\nCidade 2: "); scanf(" %[^\n]s", c2.cidade);
    printf("Populacao: "); scanf("%lu", &c2.populacao);
    printf("Area (km2): "); scanf("%f", &c2.area);
    printf("PIB (bilhoes): "); scanf("%f", &c2.pib);

    // Calculos
    densidade1 = (float)c1.populacao / c1.area;
    densidade2 = (float)c2.populacao / c2.area;

    // --- Menu de Comparação ---
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - Populacao (Maior vence)\n");
    printf("2 - PIB (Maior vence)\n");
    printf("3 - Densidade (Menor vence)\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    printf("\n=== RESULTADO ===\n");

    switch(opcao) {
        case 1:
            printf("Atributo: Populacao\n");
            if (c1.populacao > c2.populacao) {
                printf("Vencedor: %s\n", c1.cidade);
            } else if (c2.populacao > c1.populacao) {
                printf("Vencedor: %s\n", c2.cidade);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2:
            printf("Atributo: PIB\n");
            if (c1.pib > c2.pib) {
                printf("Vencedor: %s\n", c1.cidade);
            } else if (c2.pib > c1.pib) {
                printf("Vencedor: %s\n", c2.cidade);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3:
            printf("Atributo: Densidade Populacional\n");
            // Lógica Inversa: Menor valor ganha
            if (densidade1 < densidade2) {
                printf("Vencedor: %s (Menor densidade)\n", c1.cidade);
            } else if (densidade2 < densidade1) {
                printf("Vencedor: %s (Menor densidade)\n", c2.cidade);
            } else {
                printf("Empate!\n");
            }
            break;

        default:
            printf("Opcao invalida.\n");
    }

    return 0;
}
