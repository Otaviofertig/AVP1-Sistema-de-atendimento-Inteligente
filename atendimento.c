/*
 * atendimento.c
 * Funções base usadas por todos os outros módulos.
 */

#include <stdio.h>
#include "atendimento.h"

/* Contador global de IDs — começa em 1 e nunca reinicia */
static int contador_id = 1;

/* Retorna o próximo ID disponível */
int proximo_id(void) {
    return contador_id++;
}

/* Converte o número de prioridade para texto */
const char *prioridade_label(int p) {
    if (p == 1) return "Baixa";
    if (p == 2) return "Media";
    if (p == 3) return "Alta";
    return "?";
}

/* Imprime o cabeçalho da tabela */
void imprimir_cabecalho(void) {
    printf("%-4s %-20s %-15s %-10s %-10s %-10s\n",
           "ID", "Cliente", "Categoria", "Prioridade", "Tempo", "Status");
    printf("---- -------------------- --------------- ---------- ---------- ----------\n");
}

/* Imprime uma linha com os dados de um atendimento */
void imprimir_atendimento(const Atendimento *a) {
    printf("%-4d %-20s %-15s %-10s %-10d %-10s\n",
           a->id, a->cliente, a->categoria,
           prioridade_label(a->prioridade), a->tempo_estimado, a->status);
}
