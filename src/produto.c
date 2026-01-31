#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *CODES_FILE = "codes/codes.csv"; // Ajuste o caminho se necessário
const int START_NUM = 999;

int gerar_codigo_produto() {
    FILE *f = fopen(CODES_FILE, "r");
    int lastNum = START_NUM;
    int currentNum;

    if (f != NULL) {
        while (fscanf(f, "%d,", &currentNum) == 1) {
            lastNum = currentNum;
        }
        fclose(f);
    }

    int novoCodigo = lastNum + 1;
    f = fopen(CODES_FILE, "a");
    if (f == NULL) return -1;
    
    fprintf(f, "%d,", novoCodigo);
    fclose(f);
    return novoCodigo;
}

Produto* criar_no_produto(Produto x) {
    Produto* novo = malloc(sizeof(Produto));
    if (novo == NULL) return NULL;

    novo->nome = malloc(strlen(x.nome) + 1);
    if (novo->nome != NULL) {
        strcpy(novo->nome, x.nome);
    }
    novo->codigo = x.codigo;
    novo->preco = x.preco;
    novo->prox = NULL;
    return novo;
}

Produto* criar_produto_por_campo(char *nome, double preco, int codigo){
    Produto* novo = malloc(sizeof(Produto));
    if (novo == NULL) return NULL;

    novo->nome = malloc(strlen(nome) + 1);
    if (novo->nome != NULL) {
        strcpy(novo->nome, nome);
    }
    novo->codigo = codigo;
    novo->preco = preco;
    novo->prox = NULL;
    return novo;
}

Produto* criar_lista_produto() {
    Produto* cabeca = malloc(sizeof(Produto));
    if (cabeca != NULL) {
        cabeca->prox = NULL;
        cabeca->codigo = -1;
        cabeca->preco = -1;
        
        // "0x0'\0'"
        cabeca->nome = malloc(4 * sizeof(char));
        if (cabeca->nome != NULL) {
            strcpy(cabeca->nome, "0x0");
        }
    }
    return cabeca;
}

void destruir_lista_produto(Produto** lista_ref) {
    if (lista_ref == NULL || *lista_ref == NULL) return;
    
    Produto* atual = *lista_ref;
    while (atual != NULL) {
        Produto* proximo = atual->prox;
        free(atual->nome);
        free(atual);
        atual = proximo;
    }
    *lista_ref = NULL;
}

void inserir_produto_fim(Produto* lista_ref, Produto x) {
    Produto* novo = criar_no_produto(x);
    if (novo == NULL) return;

    Produto* atual = lista_ref;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;
}

Produto* buscar_produto_por_codigo(Produto* lista_ref, int codigo) {
    Produto *aux = lista_ref->prox;
    while (aux != NULL) {
        if (aux->codigo == codigo) return aux;
        aux = aux->prox;
    }
    return NULL;
}

Produto* buscar_produto_por_nome(Produto* lista_ref, char* busca) {
    Produto *aux = lista_ref->prox;
    while (aux != NULL) {
        if (strstr(aux->nome, busca) != NULL) return aux;
        aux = aux->prox;
    }
    return NULL;
}

void editar_preco_produto(Produto* lista_ref, int codigo, double novo_preco) {
    Produto* p = buscar_produto_por_codigo(lista_ref, codigo);
    if (p != NULL) {
        p->preco = novo_preco;
        printf("Preco do produto %d atualizado para R$ %.2f.\n", codigo, novo_preco);
    } else {
        printf("Erro: Produto %d nao encontrado.\n", codigo);
    }
}

void remover_produto_especifico(Produto* lista_ref, int codigo) {
    Produto* anterior = lista_ref;
    Produto* atual = lista_ref->prox;

    while (atual != NULL && atual->codigo != codigo) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        anterior->prox = atual->prox;
        free(atual->nome);
        free(atual);
        printf("Produto %d removido.\n", codigo);
    }
}

void remover_primeiro_da_lista(Produto* lista_ref) {
    if (lista_ref == NULL || lista_ref->prox == NULL) return;
    
    Produto *remover = lista_ref->prox;
    lista_ref->prox = remover->prox;
    
    free(remover->nome);
    free(remover);
}

void remover_ultimo_da_lista(Produto* lista_ref) {
    if (lista_ref == NULL || lista_ref->prox == NULL) return;

    Produto *anterior = lista_ref;
    Produto *atual = lista_ref->prox;

    while (atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = NULL;
    free(atual->nome);
    free(atual);
}

void imprimir_produto(Produto * prod) {
    if (prod == NULL) return;
    printf("[%d] %-15s | R$ %7.2f\n", prod->codigo, prod->nome, prod->preco);
}

void imprime_lista_produto(Produto* lista_ref) {
    printf("\n--- LISTA DE PRODUTOS ---\n");
    Produto* aux = lista_ref->prox;
    while (aux != NULL) {
        imprimir_produto(aux);
        aux = aux->prox;
    }
    printf("-------------------------\n");
}