#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "caixa.h"

Carrinho * headcell() {
    Carrinho *head;
    head = malloc(sizeof(Carrinho));
    head->prox = NULL;
    
    return head;
}

void adicionarCarrinho(int codigo_produto, Carrinho *head, Produto *lista) { //Insere no final da lista.
    
    Produto *encontrado = buscar_produto_por_codigo(lista,codigo_produto);
    if (encontrado == NULL) {
        printf("Produto nao encontrado!\n");
        return;
    }
    printf("Resultado:\n");
    imprimir_produto(encontrado);

    Carrinho *aux, *novo = malloc(sizeof (Carrinho));
    if (novo) {
        novo->prod_carrinho = *encontrado;
        novo->prox = NULL;
        if (head->prox == NULL) 
            head->prox = novo;
        else {
            aux = head;
            while(aux->prox)
                aux = aux->prox;
            aux->prox = novo;
        }
    } else
        printf("Erro ao adicionar o produto no carrinho!\n"); //Erro ao alocar memória.
}

void retirarCarrinho (int x, Carrinho *head) {
    Carrinho *p, *q;
    p = head;
    q = head->prox;

    while (q != NULL && q->prod_carrinho.codigo != x) {
        p = q;
        q = q->prox;
    }

    if (q != NULL) {
        p->prox = q->prox;
        free (q);
        printf("Produto retirado do carrinho.\n");
    } else
        printf("Este produto nao esta no seu carrinho.\n");
}

void listar (Carrinho *head) {
    if (head->prox) {
        Carrinho *p;
        int i=1;
        double valor_total = 0;
        for(p = head->prox; p != NULL; p = p->prox) {
            printf(" PRODUTO %d \n", i);
            printf(" NOME : %s \n", p->prod_carrinho.nome);
            printf(" PREÇO : %.2lf \n", p->prod_carrinho.preco);
            printf(" CODIGO : %03d \n", p->prod_carrinho.codigo);
            // printf(" QUANTIDADE : %d \n", p->quantidade);
            printf(" ----------------- \n");
            valor_total += p->prod_carrinho.preco; //* p->quantidade;        
            i++;
        }
        printf("Valor total %.2lf\n", valor_total);
    } else
        printf("Seu carrinho está vazio!\n");
}

void printMenuCarrinho () {
    system("clear"); // No Windows usar system("cls");
    printf("---------- CARRINHO ----------\n");
    printf(" (1) Mostrar produtos do carrinho\n"); 
    printf(" (2) Retirar produto do carrinho\n");
    printf(" (3) Realizar compra\n");
    printf(" (4) Adicionar produto no carrinho\n");
    printf(" (0) Sair\n");
    printf("------------------------------\n");  
    printf("Digite a opção desejada: ");  
}

void telaCompra() {
    system("clear");
    printf("===============================================================================\n");
    printf("**                   MUITO OBRIGADO PELA SUA COMPRA!                         **\n");
    printf("**           Seu pedido ja esta sendo preparado com carinho.                 **\n");
    printf("**                Esperamos ver voce novamente em breve!                     **\n");
    printf("===============================================================================\n");
    for (int i=3; i>0; i--) {
        printf("Voltando para o menu inicial em %d...\n", i);
        sleep(1);
        printf("\x1b[1F"); // Move para o início da linha anterior
        printf("\x1b[2K"); // Limpa a linha inteira
    }
}

void menuCarrinho(Carrinho *head, Produto *estoque) {
    int opcao, aux;

    do {
        printMenuCarrinho();
        scanf("%d", &opcao);
        switch (opcao) {
            case 0:
                break;
            case 1:{
                system("clear");
                listar(head);
                printf("Digite qualquer numero para voltar para o menu: ");
                scanf("%d", &aux);
                break;
            }
            case 2:{
                int codigo;
                system("clear");
                listar(head);
                printf("Digite o codigo do produto que deseja retirar: ");
                scanf("%d", &codigo);
                retirarCarrinho(codigo, head);
                printf("Digite qualquer numero para voltar para o menu: ");
                scanf("%d", &aux);
                break;
            }
            case 3:{
                char resposta;
                system("clear");
                listar(head);
                printf("Deseja realizar a compra? Digite (S) para confirmar: ");
                scanf(" %c", &resposta);
                if (resposta == 'S') {
                    telaCompra();
                    opcao = 0;
                    limparCarrinho(head);
                }
                break;
            }
            case 4:{
                system("clear");
                imprime_lista_produto(estoque);
                printf("Insira o codigo do produto: \n");
                int codigo1;
                scanf("%d", &codigo1);
                adicionarCarrinho(codigo1, head, estoque);
                sleep(2);
                break;
            }
            default:{
                printf("Opção invalida! Por favor, digite novamente.\n");
                sleep(2);
                break;
            }
        }
    } while (opcao != 0);
}

void limparCarrinho (Carrinho *head) {
    Carrinho *atual = head->prox;
    while (atual != NULL) {
        Carrinho *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    head->prox = NULL;
}

void destruir_lista_carrinho(Carrinho *head) {
    Carrinho *atual = head;
    while (atual != NULL) {
        Carrinho *temp = atual;    
        atual = atual->prox;   
        free(temp);               
    }
}