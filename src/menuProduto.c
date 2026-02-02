#include "menuProduto.h"
#include "produto.h"

#include <stdio.h>
#include <string.h>

int menu_Produto(){
    int opcao;
    Produto *head = criar_lista_produto();
    Produto lista_base[4] = {
        {"Refri", 1, 15.5, NULL}, 
        {"Suco", 2, 10.1, NULL},
        {"Suco verde", 3, 34.1, NULL},
        {"Maracuja", 4, 10.1, NULL}
    };
    for(int i = 0; i < 4; i++)
        inserir_produto_fim(head, lista_base[i]);
    do{
        opcao = print_menu_produto();
        char codigo;
        
        switch (opcao) {
            case 1:{
                cadastrar_produto(head);
                break;
            }
            case 2:{
                Produto *aux = head;
                imprime_lista_produto(head);
                break;
            }
            case 3:{
                pesquisar_produto(head);
                break;
            }
            case 4:{
                editar_dados(head);
                break;
            }
            case 5:{
                remover_produto(head);
                break;
            }
            case 0:{
                printf("Saindo do sistema\n");
                break;
            }
            default:{
                printf("Opcao invalida!\n");
                break;
            }
        }

    }while(opcao !=0);

    return 0;
}

int print_menu_produto(){
    printf("\n--------------- Cadastro de Produtos ------------------\n");
    printf("1 - Cadastrar novo Produto\n");
    printf("2 - Listar todos os Produtos\n");
    printf("3 - Buscar Produto pelo codigo\n");
    printf("4 - Editar dados de um Produto\n");
    printf("5 - Remover Produto\n");
    printf("0 - Sair\n");
    int resposta;
    scanf("%d", &resposta);
    return resposta;
}

void cadastrar_produto(Produto *inicio){
    char nome_temp[100]; 
    double preco_temp; 
    int codigo_temp;

    printf("Nome do Produto: ");
    scanf(" %[^\n]s", nome_temp);

    printf("Preço: ");
    scanf(" %lf", &preco_temp);
    
    printf("Codigo: ");
    scanf("%d", &codigo_temp);

    Produto *novo_produto = criar_produto_por_campo(nome_temp, preco_temp, codigo_temp);
    inserir_produto_fim(inicio, *novo_produto);
    printf("\nProduto cadastrado com sucesso!\n");
}

void editar_dados(Produto *inicio){
    printf("Digite o codigo do produto\n");
    int codigo = -1;
    scanf("%d",&codigo);

    Produto *encontrado = buscar_produto_por_codigo(inicio,codigo);
    if (encontrado == NULL) {
        printf("Produto nao encontrado!\n");
        return;
    }
    printf("Resultado:\n");
    imprimir_produto(encontrado);
    
    printf("1- Mudar nome:\n");
    printf("2- Mudar codigo:\n");
    printf("3- Mudar preco:\n");
    printf("4- Mudar todas a opções anteriores:\n");
    printf("0- Voltar\n");
    
    int entrada;
    scanf("%d", &entrada);
    switch (entrada) {
        case 1:{
            printf("Mudar nome: ");
            scanf(" %[^\n]", encontrado->nome);
            break;
        }
        case 2:{
            printf("Mudar codigo: ");
            scanf("%d", &encontrado->codigo);
            break;
        }
        case 3:{
            printf("Mudar preco: ");
            scanf("%lf", &encontrado->preco);
        }        
        case 0:{
            printf("Saindo da edicao.\n");
            break;
        }
        default:{
            printf("Opcao invalida!\n");
            break;
        }
    }   
}

void remover_produto(Produto *inicio){
    printf("Digite o codigo do produto\n");
    int codigo;
    scanf("%d",&codigo);
    
    Produto *encontrado = buscar_produto_por_codigo(inicio,codigo);
    int entrada;
    if (encontrado == NULL) {
        printf("Produto nao encontrado!\n");
        return;
    }
    printf("Produto encontrado:\n");
    imprimir_produto(encontrado);
    printf("Tem certeza que quer remove-lo?\n1- sim \n2- nao\n");
    int resposta;
    scanf("%d", &resposta);
    switch (resposta) {
        case 1:{
            remover_produto_especifico(inicio, codigo);
            break;
        }
        case 2:{
            break;
        }
        default:{
            printf("Opção invalida\n");
        }
    }
}

void pesquisar_produto(Produto *inicio){
    printf("Digite o codigo do produto:\n");
    int codigo = -1;
    scanf("%d", &codigo);

    Produto *achado = buscar_produto_por_codigo(inicio, codigo);
    if (achado) {
        printf("Produto encontrado:\n");
        imprimir_produto(achado);
    } else
        printf("\nProduto nao encontrado.\n");
}