#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdbool.h>

typedef struct Cliente {
  char nome[50];
  char cpf[12];
  char email[100];
  char telefone[15];
  char data_nascimento[11];
  struct Cliente *proximo;
} Cliente;

Cliente *criar_no_cliente(Cliente c);
Cliente *criar_cliente_por_campo(const char *nome, const char *cpf,
                                 const char *email, const char *telefone,
                                 const char *data_nascimento);
Cliente *criar_lista_cliente();
void destruir_lista_cliente(Cliente **lista_ref);

void inserir_cliente_fim(Cliente *lista_ref, Cliente c);
void inserir_cliente_comeco(Cliente *lista_ref, Cliente c);

void imprimir_cliente(Cliente *c);
void imprime_lista_cliente(Cliente *lista_ref);

Cliente *buscar_cliente_por_cpf(Cliente *lista_ref, const char *cpf);
Cliente *buscar_cliente_por_nome(Cliente *lista_ref, const char *nome);

void editar_nome_cliente(Cliente *lista_ref, const char *cpf,
                         const char *novo_nome);
void editar_email_cliente(Cliente *lista_ref, const char *cpf,
                          const char *novo_email);
void editar_telefone_cliente(Cliente *lista_ref, const char *cpf,
                             const char *novo_telefone);
void editar_data_nascimento_cliente(Cliente *lista_ref, const char *cpf,
                                    const char *nova_data);
bool verificar_cpf_existente(Cliente *lista_ref, const char *cpf);
void remover_primeiro_da_lista_cliente(Cliente *lista_ref);
void remover_ultimo_da_lista_cliente(Cliente *lista_ref);
void remover_cliente_especifico(Cliente *lista_ref, const char *cpf);
#endif /* CLIENTE_H */
