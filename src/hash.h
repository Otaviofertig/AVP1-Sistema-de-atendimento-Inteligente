#ifndef HASH_H
#define HASH_H

#include "atendimento.h"

#define HASH_TAMANHO 31

typedef struct NoHash {
    Atendimento atendimento;
    struct NoHash *proximo;
} NoHash;

typedef struct {
    NoHash *buckets[HASH_TAMANHO];
} TabelaHash;

void hash_init(TabelaHash *h);
int  hash_inserir(TabelaHash *h, Atendimento a);
void hash_buscar_categoria(const TabelaHash *h, const char *categoria);
void hash_destruir(TabelaHash *h);

#endif
