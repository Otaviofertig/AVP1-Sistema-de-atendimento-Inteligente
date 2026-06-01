#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void lista_init(Lista *l) {
    l->cabeca = NULL;
    l->tamanho = 0;
}

int lista_inserir(Lista *l, Atendimento a) {
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (!novo) return 0;

    novo->atendimento = a;
    novo->proximo = l->cabeca;
    l->cabeca = novo;
    l->tamanho++;
    return 1;
}

void lista_listar(const Lista *l) {
    if (!l->cabeca) {
        printf("  Historico vazio.\n");
        return;
    }
    imprimir_cabecalho();
    NoLista *atual = l->cabeca;
    while (atual) {
        imprimir_atendimento(&atual->atendimento);
        atual = atual->proximo;
    }
    printf("  Total de registros: %d\n", l->tamanho);
}

int lista_buscar_nome(const Lista *l, const char *nome) {
    int encontrados = 0;
    NoLista *atual = l->cabeca;
    while (atual) {
        if (strstr(atual->atendimento.cliente, nome) != NULL) {
            if (encontrados == 0) imprimir_cabecalho();
            imprimir_atendimento(&atual->atendimento);
            encontrados++;
        }
        atual = atual->proximo;
    }
    if (encontrados == 0) printf("  Nenhum atendimento encontrado para \"%s\".\n", nome);
    else printf("  Encontrados: %d\n", encontrados);
    return encontrados;
}

int lista_buscar_prioridade(const Lista *l, int prioridade) {
    int encontrados = 0;
    NoLista *atual = l->cabeca;
    while (atual) {
        if (atual->atendimento.prioridade == prioridade) {
            if (encontrados == 0) imprimir_cabecalho();
            imprimir_atendimento(&atual->atendimento);
            encontrados++;
        }
        atual = atual->proximo;
    }
    if (encontrados == 0)
        printf("  Nenhum atendimento com prioridade %s.\n", prioridade_label(prioridade));
    else
        printf("  Encontrados: %d\n", encontrados);
    return encontrados;
}

int lista_cancelar(Lista *l, int id) {
    NoLista *atual = l->cabeca;
    while (atual) {
        if (atual->atendimento.id == id) {
            if (strcmp(atual->atendimento.status, "atendido") == 0) {
                printf("  Atendimento #%d ja foi atendido e nao pode ser cancelado.\n", id);
                return 0;
            }
            strncpy(atual->atendimento.status, "cancelado", MAX_STATUS - 1);
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

int lista_atualizar_status(Lista *l, int id, const char *status) {
    NoLista *atual = l->cabeca;
    while (atual) {
        if (atual->atendimento.id == id) {
            strncpy(atual->atendimento.status, status, MAX_STATUS - 1);
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

void lista_destruir(Lista *l) {
    NoLista *atual = l->cabeca;
    while (atual) {
        NoLista *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    lista_init(l);
}

int lista_copiar_array(const Lista *l, Atendimento *arr, int max) {
    int i = 0;
    NoLista *atual = l->cabeca;
    while (atual && i < max) {
        arr[i++] = atual->atendimento;
        atual = atual->proximo;
    }
    return i;
}
