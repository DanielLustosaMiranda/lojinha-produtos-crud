#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menucliente.h"

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
                scanf("%[^\n]", encontrado->nome);
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
        return inicio; 
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

Cliente *novo_cadastro(Cliente *inicio){
    Cliente *novo = (Cliente *) malloc(sizeof(Cliente));

    if (novo == NULL){
        printf("Erro de memoria!\n");
        return inicio;
    }

    cadastrar_cliente(novo);
    novo->proximo = inicio;

    return novo;
}

void exibir_lista(Cliente *inicio){
    printf("Listagem de clientes\n");
    Cliente *atual = inicio;
    if (atual == NULL){
        printf("Lista vazia!\n");
        return;
    }

    while (atual != NULL){
        listar_cliente(atual);
        atual = atual->proximo;
    }
}

void executar_busca(Cliente *inicio){
    char cpf_buscar[15];
    printf("Digite o cpf procurado\n");
    scanf("%s", cpf_buscar);

    Cliente *achado = buscar_cliente(inicio, cpf_buscar);

    if (achado){
        printf("CLiente achado!\n");
        listar_cliente(inicio);
    }
    else {
        printf("Cliente nao encontrado!\n");
    }
}

void liberar_lista(Cliente *inicio) {
    Cliente *atual = inicio;
    while (atual != NULL) {
        Cliente *temp = atual;    
        atual = atual->proximo;   
        free(temp);               
    }
}

int menuCliente(Cliente *inicio) {
    int entrada;

    do {
        print_menu();
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &entrada);

        switch (entrada) {
            case 1: {
                inicio = novo_cadastro(inicio);
                break;
            }
            case 2: {
                exibir_lista(inicio);
                break;
            }
            case 3: {
                executar_busca(inicio);
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

    return 0;

}
