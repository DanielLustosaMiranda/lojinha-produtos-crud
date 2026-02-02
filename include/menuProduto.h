#ifndef MENUCLIENTE_H
#define MENUCLIENTE_H

#include "produto.h"

int print_menu_produto();
void menu_editar_produto();
void main_produto();

void cadastrar_produto(Produto *inicio);

void listar_produto(Produto *p);
void pesquisar_produto(Produto *inicio);

void editar_dados_produto(Produto *inicio);
void remover_produto(Produto *inicio);
int menu_Produto(Produto *estoque);

#endif