#ifndef MENUCLIENTE_H
#define MENUCLIENTE_H

#include "cliente.h"

int print_menu_cliente();
void menu_editar_cliente();
void main_cliente();

void cadastrar_cliente(Cliente *inicio);

void listar_cliente(Cliente *p);
void pesquisar_cliente(Cliente *inicio);

void editar_dados_cliente(Cliente *inicio);
void remover_cliente(Cliente *inicio);
int menu_cliente(Cliente *inicio);

#endif /* MENUCLIENTE_H */
