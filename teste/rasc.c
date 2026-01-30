#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cliente {
    char nome[50];
    char cpf[12];
    char email[100];
    char telefone[15];
    char data_nascimento[11];
    struct Cliente *proximo; 
} Cliente;

void print_menu();
void cadastrar_cliente(Cliente *c);
void listar_cliente(Cliente *c);
void buscar_cliente(Cliente *c);
void editar_dados(Cliente *c);
void remover_cliente(Cliente *c);

int main() {
    int entrada;
   
    Cliente *inicio = NULL; 

    do {
        print_menu();
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &entrada);

        switch (entrada) {
            case 1: {
               
                Cliente *novo = (Cliente *) malloc(sizeof(Cliente));
                if (novo == NULL) {
                    printf("Erro de memoria!\n");
                    break;
                }
                
                cadastrar_cliente(novo);
                
                
                novo->proximo = inicio;
                inicio = novo;
                
                printf("\nCliente cadastrado com sucesso!\n");
                break;
            }
            case 2: {
                printf("\n--- LISTAGEM DE CLIENTES ---\n");
                Cliente *atual = inicio;
                if (atual == NULL) {
                    printf("Lista vazia!\n");
                }
                while (atual != NULL) {
                    listar_cliente(atual);
                }
                break;
            }
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida, tente novamente!\n");
        }
    } while (entrada != 0);

    Cliente *atual = inicio;
    while (atual != NULL) {
        Cliente *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}

void print_menu() {
    printf("\n--------------- SISTEMA DE COMPRAS (LISTA) ------------------\n");
    printf("1 - Cadastrar novo cliente\n");
    printf("2 - Listar todos os clientes\n");
    printf("3 - Buscar cliente pelo CPF\n");
    printf("4 - Editar dados de um cliente\n");
    printf("5 - Remover cliente\n");
    printf("0 - Sair\n");
}

void cadastrar_cliente(Cliente *c) {
    printf("Nome: ");
    scanf(" %[^\n]s", c->nome);
    printf("CPF: ");
    scanf(" %s", c->cpf);
    printf("Email: ");
    scanf(" %s", c->email);
    printf("Telefone: ");
    scanf(" %s", c->telefone);
    printf("Data de Nascimento: ");
    scanf(" %s", c->data_nascimento);
    c->proximo = NULL; 
}

void listar_cliente(Cliente *c) {
    printf("Nome do cliente: %s \n", c->nome);
    printf("CPF do cliente: %s\n", c->cpf);
    printf("Email do cliente: %s \n", c->email);
    printf("Telefone do cliente: %s \n", c->telefone);
    printf("Data de nascimento do cliente: %s \n", c->data_nascimento);
       
}

void buscar_cliente(Cliente *inicio){
    char cpf_procurado[12];
    printf("Digite o cpf procurado: \n");
    scanf("%s", cpf_procurado);

    Cliente *atual = inicio;
    
    while (atual != NULL) {
         

        if (strcmp(atual->cpf, cpf_procurado) == 0){
            printf("Cliente encontrado: %s\n", atual->nome);
            return;
        }
        atual = atual->proximo;
    }
    
    printf("CLiente nao encontrado.\n");

}

void editar_dados(Cliente *c){

}

void remover_cliente(Cliente *c){

}