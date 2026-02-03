#include "menuProduto.h"
#include "menucliente.h"
#include "caixa.h"
#include "produto.h"
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define tam_inicial 4

void limpar_arquivos_de_codigo(){
    const char *CODES_FILE = "codes/codes.csv";
    FILE *arquivo = fopen(CODES_FILE, "w");
    
    if (arquivo != NULL) {
        printf("Conteudo apagado com sucesso!\n");
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
}

void rodar_programa(){
    Carrinho *head_carrinho = headcell();
    Cliente *head_cliente = NULL;
   
    Produto *head_produto = criar_lista_produto();

    Produto lista_base[tam_inicial] = {
        {"Refri", gerar_codigo_produto(), 15, 12.5, NULL}, 
        {"Suco", gerar_codigo_produto(), 10, 10.9, NULL},
        {"Suco verde", gerar_codigo_produto(), 34, 5.5,NULL},
        {"Maracuja", gerar_codigo_produto(), 10, 9.1, NULL}
    };
    for(int i = 0; i < tam_inicial; i++)
        inserir_produto_comeco(head_produto, lista_base[i]);

    int resposta;
    do{
        system("clear");
        printf("1- Cliente\n");
        printf("2- Produto\n");
        printf("3- Carrinho\n");
        printf("0- Sair\n");
    
        scanf("%d", &resposta);
    
        switch (resposta) {
            case 0:{
                break;
            }
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
                printf("Opção inválida!\n");
                sleep(2);
                break;
            }
        }

    }
    while (resposta != 0);

    liberar_lista(head_cliente);
    destruir_lista_produto(&head_produto);
    destruir_lista_carrinho(head_carrinho);
    limpar_arquivos_de_codigo();
}


int main() {
    
    rodar_programa();

    return 0;
}
