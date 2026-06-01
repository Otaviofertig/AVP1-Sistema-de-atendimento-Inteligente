#include <stdio.h>
#include "ordenacao.h"

// Insertion sort - didatico e adequado para volumes pequenos/medios
static void insertion_sort(Atendimento *arr, int n,
                           int (*cmp)(const Atendimento *, const Atendimento *)) {
    for (int i = 1; i < n; i++) {
        Atendimento chave = arr[i];
        int j = i - 1;
        while (j >= 0 && cmp(&arr[j], &chave) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

static int cmp_prioridade_desc(const Atendimento *a, const Atendimento *b) {
    // Maior prioridade primeiro (3 > 2 > 1)
    return b->prioridade - a->prioridade;
}

static int cmp_tempo_asc(const Atendimento *a, const Atendimento *b) {
    return a->tempo_estimado - b->tempo_estimado;
}

void ordenar_por_prioridade(Atendimento *arr, int n) {
    insertion_sort(arr, n, cmp_prioridade_desc);
}

void ordenar_por_tempo(Atendimento *arr, int n) {
    insertion_sort(arr, n, cmp_tempo_asc);
}

void imprimir_array(const Atendimento *arr, int n) {
    if (n == 0) {
        printf("  Nenhum atendimento para exibir.\n");
        return;
    }
    imprimir_cabecalho();
    for (int i = 0; i < n; i++)
        imprimir_atendimento(&arr[i]);
    printf("  Total: %d\n", n);
}
