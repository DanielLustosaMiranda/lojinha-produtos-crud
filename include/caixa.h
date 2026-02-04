#ifndef CAIXA_H
#define CAIXA_H

#include "produto.h"
#include "menucliente.h"

typedef struct carrinho {
    Produto prod_carrinho;
    struct carrinho *prox;
} Carrinho;

Carrinho * headcell();
void adicionarCarrinho(int codigo_produto, Carrinho *head, Produto *lista);//Insere no final da lista.
void retirarCarrinho (int x, Carrinho *head);
void listar (Carrinho *head);
void limparCarrinho (Carrinho *head);

void telaLogin(Carrinho *head, Produto *estoque, Cliente *inicio);
void printMenuCarrinho (Cliente *cliente_atual);
void telaCompra(Cliente *cliente_atual);
void menuCarrinho(Carrinho *head, Produto *estoque, Cliente *cliente_atual);

void destruir_lista_carrinho(Carrinho *head);

void centralizar(char *texto, int largura);
#endif