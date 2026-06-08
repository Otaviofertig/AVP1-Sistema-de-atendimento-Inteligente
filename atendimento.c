/*
 * atendimento.c
 *
 * TAD (Tipo Abstrato de Dados) base do sistema.
 * Responsável por:
 *   - Manter o contador global de IDs e gerar o próximo ID único
 *   - Converter o número de prioridade (1, 2, 3) para texto legível
 *   - Imprimir o cabeçalho da tabela de atendimentos no terminal
 *   - Imprimir uma linha formatada com os dados de um atendimento
 *
 * Todos os outros módulos dependem deste arquivo para exibir atendimentos.
 */

#include <stdio.h>
#include <string.h>
#include "atendimento.h"

/* Variável estática: cada chamada a proximo_id() retorna um valor incrementado */
static int contador_id = 1;

int proximo_id(void) {
    /* Retorna o próximo ID disponível e incrementa o contador interno */
}

const char *prioridade_label(int p) {
    /* Converte o inteiro de prioridade para string:
     *   1 -> "Baixa"
     *   2 -> "Media"
     *   3 -> "Alta"
     *   outro -> "Desconhecida"
     */
}

void imprimir_cabecalho(void) {
    /* Imprime no terminal o cabeçalho das colunas da tabela:
     *   ID | Cliente | Categoria | Prioridade | Tempo(min) | Status
     * e uma linha separadora abaixo
     */
}

void imprimir_atendimento(const Atendimento *a) {
    /* Imprime uma linha formatada com todos os campos do atendimento:
     *   id, cliente, categoria, prioridade_label(), tempo_estimado, status
     */
}
