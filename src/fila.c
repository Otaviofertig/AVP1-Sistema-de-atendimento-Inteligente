/*
 * fila.c
 * Fila dinâmica (FIFO): o primeiro a entrar é o primeiro a ser atendido.
 * Cada atendimento cadastrado entra no FIM da fila.
 * Quando alguém é atendido, sai do INÍCIO da fila.
 */

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/* Inicializa a fila vazia */
void fila_init(Fila *f) {
    f->frente  = NULL;
    f->fim     = NULL;
    f->tamanho = 0;
}

/* Retorna 1 se a fila não tem nenhum elemento */
int fila_vazia(const Fila *f) {
    return f->frente == NULL;
}

/* Adiciona um atendimento no fim da fila */
int fila_enqueue(Fila *f, Atendimento a) {
    NoFila *novo = (NoFila *)malloc(sizeof(NoFila));
    if (novo == NULL) return 0;

    novo->atendimento = a;
    novo->proximo     = NULL;

    if (fila_vazia(f)) {
        /* Se a fila estava vazia, frente e fim apontam para o mesmo nó */
        f->frente = novo;
    } else {
        /* Liga o último nó ao novo */
        f->fim->proximo = novo;
    }
    f->fim = novo;
    f->tamanho++;
    return 1;
}

/* Remove e retorna o atendimento do início da fila */
int fila_dequeue(Fila *f, Atendimento *dest) {
    if (fila_vazia(f)) return 0;

    NoFila *removido = f->frente;
    *dest = removido->atendimento;
    f->frente = removido->proximo;

    if (f->frente == NULL) {
        f->fim = NULL; /* a fila ficou vazia */
    }

    free(removido);
    f->tamanho--;
    return 1;
}

/* Lê o primeiro da fila sem remover */
int fila_peek(const Fila *f, Atendimento *dest) {
    if (fila_vazia(f)) return 0;
    *dest = f->frente->atendimento;
    return 1;
}

/* Lista todos os atendimentos da fila com sua posição */
void fila_listar(const Fila *f) {
    if (fila_vazia(f)) {
        printf("  Fila de espera vazia.\n");
        return;
    }

    printf("  Pos  ");
    imprimir_cabecalho();

    int pos = 1;
    NoFila *atual = f->frente;
    while (atual != NULL) {
        printf("  %-4d ", pos);
        imprimir_atendimento(&atual->atendimento);
        pos++;
        atual = atual->proximo;
    }
    printf("  Total na fila: %d\n", f->tamanho);
}

/* Libera toda a memória da fila */
void fila_destruir(Fila *f) {
    NoFila *atual = f->frente;
    while (atual != NULL) {
        NoFila *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    fila_init(f);
}
