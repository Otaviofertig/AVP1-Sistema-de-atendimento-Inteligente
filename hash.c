/*
 * hash.c
 * RESPONSAVEL: Integrante B
 *
 * Tabela Hash para agrupar e buscar atendimentos por CATEGORIA.
 *
 * Como funciona?
 *   A funcao de hash recebe o nome da categoria (string) e devolve
 *   um numero entre 0 e HASH_TAMANHO-1. Esse numero e o indice do
 *   vetor de buckets onde o atendimento sera guardado.
 *
 *   buckets[0] --> [NoHash] --> [NoHash] --> NULL
 *   buckets[1] --> NULL
 *   buckets[2] --> [NoHash] --> NULL
 *   ...
 *
 *   Quando duas categorias diferentes geram o mesmo indice (colisao),
 *   os nos ficam encadeados no mesmo bucket (lista ligada).
 *
 * Funcao djb2 (ja implementada abaixo):
 *   E um algoritmo classico de hash para strings.
 *   Voce NAO precisa alterar a funcao hash_funcao.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

/*
 * hash_funcao  (funcao auxiliar interna — use static, JA IMPLEMENTADA)
 * Recebe uma string e retorna o indice do bucket (0 a HASH_TAMANHO-1).
 * Algoritmo djb2: multiplica o hash acumulado por 33 e soma o caractere atual.
 * Nao precisa modificar esta funcao.
 */
static unsigned int hash_funcao(const char *str) {
    unsigned int hash = 5381;
    while (*str) {
        hash = ((hash << 5) + hash) + (unsigned char)(*str);
        str++;
    }
    return hash % HASH_TAMANHO;
}

/*
 * hash_init
 * Inicializa todos os buckets como NULL (tabela vazia).
 * Use um for de 0 ate HASH_TAMANHO-1:
 *   h->buckets[i] = NULL;
 */
void hash_init(TabelaHash *h) {
    /* TODO */
}

/*
 * hash_inserir
 * Insere um atendimento na tabela hash.
 * Passos:
 *   1. Calcule o indice: unsigned int idx = hash_funcao(a.categoria);
 *   2. Aloque um novo NoHash com malloc
 *   3. Se malloc falhar, retorne 0
 *   4. Copie o atendimento: novo->atendimento = a
 *   5. Insira no INICIO do bucket (mais rapido):
 *        novo->proximo = h->buckets[idx];
 *        h->buckets[idx] = novo;
 *   6. Retorne 1 (sucesso)
 */
int hash_inserir(TabelaHash *h, Atendimento a) {
    /* TODO */
    return 0;
}

/*
 * hash_buscar_categoria
 * Busca e imprime todos os atendimentos de uma determinada categoria.
 * Passos:
 *   1. Calcule o indice: unsigned int idx = hash_funcao(categoria);
 *   2. Percorra a lista encadeada em h->buckets[idx]
 *   3. Para cada no, compare a categoria com strcmp:
 *        strcmp(atual->atendimento.categoria, categoria) == 0
 *      ATENCAO: strcmp retorna 0 quando as strings sao IGUAIS.
 *   4. Se igual, imprima (use imprimir_cabecalho() apenas no primeiro resultado)
 *   5. Ao final, se nenhum encontrado, informe o usuario
 *
 * Obs: pode haver colisoes no bucket (categorias diferentes no mesmo indice).
 *   Por isso e necessario verificar a categoria com strcmp, nao apenas o indice.
 */
void hash_buscar_categoria(const TabelaHash *h, const char *categoria) {
    /* TODO */
}

/*
 * hash_destruir
 * Libera toda a memoria alocada na tabela hash.
 * Para cada bucket (for de 0 ate HASH_TAMANHO-1):
 *   - Percorra a lista encadeada do bucket
 *   - Para cada no, salve o proximo, faca free no atual
 *   - Ao final, faca h->buckets[i] = NULL
 */
void hash_destruir(TabelaHash *h) {
    /* TODO */
}
