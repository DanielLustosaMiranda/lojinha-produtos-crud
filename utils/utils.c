#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limparConsole() {
#ifdef __linux
  system("clear");
#elif defined(_WIN32)
  system("cls");
#endif
}

void centralizar(char *texto, int largura) {
  int len = strlen(texto);
  int espacos = (largura - len) / 2;

  for (int i = 0; i < espacos; i++) {
    printf(" ");
  }
  printf("%s\n", texto);
}
