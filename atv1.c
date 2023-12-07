#include <stdio.h>

// Função para validar a quantidade de peças
int validaQuantidade() {
    int Quantidade;

    printf("Digite a quantidade de pecas fabricadas:");
    scanf("%d", &Quantidade);
    if(Quantidade < 50){
        printf("Nao recebe adicional.\n");
    }

    return Quantidade;
}

// Função para calcular o salário total
float calcularSalario(int quantidade) {
    float salarioBase = 600.00;
    int Quantidade1 = 50;
    int Quantidade2 = 80;
    float Adicional1 = 0.5;
    float Adicional2 = 0.75;

    if (quantidade <= Quantidade1) {
        return salarioBase;
    } else if (quantidade <= Quantidade2) {
        return salarioBase + (quantidade - Quantidade1) * Adicional1;
    } else {
        return salarioBase + (Quantidade2 - Quantidade1) * Adicional1 + (quantidade - Quantidade2) * Adicional2;
    }
}

// Procedimento para mostrar o resultado final
void mostraFinal(float salario) {
    printf("\nO salario total e: R$ %.2f\n", salario);
}

int main() {
    int quantidade;
    int opcao;

    do {
        quantidade = validaQuantidade();
        float salario = calcularSalario(quantidade);
        mostraFinal(salario);

        printf("\nDeseja calcular o salario de outro funcionario? 1 - Sim.\n0 - Nao. ");
        scanf(" %d", &opcao);

    } while (opcao != 0);

    return 0;
}
