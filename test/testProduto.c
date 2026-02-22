#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "produto.h"

int main() {
    Produto *cabeca = criar_lista_produto();
    if (cabeca == NULL) return 1;

    Produto lista_base[4] = {
        {"Refri", 0, 15.5, NULL}, 
        {"Suco", 0, 10.1, NULL},
        {"Suco verde", 0, 34.1, NULL},
        {"Maracuja", 0, 10.1, NULL}
    };

    printf("Cadastrando Produtos\n");
    for(int i = 0; i < 4; i++) {
        lista_base[i].codigo = gerar_codigo_produto();
        
        inserir_produto_fim(cabeca, lista_base[i]);
    }

    imprime_lista_produto(cabeca);

    int cod_procurado = 1001; 
    printf("\nBuscando produto %d\n", cod_procurado);
    Produto* achado = buscar_produto_por_codigo(cabeca, cod_procurado);
    
    if(achado) {
        imprimir_produto(achado);        
        printf("Editando preco\n");
        editar_preco_produto(cabeca, cod_procurado, 12.50);
    }
    
    printf("Removendo o primeiro da lista...\n");
    remover_primeiro_da_lista(cabeca);

    printf("Removendo o ultimo da lista...\n");
    remover_ultimo_da_lista(cabeca);

    printf("\nLista Final:\n");
    imprime_lista_produto(cabeca);

    // 8. Limpeza Total
    destruir_lista_produto(&cabeca);

    return 0;
}
