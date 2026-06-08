/*
 * lista.c
 *
 * Implementação da lista encadeada simples usada como HISTÓRICO de atendimentos.
 * Diferente da fila (que controla a ordem de espera), a lista guarda TODOS os
 * atendimentos já cadastrados — inclusive os já atendidos e cancelados.
 * Inserção é feita no início da lista (O(1)).
 *
 * Funções:
 *   lista_init             - Inicializa a lista vazia (cabeca = NULL, tamanho = 0)
 *   lista_inserir          - Aloca novo nó e o insere no início da lista
 *   lista_listar           - Percorre e imprime todos os atendimentos do histórico
 *   lista_buscar_nome      - Busca sequencial por trecho do nome do cliente (strstr)
 *                            Imprime todos os registros que contêm o texto buscado
 *   lista_buscar_prioridade- Busca sequencial: imprime todos com a prioridade dada
 *   lista_cancelar         - Percorre a lista até encontrar o ID e altera o status
 *                            para "cancelado" (bloqueia se já estiver "atendido")
 *   lista_atualizar_status - Percorre a lista e altera o status do atendimento com
 *                            o ID informado para o novo valor recebido
 *   lista_destruir         - Libera todos os nós alocados dinamicamente
 *   lista_copiar_array     - Copia até `max` atendimentos da lista para um vetor,
 *                            necessário para as funções de ordenação
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void lista_init(Lista *l) {
    /* Define cabeca = NULL e tamanho = 0 */
}

int lista_inserir(Lista *l, Atendimento a) {
    /* 1. Aloca um NoLista com malloc
     * 2. Copia o atendimento para o novo nó
     * 3. Encadeia o novo nó no início: novo->proximo = cabeca; cabeca = novo
     * 4. Incrementa tamanho
     * 5. Retorna 1 em sucesso ou 0 se malloc falhou
     */
}

void lista_listar(const Lista *l) {
    /* 1. Se a lista estiver vazia, imprime "Historico vazio." e retorna
     * 2. Imprime o cabeçalho com imprimir_cabecalho()
     * 3. Percorre todos os nós e chama imprimir_atendimento() em cada um
     * 4. Imprime o total de registros ao final
     */
}

int lista_buscar_nome(const Lista *l, const char *nome) {
    /* Busca sequencial (O(n)) — percorre toda a lista.
     * Para cada nó, usa strstr() para verificar se o campo cliente
     * contém o trecho buscado (busca parcial, case-sensitive).
     * Imprime os encontrados e retorna a quantidade.
     */
}

int lista_buscar_prioridade(const Lista *l, int prioridade) {
    /* Busca sequencial (O(n)) — percorre toda a lista.
     * Compara o campo prioridade de cada atendimento com o valor recebido.
     * Imprime os encontrados e retorna a quantidade.
     */
}

int lista_cancelar(Lista *l, int id) {
    /* 1. Percorre a lista até encontrar o ID
     * 2. Se o status já for "atendido", imprime aviso e retorna 0
     * 3. Se encontrado e não atendido, altera status para "cancelado" e retorna 1
     * 4. Se o ID não existir na lista, retorna 0
     */
}

int lista_atualizar_status(Lista *l, int id, const char *status) {
    /* Percorre a lista até encontrar o nó com o ID informado.
     * Atualiza o campo status com strncpy() usando o valor recebido.
     * Retorna 1 se encontrou e atualizou, 0 caso contrário.
     */
}

void lista_destruir(Lista *l) {
    /* Percorre todos os nós liberando a memória de cada um,
     * depois reinicializa a lista chamando lista_init()
     */
}

int lista_copiar_array(const Lista *l, Atendimento *arr, int max) {
    /* Percorre a lista copiando cada atendimento para arr[i].
     * Para quando chegar em NULL ou quando i atingir max.
     * Retorna o número de elementos copiados.
     * Usado por ordenacao.c para ordenar sem modificar a lista original.
     */
}
