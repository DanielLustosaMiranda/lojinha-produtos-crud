#include "menuProduto.h"
#include "menucliente.h"
#include "caixa.h"
#include "produto.h"
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>


void rodar_programa(){
    Carrinho *head_carrinho = headcell();
    Cliente *head_cliente = NULL;
   

    Produto *head_produto = criar_lista_produto();

    Produto lista_base[4] = {
        {"Refri", 1, 15.5, NULL}, 
        {"Suco", 2, 10.1, NULL},
        {"Suco verde", 3, 34.1, NULL},
        {"Maracuja", 4, 10.1, NULL}
    };
    for(int i = 0; i < 4; i++)
        inserir_produto_fim(head_produto, lista_base[i]);

    int resposta;
    do{
        system("clear");
        printf("1- Cliente\n");
        printf("2- Produto\n");
        printf("3- Carrinho\n");
        printf("0- Sair\n");
    
        scanf("%d", &resposta);
    
        switch (resposta) {
            case 1:{
                head_cliente = menuCliente(head_cliente);
                break;
            }
            case 2:{
                menu_Produto(head_produto);
                break;
            }
            case 3:{
                menuCarrinho(head_carrinho, head_produto);
                break;
            }
            default:{
                printf("invalida\n");
                break;
            }
        }

    }
    while (resposta != 0);

    liberar_lista(head_cliente);
    destruir_lista_produto(&head_produto);
    destruir_lista_carrinho(head_carrinho);
}

int main() {
    
    rodar_programa();

    return 0;
}
