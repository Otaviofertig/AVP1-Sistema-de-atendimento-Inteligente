#include <stdio.h>
#include <string.h>
#include "atendimento.h"

static int contador_id = 1;

int proximo_id(void) {
    return contador_id++;
}

const char *prioridade_label(int p) {
    switch (p) {
        case 1: return "Baixa";
        case 2: return "Media";
        case 3: return "Alta";
        default: return "Desconhecida";
    }
}

void imprimir_cabecalho(void) {
    printf("%-5s %-20s %-15s %-10s %-10s %-12s\n",
           "ID", "Cliente", "Categoria", "Prioridade", "Tempo(min)", "Status");
    printf("%-5s %-20s %-15s %-10s %-10s %-12s\n",
           "---", "-------------------", "--------------", "----------", "----------", "------------");
}

void imprimir_atendimento(const Atendimento *a) {
    printf("%-5d %-20s %-15s %-10s %-10d %-12s\n",
           a->id, a->cliente, a->categoria,
           prioridade_label(a->prioridade), a->tempo_estimado, a->status);
}
