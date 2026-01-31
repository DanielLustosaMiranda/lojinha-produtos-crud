#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct produto {
    char *nome;
    int codigo;
    double preco;
    struct produto *prox;
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
    printf(" (4) Sair\n");
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
    for (int i=5; i>0; i--) {
        printf("Voltando para o menu inicial em %d...\n", i);
        sleep(1);
    }
}

void menuCarrinho (Carrinho *head) {
    int opcao=1, aux;

    do {
        printMenuCarrinho();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                system("clear");
                listar(head);
                printf("Digite qualquer numero para voltar para o menu: ");
                scanf("%d", &aux);
                break;
            case 2:
                int codigo;
                system("clear");
                printf("Digite o codigo do produto que deseja retirar: ");
                scanf("%d", &codigo);
                retirarCarrinho(codigo, head);
                printf("Digite qualquer numero para voltar para o menu: ");
                scanf("%d", &aux);
                break;
            case 3:
                char resposta;
                system("clear");
                listar(head);
                printf("Deseja realizar a compra? (S/N): ");
                scanf(" %c", &resposta);
                if (resposta == 'S') {
                    telaCompra();
                    opcao = 4; 
                }
            case 4:
                break;
            default:
                printf("Opção invalida! Por favor, digite novamente.\n");
                sleep(1.8);
        }
    } while (opcao != 4);
}

int main () {
    Carrinho *head = headcell();

    Produto p1 = {
        .nome = "Arruela",
        .codigo = 105,
        .preco = 5.5
    };

    Produto p2 = {
        .nome = "Chave de Fenda",
        .codigo = 112,
        .preco = 20.5
    };    

    Produto p3= {
        .nome = "Parafusadeira",
        .codigo = 501,
        .preco = 100.99
    };

    Produto p4 = {
        .nome = "Martelo",
        .codigo = 505,
        .preco = 101.99
    };

    adicionarCarrinho(p3, head);
    adicionarCarrinho(p2, head);
    adicionarCarrinho(p4, head);
    menuCarrinho(head);

    return 0;
}
