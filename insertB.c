#include "b.h"
#include <stdio.h>
#include <stdlib.h>
//João Pedro Silva Cassimiro - 2142600
No* criaNo(ArvB* arvore){
  int max = arvore->ordem * 2;
  No* no = malloc(sizeof(No));
  no->pai = NULL;
  no->chaves = malloc(sizeof(int) * (max + 1));//2t + 1 chaves
  no->filhos = malloc(sizeof(No) * (max + 2));//chaves + 1 filhos
  no->total = 0;
  no->folha = 1;
  for(int  i = 0;i < max + 1;i++){
    no->filhos[i] = NULL;
  }
  return no;
}

ArvB* criaArv(int ordem){
  ArvB* a = malloc(sizeof(ArvB));
  a->ordem = ordem;
  a->raiz = criaNo(a);
  return a;
}

No* localizaNo(ArvB* arv, int chave){
  No* atual = arv->raiz;
  while (!atual->folha) {
      int i = 0;
      while (i < atual->total && chave > atual->chaves[i]) {
          i++;
      }
      atual = atual->filhos[i];
  }
  return atual;
}

No* divideNo(ArvB* arv, No* no){
  int meio = no->total /2;
  No* novo = criaNo(arv);
  novo->pai = no->pai;

  for(int i = meio + 1; i < no->total; i++){
    novo->filhos[novo->total] = no->filhos[i];
    novo->chaves[novo->total] = no->chaves[i];
    if(novo->filhos[novo->total] != NULL){
      novo->filhos[novo->total]->pai = novo;
    }
    novo->total++;
  }
  novo->filhos[novo->total] = no->filhos[no->total];
  if(novo->filhos[novo->total] != NULL){
    novo->filhos[novo->total]->pai = novo;
  }
  no->total = meio;
  return novo;
}

int transbordo(ArvB* arv, No* no){
  int max = arv->ordem * 2;
  if(no->total < max){
    return 0;
  }else{
    return 1;
  }
}

void adicionaChaveNo(No* no, No* novo, int chave){
  int i = no->total - 1;
  while (i >= 0 && chave < no->chaves[i]) {
      no->chaves[i + 1] = no->chaves[i];
      no->filhos[i + 2] = no->filhos[i + 1];
      i--;
  }
  no->chaves[i + 1] = chave;
  no->filhos[i + 2] = novo;
  if (novo != NULL) {
      novo->pai = no;
  }
  no->total++;
}

void adicionaChaveRecursivo(ArvB* arvore, No* no, No* novo, int chave){ 
  adicionaChaveNo(no, novo, chave);
  if(transbordo(arvore, no)){
    int promovido = no->chaves[arvore->ordem];
    No* novo = divideNo(arvore, no);
    if(no->pai == NULL) {
      No* pai = criaNo(arvore);
      pai->filhos[0] = no;
      adicionaChaveNo(pai, novo, promovido);
      no->pai = pai; 
      novo->pai = pai;
      arvore->raiz = pai;
      pai->folha = 0;
    }else{
      adicionaChaveRecursivo(arvore, no->pai, novo, promovido);
    }
  }
}

void adicionaChave(ArvB* arv, int chave){
  No* no = localizaNo(arv, chave);
  adicionaChaveRecursivo(arv, no, NULL, chave);
}

void saida(No* raiz, int tabs) {
    if (raiz != NULL) {
        int i;
        for (i = 0; i < raiz->total; i++) {
              saida(raiz->filhos[i], tabs + 1);
            for (int j = 0; j < tabs; j++) {
                printf("\t");
            }
            printf("%d\n", raiz->chaves[i]);
        }
          saida(raiz->filhos[i], tabs + 1);
    }
}