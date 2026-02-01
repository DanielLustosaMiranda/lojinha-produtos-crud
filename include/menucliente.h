#ifndef CLIENTE_H
#define CLIENTE_H


typedef struct Cliente {
    char nome[50];
    char cpf[12];
    char email[100];
    char telefone[15];
    char data_nascimento[11];
    struct Cliente *proximo;
} Cliente;


void print_menu();
void menu_editar();
void cadastrar_cliente(Cliente *c);
void listar_cliente(Cliente *c);
Cliente* buscar_cliente(Cliente *inicio, char *cpf_procurado);
void editar_dados(Cliente *inicio);
Cliente* remover_cliente(Cliente *c);
void menu_remove();

#endif