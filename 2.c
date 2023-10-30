#include <stdio.h>
#include <ctype.h>

// Função para validar o sexo (M ou F)
char validaSexo() {
    char sexo;
    while (1) {
        printf("Informe o sexo (M/F): ");
        scanf(" %c", &sexo);
        sexo = toupper(sexo);  // Converte para maiúscula

        if (sexo == 'M' || sexo == 'F') {
            return sexo;
        } else {
            printf("Sexo inválido. Digite M para masculino ou F para feminino.\n");
        }
    }
}

// Função para validar o salário (deve ser maior que R$ 1,00)
float validaSalario() {
    float salario;
    while (1) {
        printf("Informe o salário em reais: R$ ");
        if (scanf("%f", &salario) == 1 && salario > 1.0) {
            return salario;
        } else {
            printf("Salário inválido. Deve ser maior que R$ 1,00. Tente novamente.\n");
        }
    }
}

// Função para classificar o salário em relação ao salário mínimo
char* classificaSalario(float salario) {
    const float salarioMinimo = 1400.0;
    if (salario > salarioMinimo) {
        return "Acima do salário mínimo";
    } else if (salario == salarioMinimo) {
        return "Igual ao salário mínimo";
    } else {
        return "Abaixo do salário mínimo";
    }
}

// Função para mostrar os resultados
void mostraClassifica(char sexo, float salario) {
    char* classificacao = classificaSalario(salario);
    printf("Salário: R$ %.2f\n", salario);
    printf("Classificação: %s\n", classificacao);
    printf("Sexo: %s\n", (sexo == 'M') ? "Masculino" : "Feminino");
    printf("\n");
}

int main() {
    int numAssalariados, abaixoMinimo = 0, acimaMinimo = 0;

    printf("Informe o número de assalariados: ");
    scanf("%d", &numAssalariados);

    for (int i = 0; i < numAssalariados; i++) {
        printf("\nAssalariado %d:\n", i + 1);
        char sexo = validaSexo();
        float salario = validaSalario();
        mostraClassifica(sexo, salario);

        if (salario < 1400.0) {
            abaixoMinimo++;
        } else {
            acimaMinimo++;
        }
    }

    printf("\nQuantidade de assalariados abaixo do salário mínimo: %d\n", abaixoMinimo);
    printf("Quantidade de assalariados acima do salário mínimo: %d\n", acimaMinimo);

    return 0;
}
