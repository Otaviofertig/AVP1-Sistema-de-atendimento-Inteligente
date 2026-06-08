/*
 * arvore.c
 * Árvore Binária de Busca (BST) organizada pelo ID do atendimento.
 *
 * Por que usar árvore para buscar por ID?
 *   Na lista, buscar um ID exige olhar nó por nó até encontrar (lento).
 *   Na árvore, a cada passo eliminamos metade dos nós restantes,
 *   chegando ao resultado muito mais rápido.
 *
 * Regra da BST:
 *   - IDs menores ficam à ESQUERDA
 *   - IDs maiores ficam à DIREITA
 */

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

/* Inicializa a árvore vazia */
void arvore_init(Arvore *a) {
    a->raiz = NULL;
}

/* Cria e retorna um novo nó */
static NoArvore *criar_no(Atendimento at) {
    NoArvore *no = (NoArvore *)malloc(sizeof(NoArvore));
    if (no == NULL) return NULL;
    no->atendimento = at;
    no->esquerda    = NULL;
    no->direita     = NULL;
    return no;
}

/* Função recursiva de inserção */
static NoArvore *inserir_rec(NoArvore *no, Atendimento at) {
    if (no == NULL) {
        return criar_no(at); /* chegou no lugar certo, cria o nó */
    }
    if (at.id < no->atendimento.id) {
        no->esquerda = inserir_rec(no->esquerda, at);
    } else if (at.id > no->atendimento.id) {
        no->direita = inserir_rec(no->direita, at);
    }
    /* se id == id, não insere (ID duplicado) */
    return no;
}

/* Insere um atendimento na árvore */
int arvore_inserir(Arvore *a, Atendimento at) {
    a->raiz = inserir_rec(a->raiz, at);
    return 1;
}

/* Função recursiva de busca */
static int buscar_rec(const NoArvore *no, int id, Atendimento *dest) {
    if (no == NULL) return 0; /* não encontrou */

    if (id == no->atendimento.id) {
        *dest = no->atendimento; /* encontrou! */
        return 1;
    }
    if (id < no->atendimento.id) {
        return buscar_rec(no->esquerda, id, dest);
    }
    return buscar_rec(no->direita, id, dest);
}

/* Busca um atendimento pelo ID */
int arvore_buscar(const Arvore *a, int id, Atendimento *dest) {
    return buscar_rec(a->raiz, id, dest);
}

/* Percurso em-ordem: imprime os nós em ordem crescente de ID */
static void em_ordem_rec(const NoArvore *no) {
    if (no == NULL) return;
    em_ordem_rec(no->esquerda);
    imprimir_atendimento(&no->atendimento);
    em_ordem_rec(no->direita);
}

void arvore_listar_em_ordem(const Arvore *a) {
    if (a->raiz == NULL) {
        printf("  Arvore vazia.\n");
        return;
    }
    imprimir_cabecalho();
    em_ordem_rec(a->raiz);
}

/* Encontra o nó com menor ID em uma sub-árvore (o mais à esquerda) */
static NoArvore *encontrar_minimo(NoArvore *no) {
    while (no->esquerda != NULL) {
        no = no->esquerda;
    }
    return no;
}

/* Função recursiva de remoção */
static NoArvore *remover_rec(NoArvore *no, int id, int *removeu) {
    if (no == NULL) return NULL;

    if (id < no->atendimento.id) {
        no->esquerda = remover_rec(no->esquerda, id, removeu);
    } else if (id > no->atendimento.id) {
        no->direita  = remover_rec(no->direita,  id, removeu);
    } else {
        *removeu = 1;

        if (no->esquerda == NULL) {
            /* Caso 1: sem filho esquerdo */
            NoArvore *tmp = no->direita;
            free(no);
            return tmp;
        }
        if (no->direita == NULL) {
            /* Caso 2: sem filho direito */
            NoArvore *tmp = no->esquerda;
            free(no);
            return tmp;
        }
        /* Caso 3: dois filhos — substitui pelo menor da sub-árvore direita */
        NoArvore *suc = encontrar_minimo(no->direita);
        no->atendimento = suc->atendimento;
        no->direita = remover_rec(no->direita, suc->atendimento.id, removeu);
    }
    return no;
}

/* Remove um nó da árvore pelo ID */
int arvore_remover(Arvore *a, int id) {
    int removeu = 0;
    a->raiz = remover_rec(a->raiz, id, &removeu);
    return removeu;
}

/* Função recursiva que libera memória (filhos antes do pai) */
static void destruir_rec(NoArvore *no) {
    if (no == NULL) return;
    destruir_rec(no->esquerda);
    destruir_rec(no->direita);
    free(no);
}

/* Libera toda a memória da árvore */
void arvore_destruir(Arvore *a) {
    destruir_rec(a->raiz);
    a->raiz = NULL;
}
