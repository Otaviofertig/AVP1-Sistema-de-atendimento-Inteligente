#ifndef ARVORE_H
#define ARVORE_H

#include "atendimento.h"

typedef struct NoArvore {
    Atendimento atendimento;
    struct NoArvore *esquerda;
    struct NoArvore *direita;
} NoArvore;

typedef struct {
    NoArvore *raiz;
} Arvore;

void arvore_init(Arvore *a);
int  arvore_inserir(Arvore *a, Atendimento at);
int  arvore_buscar(const Arvore *a, int id, Atendimento *dest);
void arvore_listar_em_ordem(const Arvore *a);
int  arvore_remover(Arvore *a, int id);
void arvore_destruir(Arvore *a);

#endif
