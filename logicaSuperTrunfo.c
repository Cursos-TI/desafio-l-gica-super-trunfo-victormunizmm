#include <stdio.h>

#include <string.h>

// Definição da estrutura da carta
typedef struct {
    char estado[3];       // Ex: "SP"
    char codigo[10];      // Ex: "C001"
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional; // Calculada
    float pib_per_capita;         // Calculada
} Carta;

// Função para calcular a densidade populacional
float calcularDensidade(int populacao, float area) {
    return (area > 0) ? (float)populacao / area : 0; // Evita divisão por zero
}

// Função para calcular o PIB per capita
float calcularPibPerCapita(float pib, int populacao) {
    return (populacao > 0) ? pib / populacao : 0; // Evita divisão por zero
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta) {
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome: %s\n", carta.nome);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f\n", carta.densidade_populacional);
    printf("PIB per capita: %.2f\n", carta.pib_per_capita);
    printf("\n");
}

int main() {
    Carta carta1, carta2;

    // 1. Cadastro das cartas (você pode reaproveitar o código do desafio anterior)
    printf("Cadastro da Carta 1:\n");
    printf("Estado: ");
    scanf("%s", carta1.estado);
    printf("Código: ");
    scanf("%s", carta1.codigo);
    printf("Nome: ");
    scanf(" %[^\n]", carta1.nome); // Lê nomes com espaços
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área: ");
    scanf("%f", &carta1.area);
    printf("PIB: ");
    scanf("%f", &carta1.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    printf("\nCadastro da Carta 2:\n");
    printf("Estado: ");
    scanf("%s", carta2.estado);
    printf("Código: ");
    scanf("%s", carta2.codigo);
    printf("Nome: ");
    scanf(" %[^\n]", carta2.nome);
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área: ");
    scanf("%f", &carta2.area);
    printf("PIB: ");
    scanf("%f", &carta2.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // 2. Cálculo de Densidade Populacional e PIB per capita
    carta1.densidade_populacional = calcularDensidade(carta1.populacao, carta1.area);
    carta1.pib_per_capita = calcularPibPerCapita(carta1.pib, carta1.populacao);
    carta2.densidade_populacional = calcularDensidade(carta2.populacao, carta2.area);
    carta2.pib_per_capita = calcularPibPerCapita(carta2.pib, carta2.populacao);

    // 3. Escolha do atributo para comparação (definido no código)
    int atributoComparacao = 1; // 1: População, 2: Área, 3: PIB, 4: Densidade, 5: PIB per capita

    // 4. Comparação e Determinação do Vencedor
    printf("\nComparação de cartas:\n");
    exibirCarta(carta1);
    exibirCarta(carta2);

    int vencedor;
    char *atributoNome;
    float valorCarta1, valorCarta2;

    switch (atributoComparacao) {
        case 1: // População
            atributoNome = "População";
            valorCarta1 = carta1.populacao;
            valorCarta2 = carta2.populacao;
            if (carta1.populacao > carta2.populacao) {
                vencedor = 1;
            } else if (carta2.populacao > carta1.populacao) {
                vencedor = 2;
            } else {
                vencedor = 0; // Empate
            }
            break;
        case 2: // Área
            atributoNome = "Área";
            valorCarta1 = carta1.area;
            valorCarta2 = carta2.area;
            if (carta1.area > carta2.area) {
                vencedor = 1;
            } else if (carta2.area > carta1.area) {
                vencedor = 2;
            } else {
                vencedor = 0;
            }
            break;
        case 3: // PIB
            atributoNome = "PIB";
            valorCarta1 = carta1.pib;
            valorCarta2 = carta2.pib;
            if (carta1.pib > carta2.pib) {
                vencedor = 1;
            } else if (carta2.pib > carta1.pib) {
                vencedor = 2;
            } else {
                vencedor = 0;
            }
            break;
        case 4: // Densidade Populacional
            atributoNome = "Densidade Populacional";
            valorCarta1 = carta1.densidade_populacional;
            valorCarta2 = carta2.densidade_populacional;
            if (carta1.densidade_populacional < carta2.densidade_populacional) {
                vencedor = 1;
            } else if (carta2.densidade_populacional < carta1.densidade_populacional) {
                vencedor = 2;
            } else {
                vencedor = 0;
            }
            break;
        case 5: // PIB per capita
            atributoNome = "PIB per capita";
            valorCarta1 = carta1.pib_per_capita;
            valorCarta2 = carta2.pib_per_capita;
            if (carta1.pib_per_capita > carta2.pib_per_capita) {
                vencedor = 1;
            } else if (carta2.pib_per_capita > carta1.pib_per_capita) {
                vencedor = 2;
            } else {
                vencedor = 0;
            }
            break;
        default:
            printf("Atributo inválido para comparação.\n");
            return 1;
    }

    // 5. Exibição do Resultado
    printf("Comparação de cartas (Atributo: %s):\n", atributoNome);
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nome, carta1.estado, valorCarta1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nome, carta2.estado, valorCarta2);

    if (vencedor == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
    } else if (vencedor == 2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
