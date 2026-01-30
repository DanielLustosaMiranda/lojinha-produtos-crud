//    Cadastrar produto (código único, nome e preço);
//    Listar todos os produtos;
//    Buscar produto pelo código;
//    Editar dados de um produto;
//    Remover produto;
#ifndef PRODUTO_H
#define PRODUTO_H

//TO-DO Lista de produtos do carrinho
typedef struct list {
	struct produto *head;
	int size;
}List;

typedef struct produto{
    char nome[100];
    char codigo[100];
    double preco;
    struct produto *prox;
}Produto;

void gerar_codigo_produto(Produto* produto);
void imprimir_produto(Produto * produto);

Produto* criar_lista_produto();
void destruir_lista_produto(Produto** lista_ref);

void adicionar_elemento_produto(Produto* lista_ref, Produto x);
//TO-DO Implementation
void procura_produto_e_remove(Produto* lista_ref, char *busca);
void remove_ultimo_produto(Produto* lista);

void imprime_lista_produto(Produto* lista);
void procure_produto(Produto* lista, char* busca);
Produto * procurar_produto_codigo(Produto* lista, char *codigo);

//TO-DO implementar a editição

#endif /* PRODUTO_H */