#include <stdio.h>

int validaQuantidade() {
    int quantidade;
    while (1) {
        printf("Digite a quantidade de peças fabricadas: ");
        if (scanf("%d", &quantidade) != 1 || quantidade < 0) {
            printf("Quantidade inválida. Tente novamente.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
        } else {
            return quantidade;
        }
    }
}

float calculaSalario(int quantidade) {
    float salario_base = 600.0;
    float adicional = 0.0;

    if (quantidade > 50) {
        adicional += (quantidade - 50) * 0.5;
        if (quantidade > 80) {
            adicional += (quantidade - 80) * 0.25;
        }
    }

    return salario_base + adicional;
}

void mostraFinal() {
    int quantidade_funcionarios;

    while (1) {
        printf("Digite o número de funcionários: ");
        if (scanf("%d", &quantidade_funcionarios) != 1 || quantidade_funcionarios < 1) {
            printf("Número de funcionários inválido. Tente novamente.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
        } else {
            break;
        }
    }

    for (int i = 0; i < quantidade_funcionarios; i++) {
        printf("\nFuncionário %d:\n", i + 1);
        int quantidade = validaQuantidade();
        float salario = calculaSalario(quantidade);
        printf("Salário do funcionário %d: R$ %.2f\n", i + 1, salario);
    }
}

int main() {
    mostraFinal();
    return 0;
}
