#include <stdio.h>
#include <string.h>

// Funcao para sexo
char* validarSexo(){
    static char sexo[10];
    do{
        printf("Informe o sexo - Masculino ou Feminino:\n");
        fgets(sexo, 10, stdin);
    }while (strcmp(sexo, "Masculino") != 0 && strcmp(sexo, "Feminino") != 0);

    return sexo;
}

// Validar salario
float validaSalario(){
    float salario;
    do {
        printf("Informe o salario:");
        scanf("%f", &salario);
    } while (salario <= 1.00);
    return salario;
}

// Salario ao salario minimo
char* classificarSalario(float salario){
    const float salarioMinimo = 1.400;
    if (salario > salarioMinimo) {
        return "Acima do salario minimo";
    } else if (salario < salarioMinimo) {
        return "Abaixo do salario minimo";
    } else {
        return "Igual ao salario minimo";
    }
}

void mostraClassificacao(char* sexo, float salario){
    printf("Salario: R$%.2f\n", salario);
    printf("Classificacao: %s\n", classificarSalario(salario));
    printf("Sexo: %s\n", sexo);
}

int main(){
    int numAssalariados, abaixoSalarioMinimo = 0, acimaSalarioMinimo = 0;

    printf("Informe o numero de assalariados: ");
    scanf("%d", &numAssalariados);

    for (int i = 0; i < numAssalariados; i++){
        printf("\nAssalariado %d:\n", i++);

        char* sexo = validarSexo();
        float salario = validaSalario();

        // Contabiliza a quantidade de assalariados abaixo ou acima do salario minimo
        if (salario < 1.400){
            abaixoSalarioMinimo++;
        } else if (salario > 1.400){
            acimaSalarioMinimo++;
        }

        // Mostra os resultados
        mostraClassificacao(sexo, salario);
    }

    // Apresenta o total de assalariados abaixo e acima do salario minimo
    printf("Total de assalariados abaixo do salario minimo: %d\n", abaixoSalarioMinimo);
    printf("Total de assalariados acima do salario minimo: %d\n", acimaSalarioMinimo);

    return 0;
}