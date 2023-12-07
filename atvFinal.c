#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definição da estrutura para o registro de veículos
typedef struct Veiculo {
    char proprietario[50];
    char combustivel[15];
    char modelo[50];
    char cor[20];
    char chassi[20];
    int ano;
    char placa[8];
    struct Veiculo* proximo;
}Veiculo;

// Função para adicionar um novo veículo à lista
Veiculo* adicionarVeiculo(Veiculo* lista, char proprietario[], char combustivel[],
                          char modelo[], char cor[], char chassi[], int ano, char placa[]) {
    Veiculo* novoVeiculo = (Veiculo*)malloc(sizeof(Veiculo));

    if (novoVeiculo == NULL){
        printf("Erro ao alocar memória para o novo veículo.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(novoVeiculo->proprietario, proprietario);
    strcpy(novoVeiculo->combustivel, combustivel);
    strcpy(novoVeiculo->modelo, modelo);
    strcpy(novoVeiculo->cor, cor);
    strcpy(novoVeiculo->chassi, chassi);
    novoVeiculo->ano = ano;
    strcpy(novoVeiculo->placa, placa);

    novoVeiculo->proximo = lista;
    return novoVeiculo;
}

// a. Listar proprietários de carros do ano de 2010 ou posterior e movidos a diesel
void listarProprietariosDiesel2010OuPosterior(Veiculo* lista){
    printf("Proprietários de carros do ano de 2010 ou posterior e movidos a diesel:\n");

    while (lista != NULL){
        if (lista->ano >= 2010 && strcmp(lista->combustivel, "diesel") == 0){
            printf("- %s\n", lista->proprietario);
        }
        lista = lista->proximo;
    }
}

// b. Listar placas que começam com J e terminam com 0, 2, 4 ou 7 e seus proprietários
void listarPlacasJTerminadasEm0247(Veiculo* lista) {
    printf("Placas que começam com J e terminam com 0, 2, 4 ou 7 e seus proprietários:\n");

    while (lista != NULL){
        if (lista->placa[0] == 'J' &&
            (lista->placa[6] == '0' || lista->placa[6] == '2' || lista->placa[6] == '4' || lista->placa[6] == '7')) {
            printf("- Placa: %s, Proprietário: %s\n", lista->placa, lista->proprietario);
        }
        lista = lista->proximo;
    }
}

// c. Listar modelo e cor dos veículos cujas placas têm segunda letra vogal e soma dos valores numéricos é par
void listarModeloCorPlacasVogalSomaPar(Veiculo* lista){
    printf("Modelo e cor dos veículos cujas placas têm segunda letra vogal e soma dos valores numéricos é par:\n");

    while (lista != NULL){
        if (strchr("aeiouAEIOU", lista->placa[1]) != NULL){
            int somaNumeros = 0;
            for (int i = 0; i < 7; i++) {
                if (isdigit(lista->placa[i])) {
                    somaNumeros += lista->placa[i] - '0';
                }
            }
            if (somaNumeros % 2 == 0){
                printf("- Modelo: %s, Cor: %s\n", lista->modelo, lista->cor);
            }
        }
        lista = lista->proximo;
    }
}

// d. Trocar proprietário com base no chassi para carros com placas sem dígitos 0
Veiculo* trocarProprietarioPorChassi(Veiculo* lista, char chassi[], char novoProprietario[]) {
    Veiculo* atual = lista;

    while (atual != NULL){
        if (strstr(atual->chassi, chassi) != NULL && strpbrk(atual->placa, "0") == NULL){
            strcpy(atual->proprietario, novoProprietario);
            printf("Proprietário do veículo com chassi %s alterado para %s\n", chassi, novoProprietario);
            return lista;
        }
        atual = atual->proximo;
    }

    printf("Veículo com chassi %s não encontrado ou possui dígito 0 na placa.\n", chassi);
    return lista;
}

// Função para liberar a memória alocada para a lista
void liberarLista(Veiculo* lista){
    Veiculo* atual = lista;
    Veiculo* proximo;

    while (atual != NULL){
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

// Função principal
int main(){
    Veiculo* listaVeiculos = NULL;

    // Adiciona alguns veículos fictícios para testar as funcionalidades
    listaVeiculos = adicionarVeiculo(listaVeiculos, "Proprietario1", "gasolina", "Modelo1", "Cor1", "Chassi1", 2015, "ABC1234");
    listaVeiculos = adicionarVeiculo(listaVeiculos, "Proprietario2", "diesel", "Modelo2", "Cor2", "Chassi2", 2010, "JZZ0247");
    listaVeiculos = adicionarVeiculo(listaVeiculos, "Proprietario3", "alcool", "Modelo3", "Cor3", "Chassi3", 2022, "XYZ1070");

    // a. Listar proprietários de carros do ano de 2010 ou posterior e movidos a diesel
    listarProprietariosDiesel2010OuPosterior(listaVeiculos);

    // b. Listar placas que começam com J e terminam com 0, 2, 4 ou 7 e seus proprietários
    listarPlacasJTerminadasEm0247(listaVeiculos);

    // c. Listar modelo e cor dos veículos cujas placas têm segunda letra vogal e soma dos valores numéricos é par
    listarModeloCorPlacasVogalSomaPar(listaVeiculos);

    // d. Trocar proprietário com base no chassi para carros com placas sem dígitos 0
    listaVeiculos = trocarProprietarioPorChassi(listaVeiculos, "Chassi1", "NovoProprietario");

    // Libera a memória alocada para a lista
    liberarLista(listaVeiculos);
