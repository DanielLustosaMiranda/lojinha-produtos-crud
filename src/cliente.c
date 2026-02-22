#include "cliente.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Cliente *criar_no_cliente(Cliente c) {
  Cliente *novo = malloc(sizeof(Cliente));
  if (!novo)
    return NULL;

  strcpy(novo->nome, c.nome);
  strcpy(novo->cpf, c.cpf);
  strcpy(novo->email, c.email);
  strcpy(novo->telefone, c.telefone);
  strcpy(novo->data_nascimento, c.data_nascimento);
  novo->proximo = NULL;
  return novo;
}

Cliente *criar_cliente_por_campo(const char *nome, const char *cpf,
                                 const char *email, const char *telefone,
                                 const char *data_nascimento) {
  Cliente temp;
  strncpy(temp.nome, nome, sizeof(temp.nome));
  strncpy(temp.cpf, cpf, sizeof(temp.cpf));
  strncpy(temp.email, email, sizeof(temp.email));
  strncpy(temp.telefone, telefone, sizeof(temp.telefone));
  strncpy(temp.data_nascimento, data_nascimento, sizeof(temp.data_nascimento));
  return criar_no_cliente(temp);
}

Cliente *criar_lista_cliente() {
  Cliente *cabeca = malloc(sizeof(Cliente));
  if (!cabeca)
    return NULL;
  cabeca->proximo = NULL;

  strcpy(cabeca->nome, "0x0");
  strcpy(cabeca->cpf, "");
  strcpy(cabeca->email, "");
  strcpy(cabeca->telefone, "");
  strcpy(cabeca->data_nascimento, "");

  return cabeca;
}

void destruir_lista_cliente(Cliente **lista_ref) {
  if (!lista_ref || !*lista_ref)
    return;
  Cliente *atual = *lista_ref;
  while (atual) {
    Cliente *temp = atual->proximo;
    free(atual);
    atual = temp;
  }
  *lista_ref = NULL;
}

void inserir_cliente_fim(Cliente *lista_ref, Cliente c) {
  Cliente *novo = criar_no_cliente(c);
  if (!novo)
    return;

  Cliente *atual = lista_ref;
  while (atual->proximo)
    atual = atual->proximo;

  atual->proximo = novo;
}

void inserir_cliente_comeco(Cliente *lista_ref, Cliente c) {
  Cliente *novo = criar_no_cliente(c);
  if (!novo)
    return;

  novo->proximo = lista_ref->proximo;
  lista_ref->proximo = novo;
}

void imprimir_cliente(Cliente *c) {
  if (!c)
    return;

  printf("\n==============================================\n");
  printf("Nome: %s\n", c->nome);
  printf("CPF: %s\n", c->cpf);
  printf("Email: %s\n", c->email);
  printf("Telefone: %s\n", c->telefone);
  printf("Data de Nascimento: %s\n", c->data_nascimento);
  printf("==============================================\n");
}

Cliente *buscar_cliente_por_cpf(Cliente *lista_ref, const char *cpf) {
  Cliente *aux = lista_ref->proximo;
  while (aux) {
    if (strcmp(aux->cpf, cpf) == 0)
      return aux;
    aux = aux->proximo;
  }
  return NULL;
}

Cliente *buscar_cliente_por_nome(Cliente *lista_ref, const char *nome) {
  Cliente *aux = lista_ref->proximo;
  while (aux) {
    if (strstr(aux->nome, nome))
      return aux;
    aux = aux->proximo;
  }
  return NULL;
}

void editar_nome_cliente(Cliente *lista_ref, const char *cpf,
                         const char *novo_nome) {
  Cliente *c = buscar_cliente_por_cpf(lista_ref, cpf);
  if (c)
    strcpy(c->nome, novo_nome);
}

void editar_email_cliente(Cliente *lista_ref, const char *cpf,
                          const char *novo_email) {
  Cliente *c = buscar_cliente_por_cpf(lista_ref, cpf);
  if (c)
    strcpy(c->email, novo_email);
}

void editar_telefone_cliente(Cliente *lista_ref, const char *cpf,
                             const char *novo_telefone) {
  Cliente *c = buscar_cliente_por_cpf(lista_ref, cpf);
  if (c)
    strcpy(c->telefone, novo_telefone);
}

void editar_data_nascimento_cliente(Cliente *lista_ref, const char *cpf,
                                    const char *nova_data) {
  Cliente *c = buscar_cliente_por_cpf(lista_ref, cpf);
  if (c)
    strcpy(c->data_nascimento, nova_data);
}

bool verificar_cpf_existente(Cliente *lista_ref, const char *cpf) {
  return buscar_cliente_por_cpf(lista_ref, cpf) != NULL;
}

void remover_primeiro_da_lista_cliente(Cliente *lista_ref) {
  if (!lista_ref || !lista_ref->proximo)
    return;
  Cliente *remover = lista_ref->proximo;
  lista_ref->proximo = remover->proximo;
  free(remover);
}

void remover_ultimo_da_lista_cliente(Cliente *lista_ref) {
  if (!lista_ref || !lista_ref->proximo)
    return;

  Cliente *anterior = lista_ref;
  Cliente *atual = lista_ref->proximo;
  while (atual->proximo) {
    anterior = atual;
    atual = atual->proximo;
  }

  anterior->proximo = NULL;
  free(atual);
}

void remover_cliente_especifico(Cliente *lista_ref, const char *cpf) {
  Cliente *anterior = lista_ref;
  Cliente *atual = lista_ref->proximo;

  while (atual && strcmp(atual->cpf, cpf) != 0) {
    anterior = atual;
    atual = atual->proximo;
  }

  if (!atual)
    return;

  anterior->proximo = atual->proximo;
  free(atual);
}
