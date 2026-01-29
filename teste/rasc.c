#include <stdio.h>
#include <stdlib.h> // Necessário para malloc/free e controle do sistema
#include <string.h>

typedef struct Cliente {
    char nome[50];
    char cpf[12];
    char email[100];
    char telefone[15];
    char data_nascimento[11]; // Aumentado para 11 para caber o '\0' final
} Cliente;

// Protótipos das funções
void print_menu();
void cadastrar_cliente(Cliente *c); // Passamos o endereço de UM cliente
void listar_cliente(Cliente *c);

int main() {
    int entrada;
    int qtd_max;
    int clientes_cadastrados = 0;

    print_menu();
    printf("\nDigite a opcao desejada: ");
    scanf("%d", &entrada);

    
    printf("Quantos clientes deseja cadastrar no total? ");
    scanf("%d", &qtd_max);
    Cliente lista[qtd_max];

    if (entrada == 1) {
       // Loop para cadastrar
        for (int i = 0; i < qtd_max; i++) {
            printf("\n--- Cadastro do Cliente %d ---\n", i + 1);
            cadastrar_cliente(&lista[i]); // Passa o endereço da posição i
            clientes_cadastrados++;
        }

    } 
    else if (entrada == 2){
        // Exemplo de como listar logo após cadastrar
        printf("\n--- LISTAGEM DE CLIENTES ---\n");
        for (int i = 0; i < clientes_cadastrados; i++) {
            listar_cliente(&lista[i]);
        }
    }
    else {
        printf("Para testar, escolha a opcao 1 primeiro!\n");
    }

    return 0;
}

void print_menu() {
    printf("--------------- BEM VINDO AO SISTEMA DE COMPRAS ------------------\n");
    printf("1 - Cadastrar clientes\n");
    printf("2 - Listar todos os clientes\n");
    printf("3 - Buscar cliente pelo CPF\n");
    printf("4 - Editar dados\n");
    printf("5 - Remover cliente\n");
}

void cadastrar_cliente(Cliente *c) {
    // O espaço antes do %s serve para ignorar o "Enter" anterior no buffer
    printf("Nome: ");
    scanf(" %[^\n]s", c->nome); // %[^\n] lê inclusive espaços (nomes compostos)

    printf("CPF: ");
    scanf(" %s", c->cpf);

    printf("Email: ");
    scanf(" %s", c->email);

    printf("Telefone: ");
    scanf(" %s", c->telefone);

    printf("Data de Nascimento (dd/mm/aaaa): ");
    scanf(" %s", c->data_nascimento);
}

void listar_cliente(Cliente *c) {
    printf("-------------------------------\n");
    printf("Nome: %s\n", c->nome);
    printf("CPF: %s\n", c->cpf);
    printf("Email: %s\n", c->email);
    printf("Telefone: %s\n", c->telefone);
    printf("Nascimento: %s\n", c->data_nascimento);
}