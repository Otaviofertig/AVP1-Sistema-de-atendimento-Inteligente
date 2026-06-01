#ifndef FILA_H
#define FILA_H

#include "atendimento.h"

typedef struct NoFila {
    Atendimento atendimento;
    struct NoFila *proximo;
} NoFila;

typedef struct {
    NoFila *frente;
    NoFila *fim;
    int tamanho;
} Fila;

void fila_init(Fila *f);
int  fila_vazia(const Fila *f);
int  fila_enqueue(Fila *f, Atendimento a);
int  fila_dequeue(Fila *f, Atendimento *dest);
int  fila_peek(const Fila *f, Atendimento *dest);
void fila_listar(const Fila *f);
void fila_destruir(Fila *f);

#endif
