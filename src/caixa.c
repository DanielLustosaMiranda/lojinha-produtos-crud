#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto {
    int codigo;
    double preco;
    char nome_produto[20];
} Produto;

typedef struct carrinho {
    Produto prod_carrinho;
    struct carrinho *prox;
} Carrinho;

Carrinho * headcell() {
    Carrinho *head;
    head = malloc(sizeof(Carrinho));
    head->prox = NULL;
    
    return head;
}

void adicionarCarrinho (Produto x, Carrinho *head) { //Insere no final da lista.
    Carrinho *aux, *novo = malloc(sizeof (Carrinho));
    if (novo) {
        novo->prod_carrinho = x;
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
        printf("Este produto não está no seu carrinho.\n");
}

void listar (Carrinho *head) {
    if (head->prox) {
        Carrinho *p;
        int i=1;
        double valor_total = 0;
        for(p = head->prox; p != NULL; p = p->prox) {
            printf(" PRODUTO %d \n", i);
            printf(" NOME : %s \n", p->prod_carrinho.nome_produto);
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

// void realizarCompra () {

// }

void menuCarrinho (Carrinho *head) {
    int opcao=1, aux;
    system("clear");
    printf("---------- CARRINHO ----------\n");
    printf(" (1) Mostrar produtos do carrinho\n"); 
    printf(" (2) Retirar produto do carrinho\n");
    printf(" (3) Realizar compra\n");
    printf(" (4) Sair\n");
    printf("------------------------------\n");    
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);
    while(opcao < 1 || opcao > 4) {
        system("clear");
        printf("---------- CARRINHO ----------\n");
        printf(" (1) Mostrar produtos do carrinho\n"); 
        printf(" (2) Retirar produto do carrinho\n");
        printf(" (3) Realizar compra\n");
        printf(" (4) Sair\n");
        printf("------------------------------\n");
        printf("Opção inexistente! Porfavor, digite novamente: ");
        scanf("%d", &opcao);
    }

    switch (opcao) {
        case 1:
            system("clear");
            listar(head);
            printf("Digite qualquer número para voltar para o menu: ");
            scanf("%d", &aux);
            break;
        case 2:
            int codigo;
            system("clear");
            printf("Digite o código do produto que deseja retirar: ");
            scanf("%d", &codigo);
            retirarCarrinho(codigo, head);
            printf("Digite qualquer número para voltar para o menu: ");
            scanf("%d", &aux);
            break;
        case 3:

        case 4:
            return;
        default:
            break;
    }
    menuCarrinho(head);
}

int main () {
    Carrinho *head = headcell();
    Produto p1, p2, p3, p4;

    strcpy(p1.nome_produto, "Arruela");
    p1.codigo = 105;
    p1.preco = 5.5;

    strcpy(p2.nome_produto, "Chave de Fenda");
    p2.codigo = 112;
    p2.preco = 20.5;

    strcpy(p3.nome_produto, "Parafusadeira");
    p3.codigo = 501;
    p3.preco = 100.99;

    strcpy(p4.nome_produto, "Martelo");
    p4.codigo = 505;
    p4.preco = 101.99;

    adicionarCarrinho(p3, head);
    adicionarCarrinho(p2, head);
    adicionarCarrinho(p4, head);
    menuCarrinho(head);

    return 0;
}
