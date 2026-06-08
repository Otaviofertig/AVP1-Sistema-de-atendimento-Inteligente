/*
 * lista.c
 * Lista encadeada simples usada como histórico de atendimentos.
 * Guarda TODOS os atendimentos cadastrados (abertos, atendidos e cancelados).
 * Inserção sempre no início da lista (operação rápida).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

/* Inicializa a lista vazia */
void lista_init(Lista *l) {
    l->cabeca  = NULL;
    l->tamanho = 0;
}

/* Insere um atendimento no início da lista */
int lista_inserir(Lista *l, Atendimento a) {
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (novo == NULL) return 0;

    novo->atendimento = a;
    novo->proximo     = l->cabeca; /* o novo nó aponta para o antigo início */
    l->cabeca         = novo;      /* o início agora é o novo nó */
    l->tamanho++;
    return 1;
}

/* Imprime todos os atendimentos do histórico */
void lista_listar(const Lista *l) {
    if (l->cabeca == NULL) {
        printf("  Historico vazio.\n");
        return;
    }

    imprimir_cabecalho();
    NoLista *atual = l->cabeca;
    while (atual != NULL) {
        imprimir_atendimento(&atual->atendimento);
        atual = atual->proximo;
    }
    printf("  Total: %d atendimento(s)\n", l->tamanho);
}

/* Busca por trecho do nome do cliente (busca parcial com strstr) */
int lista_buscar_nome(const Lista *l, const char *nome) {
    int encontrados = 0;
    NoLista *atual = l->cabeca;

    while (atual != NULL) {
        /* strstr retorna não-nulo se encontrar o trecho dentro do nome */
        if (strstr(atual->atendimento.cliente, nome) != NULL) {
            if (encontrados == 0) imprimir_cabecalho();
            imprimir_atendimento(&atual->atendimento);
            encontrados++;
        }
        atual = atual->proximo;
    }

    if (encontrados == 0)
        printf("  Nenhum resultado para \"%s\".\n", nome);
    else
        printf("  Encontrados: %d\n", encontrados);

    return encontrados;
}

/* Busca todos os atendimentos com a prioridade informada */
int lista_buscar_prioridade(const Lista *l, int prioridade) {
    int encontrados = 0;
    NoLista *atual = l->cabeca;

    while (atual != NULL) {
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

/* Cancela o atendimento com o ID informado */
int lista_cancelar(Lista *l, int id) {
    NoLista *atual = l->cabeca;
    while (atual != NULL) {
        if (atual->atendimento.id == id) {
            /* Não permite cancelar algo que já foi atendido */
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

/* Atualiza o status de um atendimento pelo ID */
int lista_atualizar_status(Lista *l, int id, const char *status) {
    NoLista *atual = l->cabeca;
    while (atual != NULL) {
        if (atual->atendimento.id == id) {
            strncpy(atual->atendimento.status, status, MAX_STATUS - 1);
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

/* Libera toda a memória da lista */
void lista_destruir(Lista *l) {
    NoLista *atual = l->cabeca;
    while (atual != NULL) {
        NoLista *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista_init(l);
}

/* Copia atendimentos da lista para um vetor (usado pela ordenação) */
int lista_copiar_array(const Lista *l, Atendimento *arr, int max) {
    int i = 0;
    NoLista *atual = l->cabeca;
    while (atual != NULL && i < max) {
        arr[i] = atual->atendimento;
        i++;
        atual = atual->proximo;
    }
    return i;
}
