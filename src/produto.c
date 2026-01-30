#include <produto.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gerar_codigo_produto(Produto* produto);

void imprimir_produto(Produto * produto){
    printf("Nome: %s\n", produto->nome);
    printf("Preco: R$%.2f\n", produto->preco);
    printf("Codigo: %s\n\n", produto->codigo);
}

Produto* criar_lista_produto() {
    Produto* novo = malloc(sizeof(Produto));
    if (novo != NULL) {
        novo->prox = NULL;
        strcpy(novo->nome, "0x0");
        novo->preco = -1;
    }
    return novo;
}

void destruir_lista_produto(Produto** lista_ref) {
    Produto* atual = *lista_ref;
    while (atual != NULL) {
        Produto* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    *lista_ref = NULL;
}

void adicionar_elemento_produto(Produto* lista_ref, Produto x) {
    Produto* novo = malloc(sizeof(Produto));
    if (novo == NULL) return;

    //TO-DO copiar corretamente o elemento
    *novo = x; 
    novo->prox = lista_ref->prox;
    lista_ref->prox = novo;
}

//TO-DO Implementation
void procura_produto_e_remove(Produto* lista_ref, char *busca);

void remove_ultimo_produto(Produto* lista) {
    if (lista == NULL || lista->prox == NULL) return;

    Produto *anterior = lista;
    Produto *atual = lista->prox;

    while (atual->prox != NULL){
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = NULL;
    free(atual);
}

void imprime_lista_produto(Produto* lista){
    Produto* aux;
    for(aux = lista->prox; aux != NULL; aux = aux->prox){
        imprimir_produto(aux);
    }
}

void procure_produto(Produto* lista, char* busca){
    Produto*aux;
    printf("Opcoes achadas:\n");
    for(aux = lista->prox; aux != NULL; aux = aux->prox){
        char* result = strstr(aux->nome, busca);

        if (result) imprimir_produto(aux);
    }
}

Produto * procurar_produto_codigo(Produto* lista, char *codigo){
    Produto *aux = lista->prox;
    while (aux != NULL) {
        if (strcmp(aux->codigo, codigo) == 0) {
            printf("achei %s\n", aux->nome);
            return aux;
        }
        aux = aux->prox;
    }
    printf("nao achei\n");
    return aux;
}