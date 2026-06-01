#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

// Funcao de hash djb2 aplicada sobre a categoria
static unsigned int hash_funcao(const char *str) {
    unsigned int hash = 5381;
    while (*str) {
        hash = ((hash << 5) + hash) + (unsigned char)(*str);
        str++;
    }
    return hash % HASH_TAMANHO;
}

void hash_init(TabelaHash *h) {
    for (int i = 0; i < HASH_TAMANHO; i++)
        h->buckets[i] = NULL;
}

int hash_inserir(TabelaHash *h, Atendimento a) {
    unsigned int idx = hash_funcao(a.categoria);
    NoHash *novo = (NoHash *)malloc(sizeof(NoHash));
    if (!novo) return 0;
    novo->atendimento = a;
    novo->proximo = h->buckets[idx];
    h->buckets[idx] = novo;
    return 1;
}

void hash_buscar_categoria(const TabelaHash *h, const char *categoria) {
    unsigned int idx = hash_funcao(categoria);
    int encontrados = 0;
    NoHash *atual = h->buckets[idx];
    while (atual) {
        if (strcmp(atual->atendimento.categoria, categoria) == 0) {
            if (encontrados == 0) imprimir_cabecalho();
            imprimir_atendimento(&atual->atendimento);
            encontrados++;
        }
        atual = atual->proximo;
    }
    if (encontrados == 0)
        printf("  Nenhum atendimento encontrado na categoria \"%s\".\n", categoria);
    else
        printf("  Encontrados: %d\n", encontrados);
}

void hash_destruir(TabelaHash *h) {
    for (int i = 0; i < HASH_TAMANHO; i++) {
        NoHash *atual = h->buckets[i];
        while (atual) {
            NoHash *prox = atual->proximo;
            free(atual);
            atual = prox;
        }
        h->buckets[i] = NULL;
    }
}
