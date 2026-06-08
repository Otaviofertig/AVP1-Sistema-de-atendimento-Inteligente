/*
 * fila.c
 *
 * Implementação da fila dinâmica (FIFO — First In, First Out).
 * Responsável por controlar a ORDEM de atendimento dos chamados abertos.
 * Cada novo atendimento cadastrado entra no FIM da fila.
 * Quando o técnico vai atender, retira o atendimento do INÍCIO da fila.
 *
 * Estrutura interna:
 *   - Lista encadeada simples com ponteiros para frente (início) e fim
 *   - Cada nó (NoFila) armazena uma cópia do Atendimento
 *
 * Funções:
 *   fila_init      - Inicializa a fila vazia (frente = fim = NULL, tamanho = 0)
 *   fila_vazia     - Retorna 1 se a fila não possui nenhum elemento
 *   fila_enqueue   - Aloca um novo nó, copia o atendimento e o adiciona ao fim
 *   fila_dequeue   - Remove e retorna o atendimento do início (libera memória do nó)
 *   fila_peek      - Lê o atendimento do início sem removê-lo
 *   fila_listar    - Percorre todos os nós e imprime cada atendimento com posição
 *   fila_destruir  - Libera todos os nós ainda presentes na fila
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void fila_init(Fila *f) {
    /* Define frente = NULL, fim = NULL e tamanho = 0 */
}

int fila_vazia(const Fila *f) {
    /* Retorna 1 se frente == NULL, caso contrário retorna 0 */
}

int fila_enqueue(Fila *f, Atendimento a) {
    /* 1. Aloca um novo NoFila com malloc
     * 2. Copia o atendimento para o novo nó
     * 3. Define proximo do novo nó como NULL
     * 4. Se a fila estiver vazia, frente e fim apontam para o novo nó
     * 5. Caso contrário, encadeia o novo nó após o fim atual e atualiza fim
     * 6. Incrementa tamanho
     * 7. Retorna 1 em sucesso ou 0 se malloc falhou
     */
}

int fila_dequeue(Fila *f, Atendimento *dest) {
    /* 1. Se a fila estiver vazia, retorna 0
     * 2. Salva o ponteiro para o nó da frente
     * 3. Copia o atendimento para *dest
     * 4. Avança frente para o próximo nó
     * 5. Se frente ficou NULL, fim também deve ser NULL
     * 6. Libera a memória do nó removido
     * 7. Decrementa tamanho e retorna 1
     */
}

int fila_peek(const Fila *f, Atendimento *dest) {
    /* 1. Se a fila estiver vazia, retorna 0
     * 2. Copia o atendimento da frente para *dest sem remover
     * 3. Retorna 1
     */
}

void fila_listar(const Fila *f) {
    /* 1. Se a fila estiver vazia, imprime mensagem e retorna
     * 2. Imprime cabeçalho com imprimir_cabecalho()
     * 3. Percorre a lista a partir de frente, imprimindo posição e atendimento
     * 4. Ao final, imprime o total de itens na fila
     */
}

void fila_destruir(Fila *f) {
    /* Percorre todos os nós liberando a memória de cada um,
     * depois reinicializa a fila chamando fila_init()
     */
}
