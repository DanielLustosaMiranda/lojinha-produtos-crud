#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menucliente.h"



int main() {
    int entrada;
    Cliente *inicio = NULL;

    do {
        print_menu();
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &entrada);

        switch (entrada) {
            case 1: {
                inicio = novo_cadastro(inicio);
                break;
            }
            case 2: {
                exibir_lista(inicio);
                break;
            }
            case 3: {
                executar_busca(inicio);
                break;
            }
            case 4:
                editar_dados(inicio);
                break;

            case 5:
                inicio = remover_cliente(inicio);
                break; 
                
                
            case 0:
                printf("Saindo do sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (entrada != 0);

   liberar_lista(inicio);

   return 0;
}




