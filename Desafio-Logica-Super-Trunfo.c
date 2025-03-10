
#include <stdio.h>
#include <string.h>

// Estrutura para representar um país no jogo
typedef struct {
    char nome[50];
    int populacao;
    float area;
    float densidade;
    int pib;
} Pais;

// Função para exibir os atributos disponíveis
void exibirAtributos() {
    printf("\nEscolha um atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - Densidade Demografica\n");
    printf("4 - PIB\n");
}

// Função para validar a escolha dos atributos
int escolherAtributo(int escolhido) {
    int opcao;
    do {
        printf("Digite o numero do atributo: ");
        scanf("%d", &opcao);
        if (opcao == escolhido) {
            printf("\nEsse atributo ja foi escolhido. Escolha outro.\n");
        }
    } while (opcao < 1 || opcao > 4 || opcao == escolhido);
    return opcao;
}

// Função para obter o valor do atributo escolhido
float obterValorAtributo(Pais p, int atributo) {
    switch (atributo) {
        case 1: return p.populacao;
        case 2: return p.area;
        case 3: return p.densidade;
        case 4: return p.pib;
        default: return 0;
    }
}

// Função principal
int main() {
    // Definição das cartas
    Pais paises[] = {
        {"Brasil", 213000000, 8515767, 25.0, 2200000},
        {"Japao", 126000000, 377975, 333.0, 5000000}
    };

    int atributo1, atributo2;
    float valor1_pais1, valor1_pais2;
    float valor2_pais1, valor2_pais2;
    float soma1, soma2;

    // Exibir opções de atributos e escolher o primeiro
    exibirAtributos();
    atributo1 = escolherAtributo(-1);

    // Exibir novamente sem o atributo já escolhido
    exibirAtributos();
    atributo2 = escolherAtributo(atributo1);

    // Obter valores dos atributos
    valor1_pais1 = obterValorAtributo(paises[0], atributo1);
    valor1_pais2 = obterValorAtributo(paises[1], atributo1);
    valor2_pais1 = obterValorAtributo(paises[0], atributo2);
    valor2_pais2 = obterValorAtributo(paises[1], atributo2);

    // Comparação dos atributos individualmente
    int pontos_pais1 = 0, pontos_pais2 = 0;

    pontos_pais1 += (atributo1 == 3) ? (valor1_pais1 < valor1_pais2) : (valor1_pais1 > valor1_pais2);
    pontos_pais2 += (atributo1 == 3) ? (valor1_pais2 < valor1_pais1) : (valor1_pais2 > valor1_pais1);

    pontos_pais1 += (atributo2 == 3) ? (valor2_pais1 < valor2_pais2) : (valor2_pais1 > valor2_pais2);
    pontos_pais2 += (atributo2 == 3) ? (valor2_pais2 < valor2_pais1) : (valor2_pais2 > valor2_pais1);

    // Soma dos atributos
    soma1 = valor1_pais1 + valor2_pais1;
    soma2 = valor1_pais2 + valor2_pais2;

    // Exibição dos resultados
    printf("\nResultado:\n");
    printf("%s - %s: %.2f\n", paises[0].nome, (atributo1 == 1) ? "Populacao" : (atributo1 == 2) ? "Area" : (atributo1 == 3) ? "Densidade" : "PIB", valor1_pais1);
    printf("%s - %s: %.2f\n", paises[1].nome, (atributo1 == 1) ? "Populacao" : (atributo1 == 2) ? "Area" : (atributo1 == 3) ? "Densidade" : "PIB", valor1_pais2);

    printf("%s - %s: %.2f\n", paises[0].nome, (atributo2 == 1) ? "Populacao" : (atributo2 == 2) ? "Area" : (atributo2 == 3) ? "Densidade" : "PIB", valor2_pais1);
    printf("%s - %s: %.2f\n", paises[1].nome, (atributo2 == 1) ? "Populacao" : (atributo2 == 2) ? "Area" : (atributo2 == 3) ? "Densidade" : "PIB", valor2_pais2);

    printf("Soma dos atributos: %s = %.2f, %s = %.2f\n", paises[0].nome, soma1, paises[1].nome, soma2);

    // Determinar o vencedor
    if (soma1 > soma2) {
        printf("%s venceu!\n", paises[0].nome);
    } else if (soma2 > soma1) {
        printf("%s venceu!\n", paises[1].nome);
    } else {
        printf("Empate!\n");
    }
    return 0;
}
