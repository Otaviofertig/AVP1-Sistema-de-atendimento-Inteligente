#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void fila_init(Fila *f) {
    f->frente = NULL;
    f->fim    = NULL;
    f->tamanho = 0;
}

int fila_vazia(const Fila *f) {
    return f->frente == NULL;
}

int fila_enqueue(Fila *f, Atendimento a) {
    NoFila *novo = (NoFila *)malloc(sizeof(NoFila));
    if (!novo) return 0;

    novo->atendimento = a;
    novo->proximo = NULL;

    if (fila_vazia(f)) {
        f->frente = novo;
    } else {
        f->fim->proximo = novo;
    }
    f->fim = novo;
    f->tamanho++;
    return 1;
}

int fila_dequeue(Fila *f, Atendimento *dest) {
    if (fila_vazia(f)) return 0;

    NoFila *removido = f->frente;
    *dest = removido->atendimento;
    f->frente = removido->proximo;
    if (f->frente == NULL) f->fim = NULL;
    free(removido);
    f->tamanho--;
    return 1;
}

int fila_peek(const Fila *f, Atendimento *dest) {
    if (fila_vazia(f)) return 0;
    *dest = f->frente->atendimento;
    return 1;
}

void fila_listar(const Fila *f) {
    if (fila_vazia(f)) {
        printf("  Fila de espera vazia.\n");
        return;
    }
    printf("  Posicao  ");
    imprimir_cabecalho();
    int pos = 1;
    NoFila *atual = f->frente;
    while (atual) {
        printf("  %-8d ", pos++);
        imprimir_atendimento(&atual->atendimento);
        atual = atual->proximo;
    }
    printf("  Total na fila: %d\n", f->tamanho);
}

void fila_destruir(Fila *f) {
    NoFila *atual = f->frente;
    while (atual) {
        NoFila *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    fila_init(f);
}
