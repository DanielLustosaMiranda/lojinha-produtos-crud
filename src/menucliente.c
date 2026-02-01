#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menucliente.h"



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
                if (atual == NULL) printf("Lista vazia!\n");
                while (atual != NULL) {
                    listar_cliente(atual);
                    atual = atual->proximo;
                }
                break;
            }
            case 3: {
                char cpf_aux[15];
                printf("Digite o CPF para buscar: ");
                scanf("%s", cpf_aux);
                Cliente *achado = buscar_cliente(inicio, cpf_aux);
                if (achado) {
                    printf("\nCliente encontrado:\n");
                    listar_cliente(achado);
                } else {
                    printf("\nCliente nao encontrado.\n");
                }
                break;
            }
            case 4:
                editar_dados(inicio);
                break;

            case 5:
                inicio = remover_cliente(inicio);
                break; 
                
                
            case 0:
                printf("Saindo do sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (entrada != 0);

    // LIBERAÇÃO DE MEMÓRIA
    Cliente *atual = inicio;
    while (atual != NULL) {
        Cliente *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    return 0;
}

// --- FUNÇÕES ---



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
    scanf(" %[^\n]", c->nome);
    printf("CPF: ");
    scanf(" %s", c->cpf);
    printf("Email: ");
    scanf(" %s", c->email);
    printf("Telefone: ");
    scanf(" %s", c->telefone);
    printf("Data de Nascimento (DD/MM/AAAA): ");
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

Cliente* buscar_cliente(Cliente *inicio, char *cpf_procurado) {
    Cliente *atual = inicio;
    while (atual != NULL) {
        if (strcmp(atual->cpf, cpf_procurado) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void menu_editar() {
    printf("O que desejar editar?\n");
    printf("1 - Editar nome do cliente.\n");
    printf("2 - Editar cpf do cliente.\n");
    printf("3 - Editar email do cliente.\n");
    printf("4 - Editar telefone do cliente.\n");
    printf("5 - Editar data de nascimento do cliente.\n");
}

void editar_dados(Cliente *inicio) {
    int entrada;
    char cpf_busca[15];

    if (inicio == NULL) {
        printf("A lista esta vazia!\n");
        return;
    }

    printf("Digite o cpf a ser procurado: ");
    scanf("%s", cpf_busca);
    while (getchar() != '\n'); 

    Cliente *encontrado = buscar_cliente(inicio, cpf_busca);

    if (encontrado == NULL) {
        printf("Cliente nao encontrado!\n");
        return;
    }

    do {
        menu_editar();
        scanf("%d", &entrada);
        while (getchar() != '\n');

        

        switch (entrada) {
            case 1:
                printf("Mudar nome: ");
                scanf("% [^\n]", encontrado->nome);
                printf("Nome editado.\n");
                printf("Novo nome: %s\n", encontrado->nome);
                break;
            case 2:
                printf("Mudar CPF: ");
                scanf("%11s", encontrado->cpf);
                printf("CPF editado.\n");
                 printf("Novo cpf: %s\n", encontrado->cpf);
                break;
            case 3:   
                printf("Mudar email: ");
                scanf("%s", encontrado->email);
                printf("Email editado.\n");
                 printf("Novo email: %s\n", encontrado->email);
                break;
            case 4: 
                printf("Mudar telefone: ");
                scanf("%s", encontrado->telefone);
                printf("Telefone editado.\n");
                 printf("Novo telefone: %s\n", encontrado->telefone);
                break;
            case 5: 
                printf("Mudar data de nascimento: ");
                scanf("%s", encontrado->data_nascimento);
                printf("Data de nascimento editada.\n");
                 printf("Nova data de nascimento: %s\n", encontrado->data_nascimento);
                break;
            case 0: 
                printf("Saindo da edicao.\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (entrada != 0);
}

Cliente* remover_cliente(Cliente *inicio){
    int opcao;
    char cpf_busca[15];
    Cliente *atual = inicio;
    Cliente *anterior = NULL;

    if (inicio == NULL){
        printf("A lista esta vazia.\n");
        return NULL;
    }

    printf("Digite o cpf que deseja remover:\n ");
    scanf("%s", cpf_busca);
    while (getchar() != '\n'); 

    while (atual != NULL && strcmp(atual->cpf, cpf_busca) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }  
    
    if (atual == NULL) {
        printf("Cliente com CPF %s nao encontrado.\n", cpf_busca);
        return inicio; // Retorna a lista original sem mexer em nada
    }

    printf("Cliente encontrado:%s \n", atual->nome);
    menu_remove();
    scanf("%d", &opcao);
    while (getchar() != '\n');

    if (opcao == 1){
        if (anterior == NULL){
            inicio = atual->proximo;
        } 
        
        else {
            anterior->proximo = atual->proximo;
        }
        free(atual);
        printf("Cliente removido com sucesso!\n");
    } 
    
    else {
        printf("Remoçao cancelada.\n");
    }
    
    return inicio;
}

void menu_remove(){
    printf("Deseja remover o cliente?\n");
    printf("1  -  SIM \n");
    printf("2  -  NAO \n");
}