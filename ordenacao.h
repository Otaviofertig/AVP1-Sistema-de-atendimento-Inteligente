#ifndef ORDENACAO_H
#define ORDENACAO_H

#include "atendimento.h"
#include "lista.h"

void ordenar_por_prioridade(Atendimento *arr, int n);
void ordenar_por_tempo(Atendimento *arr, int n);
void imprimir_array(const Atendimento *arr, int n);

#endif
