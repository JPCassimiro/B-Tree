#ifndef B_H
#define B_H
//João Pedro Silva Cassimiro - 2142600
typedef struct no{
  int total;//quantidade atual de chaves
  int* chaves;//info
  struct no** filhos;
  struct no* pai;
  int folha;
} No;

typedef struct arvB{
  No* raiz;
  int ordem;//ou t, define max e min de chaves
} ArvB;

No* criaNo(ArvB* arvore);
ArvB* criaArv(int ordem);
No* divideNo(ArvB* arv, No* no);
void adicionaChaveRecursivo(ArvB* arvore, No* no, No* novo, int chave);
void adicionaChave(ArvB* arv, int chave);
int transbordo(ArvB* arv, No* no);
void adicionaChaveNo(No* no, No* novo, int chave);
void saida(No* raiz, int tab);
#endif
