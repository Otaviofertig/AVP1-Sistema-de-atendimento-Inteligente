#ifndef LISTA_H
#define LISTA_H

#include "atendimento.h"

typedef struct NoLista {
    Atendimento atendimento;
    struct NoLista *proximo;
} NoLista;

typedef struct {
    NoLista *cabeca;
    int tamanho;
} Lista;

void lista_init(Lista *l);
int  lista_inserir(Lista *l, Atendimento a);
void lista_listar(const Lista *l);
int  lista_buscar_nome(const Lista *l, const char *nome);
int  lista_buscar_prioridade(const Lista *l, int prioridade);
int  lista_cancelar(Lista *l, int id);
int  lista_atualizar_status(Lista *l, int id, const char *status);
void lista_destruir(Lista *l);
int  lista_copiar_array(const Lista *l, Atendimento *arr, int max);

#endif
