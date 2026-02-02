#ifndef CAIXA_H
#define CAIXA_H

#include "produto.h"

typedef struct carrinho {
    Produto prod_carrinho;
    struct carrinho *prox;
} Carrinho;

Carrinho * headcell();
void adicionarCarrinho(int codigo_produto, Carrinho *head, Produto *lista);//Insere no final da lista.
void retirarCarrinho (int x, Carrinho *head);
void listar (Carrinho *head);
void limparCarrinho (Carrinho *head);

void printMenuCarrinho ();
void telaCompra();
void menuCarrinho(Carrinho *head, Produto *estoque);

void destruir_lista_carrinho(Carrinho *head);
#endif