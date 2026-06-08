/*
 * ordenacao.c
 * RESPONSAVEL: Integrante B
 *
 * Implementa ordenacao do historico de atendimentos usando Insertion Sort.
 *
 * Por que Insertion Sort?
 *   E simples de entender e implementar. Para listas de centenas de registros
 *   (o que e o caso aqui), o desempenho e aceitavel.
 *   Funciona como organizar cartas na mao: pega uma carta por vez e insere
 *   ela na posicao correta em relacao as cartas ja organizadas.
 *
 * A ordenacao NAO modifica a lista encadeada original.
 * O main.c copia os atendimentos para um vetor temporario (com lista_copiar_array)
 * e passa esse vetor para as funcoes abaixo.
 *
 * Assinaturas definidas em ordenacao.h:
 *   void ordenar_por_prioridade(Atendimento *arr, int n);
 *   void ordenar_por_tempo(Atendimento *arr, int n);
 *   void imprimir_array(const Atendimento *arr, int n);
 */

#include <stdio.h>
#include "ordenacao.h"

/*
 * insertion_sort  (funcao auxiliar interna — use static)
 * Algoritmo generico de Insertion Sort que aceita qualquer criterio de comparacao.
 *
 * Parametros:
 *   arr — vetor de Atendimentos a ser ordenado (modificado in-place)
 *   n   — quantidade de elementos no vetor
 *   cmp — ponteiro para funcao de comparacao
 *           retorna > 0 se 'a' deve vir depois de 'b'
 *           retorna < 0 se 'a' deve vir antes de 'b'
 *           retorna 0   se sao iguais
 *
 * Logica do Insertion Sort:
 *   for i de 1 ate n-1:
 *     chave = arr[i]           // elemento que vamos inserir na posicao correta
 *     j = i - 1
 *     while j >= 0 E cmp(&arr[j], &chave) > 0:
 *         arr[j+1] = arr[j]   // empurra o elemento para a direita
 *         j--
 *     arr[j+1] = chave         // insere a chave na posicao correta
 */

/*
 * cmp_prioridade_desc  (funcao auxiliar interna — use static)
 * Criterio: maior prioridade primeiro (Alta=3, Media=2, Baixa=1).
 * Para ordenar em ordem DECRESCENTE, retorne b->prioridade - a->prioridade.
 * Se o resultado for positivo, significa que 'a' deve vir depois de 'b'.
 */

/*
 * cmp_tempo_asc  (funcao auxiliar interna — use static)
 * Criterio: menor tempo estimado primeiro (ordem crescente).
 * Retorne a->tempo_estimado - b->tempo_estimado.
 */

/*
 * ordenar_por_prioridade
 * Chama insertion_sort passando arr, n e a funcao cmp_prioridade_desc.
 */
void ordenar_por_prioridade(Atendimento *arr, int n) {
    /* TODO */
}

/*
 * ordenar_por_tempo
 * Chama insertion_sort passando arr, n e a funcao cmp_tempo_asc.
 */
void ordenar_por_tempo(Atendimento *arr, int n) {
    /* TODO */
}

/*
 * imprimir_array
 * Imprime todos os atendimentos de um vetor ja ordenado.
 * Passos:
 *   1. Se n == 0, imprima "Nenhum atendimento para exibir." e retorne
 *   2. Chame imprimir_cabecalho()
 *   3. Use um for de 0 ate n-1 e chame imprimir_atendimento(&arr[i])
 *   4. Imprima o total: n
 */
void imprimir_array(const Atendimento *arr, int n) {
    /* TODO */
}
