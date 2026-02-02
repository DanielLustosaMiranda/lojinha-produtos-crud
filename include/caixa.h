#include "produto.h"
#ifndef CAIXA_H
#define CAIXA_H

typedef struct carrinho {
    Produto prod_carrinho;
    struct carrinho *prox;
} Carrinho;

Carrinho * headcell();

void adicionarCarrinho (Produto x, Carrinho *head);
void retirarCarrinho (int x, Carrinho *head);
void listar (Carrinho *head);

void printMenuCarrinho ();
void telaCompra();
void menuCarrinho (Carrinho *head);

#endif