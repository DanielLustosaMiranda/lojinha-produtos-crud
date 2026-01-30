#include <stdbool.h>
#include <string.h>
#include "produto.h"

int main(){
    Produto *cabeca = criar_lista_produto();
    Produto lista[10] = {
        {"Refri", "1234", 15.5, NULL}, 
        {"Suco", "1222", 10.1, NULL},
        {"Suco verde", "555", 34.1, NULL}

    };

    adicionar_elemento_produto(cabeca, lista[0]);
    adicionar_elemento_produto(cabeca, lista[1]);
    adicionar_elemento_produto(cabeca, lista[2]);

    Produto* cc = cabeca;

    
    //procure_produto(cabeca, "Suco");
    //procurar_produto_codigo(cabeca, "1222");
    remove_ultimo_produto(cabeca);
    
    imprime_lista_produto(cc);


    destruir_lista_produto(&cabeca);

    return 0;
}