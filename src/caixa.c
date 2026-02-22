#include "caixa.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

Carrinho *headcell() {
  Carrinho *head;
  head = malloc(sizeof(Carrinho));
  head->prox = NULL;

  return head;
}

void adicionarCarrinho(int codigo_produto, Carrinho *head,
                       Produto *estoque) { // Insere no final da lista.
  Produto *encontrado = buscar_produto_por_codigo(estoque, codigo_produto);
  if (encontrado == NULL) {
    printf("Produto nao encontrado!\n");
    return;
  }
  printf("Resultado:\n");
  imprimir_produto(encontrado);

  Carrinho *aux, *novo = malloc(sizeof(Carrinho));
  if (novo) {
    novo->prod_carrinho = *encontrado;
    novo->prox = NULL;
    if (head->prox == NULL)
      head->prox = novo;
    else {
      aux = head;
      while (aux->prox)
        aux = aux->prox;
      aux->prox = novo;
    }
  } else
    printf("Erro ao adicionar o produto no carrinho!\n"); // Erro ao alocar
                                                          // memória.
}

void retirarCarrinho(int codigo_produto, Carrinho *head) {
  Carrinho *p, *q;
  p = head;
  q = head->prox;

  while (q != NULL && q->prod_carrinho.codigo != codigo_produto) {
    p = q;
    q = q->prox;
  }

  if (q != NULL) {
    p->prox = q->prox;
    free(q);
    printf("Produto retirado do carrinho.\n");
  } else
    printf("Este produto nao esta no seu carrinho.\n");
}

void listar(Carrinho *head) {
  if (head->prox) {
    Carrinho *p;
    int i = 1;
    double valor_total = 0;
    for (p = head->prox; p != NULL; p = p->prox) {
      printf(" PRODUTO %d \n", i);
      printf(" NOME : %s \n", p->prod_carrinho.nome);
      printf(" PREÇO : %.2lf \n", p->prod_carrinho.preco);
      printf(" CODIGO : %03d \n", p->prod_carrinho.codigo);
      printf(" ----------------- \n");
      valor_total += p->prod_carrinho.preco;
      i++;
    }
    printf("Valor total %.2lf\n", valor_total);
  } else
    printf("Seu carrinho está vazio!\n");
}

void printMenuCarrinho(Cliente *cliente_atual) {
  limparConsole();
  printf("---------- MENU DE COMPRA ----------\n");
  centralizar("Olá", 38);
  centralizar(cliente_atual->nome, 38);
  centralizar("seja bem-vindo(a)!", 38);
  printf("1 - Mostrar produtos do carrinho\n");
  printf("2 - Retirar produto do carrinho\n");
  printf("3 - Realizar compra\n");
  printf("4 - Adicionar produto no carrinho\n");
  printf("0 - Sair\n");
  printf("------------------------------\n");
  printf("Digite a opção desejada: ");
}

void telaLogin(Carrinho *head, Produto *estoque, Cliente *inicio) {
  char cpf_busca[12];
  Cliente *cliente_atual;
  limparConsole();
  printf("Por favor, digite o seu CPF para entrar no menu de compra: ");
  scanf(" %[^\n]", cpf_busca);
  cliente_atual = buscar_cliente_por_cpf(inicio, cpf_busca);
  if (cliente_atual)
    menuCarrinho(head, estoque, cliente_atual);
  else {
    printf("CPF não encontrado, retornando para o menu inicial.\n");
    sleep(2);
    return;
  }
}

void telaCompra(Cliente *cliente_atual, Carrinho *head, Produto *estoque) {
  Produto *encontrado;
  Carrinho *p = head->prox;
  while (p != NULL) {
    encontrado = buscar_produto_por_codigo(estoque, p->prod_carrinho.codigo);
    if (encontrado == NULL) {
      printf("Produto nao encontrado\n");
      return;
    }

    if (encontrado->quantidade == 0) {
      printf("Não foi possivel realizar a compra de todos os produtos [%d]! "
             "Não temos estoque o suficiente.\n",
             encontrado->codigo);
    } else {
      encontrado->quantidade--;
    }

    p = p->prox;
  }

  printf("====================================================================="
         "==========\n");
  centralizar(cliente_atual->nome, 81);
  centralizar("MUITO OBRIGADO PELA SUA COMPRA!", 81);
  centralizar("Seu pedido ja esta sendo preparado com carinho.", 81);
  centralizar("Esperamos ver voce novamente em breve!", 81);
  printf("====================================================================="
         "==========\n");

  for (int i = 5; i > 0; i--) {
    printf("Voltando para o menu inicial em %d...\n", i);
    sleep(1);
    printf("\x1b[1F"); // Move para o início da linha anterior
    printf("\x1b[2K"); // Limpa a linha inteira
  }
}

void menuCarrinho(Carrinho *head, Produto *estoque, Cliente *cliente_atual) {
  int opcao, aux;

  do {
    printMenuCarrinho(cliente_atual);
    scanf("%d", &opcao);
    switch (opcao) {
    case 0:
      break;
    case 1: {
      limparConsole();
      listar(head);
      printf("Digite qualquer numero para voltar para o menu: ");
      scanf("%d", &aux);
      break;
    }
    case 2: {
      int codigo;
      limparConsole();
      listar(head);
      printf("Digite o codigo do produto que deseja retirar: ");
      scanf("%d", &codigo);
      retirarCarrinho(codigo, head);
      printf("Digite qualquer numero para voltar para o menu: ");
      scanf("%d", &aux);
      break;
    }
    case 3: {
      char resposta;
      limparConsole();
      listar(head);
      if (head->prox) {
        printf("Deseja realizar a compra? Digite (s) para confirmar: ");
        getchar();
        scanf("%c", &resposta);
        if (resposta == 's') {
          limparConsole();
          telaCompra(cliente_atual, head, estoque);
          opcao = 0;
        }
        break;
      }
      printf("Digite qualquer numero para voltar para o menu: ");
      scanf("%d", &aux);
      break;
    }
    case 4: {
      int codigo;
      limparConsole();
      imprime_lista_produto(estoque);
      printf("Insira o codigo do produto: \n");
      scanf("%d", &codigo);
      adicionarCarrinho(codigo, head, estoque);
      sleep(2);
      break;
    }
    default: {
      printf("Opção invalida! Por favor, digite novamente.\n");
      sleep(2);
      break;
    }
    }
  } while (opcao != 0);
  limparCarrinho(head);
}

void limparCarrinho(Carrinho *head) {
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
