#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct produto {
    char *nome;
    int codigo;
    double preco;
    struct produto *prox;
} Produto;

int gerar_codigo_produto();
Produto* criar_no_produto(Produto x);
Produto* criar_produto_por_campo(char *nome, double preco, int codigo);
Produto* criar_lista_produto();
void destruir_lista_produto(Produto** lista_ref);

void inserir_produto_fim(Produto* lista_ref, Produto x);

void imprimir_produto(Produto* prod);
void imprime_lista_produto(Produto* lista_ref);

Produto* buscar_produto_por_codigo(Produto* lista_ref, int codigo);
Produto* buscar_produto_por_nome(Produto* lista_ref, char* busca);

void editar_preco_produto(Produto* lista_ref, int codigo, double novo_preco);

void remover_primeiro_da_lista(Produto* lista_ref);
void remover_ultimo_da_lista(Produto* lista_ref);
void remover_produto_especifico(Produto* lista_ref, int codigo);

#endif /* PRODUTO_H */