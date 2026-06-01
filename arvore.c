#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void arvore_init(Arvore *a) {
    a->raiz = NULL;
}

static NoArvore *novo_no(Atendimento at) {
    NoArvore *no = (NoArvore *)malloc(sizeof(NoArvore));
    if (!no) return NULL;
    no->atendimento = at;
    no->esquerda = NULL;
    no->direita  = NULL;
    return no;
}

static NoArvore *inserir_rec(NoArvore *no, Atendimento at, int *ok) {
    if (!no) {
        *ok = 1;
        return novo_no(at);
    }
    if (at.id < no->atendimento.id)
        no->esquerda = inserir_rec(no->esquerda, at, ok);
    else if (at.id > no->atendimento.id)
        no->direita = inserir_rec(no->direita, at, ok);
    else
        *ok = 0; // ID duplicado
    return no;
}

int arvore_inserir(Arvore *a, Atendimento at) {
    int ok = 0;
    a->raiz = inserir_rec(a->raiz, at, &ok);
    return ok;
}

static int buscar_rec(const NoArvore *no, int id, Atendimento *dest) {
    if (!no) return 0;
    if (id == no->atendimento.id) {
        *dest = no->atendimento;
        return 1;
    }
    if (id < no->atendimento.id)
        return buscar_rec(no->esquerda, id, dest);
    return buscar_rec(no->direita, id, dest);
}

int arvore_buscar(const Arvore *a, int id, Atendimento *dest) {
    return buscar_rec(a->raiz, id, dest);
}

static void em_ordem_rec(const NoArvore *no) {
    if (!no) return;
    em_ordem_rec(no->esquerda);
    imprimir_atendimento(&no->atendimento);
    em_ordem_rec(no->direita);
}

void arvore_listar_em_ordem(const Arvore *a) {
    if (!a->raiz) {
        printf("  Arvore vazia.\n");
        return;
    }
    imprimir_cabecalho();
    em_ordem_rec(a->raiz);
}

// Retorna o no com menor ID na subarvore (usado na remocao)
static NoArvore *minimo(NoArvore *no) {
    while (no->esquerda) no = no->esquerda;
    return no;
}

static NoArvore *remover_rec(NoArvore *no, int id, int *ok) {
    if (!no) return NULL;
    if (id < no->atendimento.id) {
        no->esquerda = remover_rec(no->esquerda, id, ok);
    } else if (id > no->atendimento.id) {
        no->direita = remover_rec(no->direita, id, ok);
    } else {
        *ok = 1;
        if (!no->esquerda) {
            NoArvore *tmp = no->direita;
            free(no);
            return tmp;
        }
        if (!no->direita) {
            NoArvore *tmp = no->esquerda;
            free(no);
            return tmp;
        }
        // Dois filhos: substitui pelo sucessor em-ordem
        NoArvore *suc = minimo(no->direita);
        no->atendimento = suc->atendimento;
        no->direita = remover_rec(no->direita, suc->atendimento.id, ok);
    }
    return no;
}

int arvore_remover(Arvore *a, int id) {
    int ok = 0;
    a->raiz = remover_rec(a->raiz, id, &ok);
    return ok;
}

static void destruir_rec(NoArvore *no) {
    if (!no) return;
    destruir_rec(no->esquerda);
    destruir_rec(no->direita);
    free(no);
}

void arvore_destruir(Arvore *a) {
    destruir_rec(a->raiz);
    a->raiz = NULL;
}
