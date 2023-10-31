#include "b.h"
#include <stdio.h>
//João Pedro Silva Cassimiro - 2142600
int main(void) {
  ArvB* a = criaArv(2);
  adicionaChave(a,33);
  adicionaChave(a,55);
  adicionaChave(a,66);
  adicionaChave(a,99);
  saida(a->raiz,0);
  return 0;
}