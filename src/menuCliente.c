#include "menuCliente.h"
#include "cliente.h"
#include <stdio.h>

int print_menu_cliente() {
  int opcao;
  printf("\n--- GERENCIAMENTO DE CLIENTE ---\n");
  printf("1 - Cadastrar novo cliente\n");
  printf("2 - Listar todos os clientes\n");
  printf("3 - Buscar cliente pelo CPF\n");
  printf("4 - Editar dados do cliente\n");
  printf("5 - Remover cliente\n");
  printf("0 - Sair\n");
  printf("Escolha: ");
  scanf("%d", &opcao);
  return opcao;
}

void cadastrar_cliente_menu(Cliente *inicio) {
  char nome[50], cpf[12], email[100], telefone[15], data[11];

  printf("Nome: ");
  scanf(" %[^\n]", nome);
  printf("CPF: ");
  scanf("%s", cpf);
  printf("Email: ");
  scanf("%s", email);
  printf("Telefone: ");
  scanf("%s", telefone);
  printf("Data Nasc. (DD/MM/AAAA): ");
  scanf("%s", data);

  Cliente *novo = criar_cliente_por_campo(nome, cpf, email, telefone, data);
  inserir_cliente_fim(inicio, *novo);
  printf("Cliente cadastrado!\n");
}

void listar_clientes_menu(Cliente *inicio) {
  Cliente *aux = inicio->proximo;
  if (!aux) {
    printf("Nenhum cliente cadastrado.\n");
    return;
  }
  while (aux) {
    imprimir_cliente(aux);
    aux = aux->proximo;
  }
}

int menu_cliente(Cliente *inicio) {
  int opcao;
  do {
    opcao = print_menu_cliente();
    switch (opcao) {
    case 1:
      cadastrar_cliente_menu(inicio);
      break;
    case 2:
      listar_clientes_menu(inicio);
      break;
    case 3: {
      char cpf[12];
      printf("Digite o CPF: ");
      scanf("%s", cpf);
      Cliente *c = buscar_cliente_por_cpf(inicio, cpf);
      if (c)
        imprimir_cliente(c);
      else
        printf("Cliente nao encontrado.\n");
      break;
    }
    case 4: {
      char cpf[12];
      printf("CPF do cliente: ");
      scanf("%s", cpf);
      Cliente *c = buscar_cliente_por_cpf(inicio, cpf);
      if (!c) {
        printf("Cliente nao encontrado.\n");
        break;
      }

      int campo;
      char valor[100];
      do {
        printf("1-Nome 2-Email 3-Telefone 4-Data Nasc 0-Sair\n");
        scanf("%d", &campo);
        if (campo >= 1 && campo <= 4) {
          printf("Novo valor: ");
          scanf(" %[^\n]", valor);
          switch (campo) {
          case 1:
            editar_nome_cliente(inicio, cpf, valor);
            break;
          case 2:
            editar_email_cliente(inicio, cpf, valor);
            break;
          case 3:
            editar_telefone_cliente(inicio, cpf, valor);
            break;
          case 4:
            editar_data_nascimento_cliente(inicio, cpf, valor);
            break;
          }
          printf("Atualizado!\n");
        }
      } while (campo != 0);
      break;
    }
    case 5: {
      char cpf[12];
      printf("CPF do cliente a remover: ");
      scanf("%s", cpf);
      remover_cliente_especifico(inicio, cpf);
      break;
    }
    case 0:
      printf("Saindo...\n");
      break;
    default:
      printf("Opcao invalida!\n");
      break;
    }
  } while (opcao != 0);

  return 0;
}
