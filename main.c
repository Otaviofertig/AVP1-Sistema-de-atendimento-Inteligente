#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "atendimento.h"
#include "fila.h"
#include "lista.h"
#include "arvore.h"
#include "hash.h"
#include "ordenacao.h"

#define MAX_HISTORICO 500

// Limpa buffer de entrada apos leitura com scanf
static void limpar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static void ler_string(const char *prompt, char *dest, int tam) {
    printf("%s", prompt);
    fgets(dest, tam, stdin);
    dest[strcspn(dest, "\n")] = '\0';
}

static int ler_int(const char *prompt, int min, int max) {
    int val;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &val) == 1 && val >= min && val <= max) {
            limpar_buffer();
            return val;
        }
        limpar_buffer();
        printf("  Valor invalido. Digite um numero entre %d e %d.\n", min, max);
    }
}

static void cadastrar(Fila *fila, Lista *historico, Arvore *arvore, TabelaHash *hash) {
    Atendimento a;
    a.id = proximo_id();

    printf("\n--- Cadastro de Atendimento (ID: %d) ---\n", a.id);
    ler_string("  Cliente    : ", a.cliente, MAX_CLIENTE);
    ler_string("  Categoria  : ", a.categoria, MAX_CATEGORIA);
    a.prioridade     = ler_int("  Prioridade (1=Baixa 2=Media 3=Alta): ", 1, 3);
    a.tempo_estimado = ler_int("  Tempo estimado (min): ", 1, 9999);
    strncpy(a.status, "aberto", MAX_STATUS - 1);

    fila_enqueue(fila, a);
    lista_inserir(historico, a);
    arvore_inserir(arvore, a);
    hash_inserir(hash, a);

    printf("  Atendimento #%d cadastrado com sucesso.\n", a.id);
}

static void atender_proximo(Fila *fila, Lista *historico, Arvore *arvore) {
    Atendimento a;
    if (!fila_dequeue(fila, &a)) {
        printf("  Fila de espera vazia. Nenhum atendimento para realizar.\n");
        return;
    }
    strncpy(a.status, "atendido", MAX_STATUS - 1);
    lista_atualizar_status(historico, a.id, "atendido");

    // Atualiza na arvore: remove e reinsere com novo status
    arvore_remover(arvore, a.id);
    arvore_inserir(arvore, a);

    printf("  Atendimento realizado:\n");
    imprimir_cabecalho();
    imprimir_atendimento(&a);
}

static void cancelar_atendimento(Fila *fila, Lista *historico) {
    int id = ler_int("\n  ID do atendimento a cancelar: ", 1, 99999);

    // Remove da fila (recriar a fila sem o item)
    Fila fila_nova;
    fila_init(&fila_nova);
    int cancelado_fila = 0;
    Atendimento tmp;
    while (fila_dequeue(fila, &tmp)) {
        if (tmp.id == id) {
            cancelado_fila = 1;
        } else {
            fila_enqueue(&fila_nova, tmp);
        }
    }
    // Move nos de volta
    while (fila_dequeue(&fila_nova, &tmp))
        fila_enqueue(fila, tmp);
    fila_destruir(&fila_nova);

    int cancelado_hist = lista_cancelar(historico, id);

    if (cancelado_fila || cancelado_hist)
        printf("  Atendimento #%d cancelado.\n", id);
    else
        printf("  Atendimento #%d nao encontrado.\n", id);
}

static void buscar_por_id(const Arvore *arvore) {
    int id = ler_int("\n  ID a buscar: ", 1, 99999);
    Atendimento a;
    if (arvore_buscar(arvore, id, &a)) {
        imprimir_cabecalho();
        imprimir_atendimento(&a);
    } else {
        printf("  Atendimento #%d nao encontrado na arvore.\n", id);
    }
}

static void buscar_por_categoria(const TabelaHash *hash) {
    char cat[MAX_CATEGORIA];
    ler_string("\n  Categoria a buscar: ", cat, MAX_CATEGORIA);
    hash_buscar_categoria(hash, cat);
}

static void buscar_por_nome(const Lista *historico) {
    char nome[MAX_CLIENTE];
    ler_string("\n  Nome (ou trecho) a buscar: ", nome, MAX_CLIENTE);
    lista_buscar_nome(historico, nome);
}

static void buscar_por_prioridade(const Lista *historico) {
    int p = ler_int("\n  Prioridade (1=Baixa 2=Media 3=Alta): ", 1, 3);
    lista_buscar_prioridade(historico, p);
}

static void ordenar_historico(const Lista *historico, int criterio) {
    Atendimento arr[MAX_HISTORICO];
    int n = lista_copiar_array(historico, arr, MAX_HISTORICO);
    if (criterio == 1) {
        ordenar_por_prioridade(arr, n);
        printf("\n  Historico ordenado por prioridade (maior primeiro):\n");
    } else {
        ordenar_por_tempo(arr, n);
        printf("\n  Historico ordenado por tempo estimado (menor primeiro):\n");
    }
    imprimir_array(arr, n);
}

static void exibir_estatisticas(const Lista *historico) {
    int total = 0, atendidos = 0, cancelados = 0, abertos = 0;
    int por_prioridade[4] = {0, 0, 0, 0}; // indices 1, 2, 3
    int tempo_total = 0;

    NoLista *atual = historico->cabeca;
    while (atual) {
        Atendimento *a = &atual->atendimento;
        total++;
        tempo_total += a->tempo_estimado;
        if (strcmp(a->status, "atendido")  == 0) atendidos++;
        else if (strcmp(a->status, "cancelado") == 0) cancelados++;
        else abertos++;
        if (a->prioridade >= 1 && a->prioridade <= 3)
            por_prioridade[a->prioridade]++;
        atual = atual->proximo;
    }

    printf("\n  ===== ESTATISTICAS =====\n");
    printf("  Total de atendimentos : %d\n", total);
    printf("  Abertos               : %d\n", abertos);
    printf("  Atendidos             : %d\n", atendidos);
    printf("  Cancelados            : %d\n", cancelados);
    printf("  Por prioridade:\n");
    printf("    Alta  (3): %d\n", por_prioridade[3]);
    printf("    Media (2): %d\n", por_prioridade[2]);
    printf("    Baixa (1): %d\n", por_prioridade[1]);
    if (total > 0)
        printf("  Tempo medio estimado  : %d min\n", tempo_total / total);
    printf("  ========================\n");
}

static void exibir_menu(void) {
    printf("\n===== SISTEMA DE ATENDIMENTOS =====\n");
    printf(" 1  - Cadastrar atendimento\n");
    printf(" 2  - Atender proximo da fila\n");
    printf(" 3  - Cancelar atendimento\n");
    printf(" 4  - Listar fila de espera\n");
    printf(" 5  - Listar historico\n");
    printf(" 6  - Buscar por nome do cliente\n");
    printf(" 7  - Buscar por prioridade\n");
    printf(" 8  - Buscar por ID (arvore binaria)\n");
    printf(" 9  - Buscar por categoria (hash)\n");
    printf("10  - Ordenar historico por prioridade\n");
    printf("11  - Ordenar historico por tempo estimado\n");
    printf("12  - Exibir estatisticas\n");
    printf(" 0  - Sair\n");
    printf("===================================\n");
}

int main(void) {
    Fila       fila;
    Lista      historico;
    Arvore     arvore;
    TabelaHash hash;

    fila_init(&fila);
    lista_init(&historico);
    arvore_init(&arvore);
    hash_init(&hash);

    int opcao;
    do {
        exibir_menu();
        opcao = ler_int("Opcao: ", 0, 12);

        switch (opcao) {
            case 1:  cadastrar(&fila, &historico, &arvore, &hash); break;
            case 2:  atender_proximo(&fila, &historico, &arvore);  break;
            case 3:  cancelar_atendimento(&fila, &historico);       break;
            case 4:
                printf("\n--- Fila de Espera ---\n");
                fila_listar(&fila);
                break;
            case 5:
                printf("\n--- Historico de Atendimentos ---\n");
                lista_listar(&historico);
                break;
            case 6:  buscar_por_nome(&historico);       break;
            case 7:  buscar_por_prioridade(&historico); break;
            case 8:  buscar_por_id(&arvore);            break;
            case 9:  buscar_por_categoria(&hash);       break;
            case 10: ordenar_historico(&historico, 1);  break;
            case 11: ordenar_historico(&historico, 2);  break;
            case 12: exibir_estatisticas(&historico);   break;
            case 0:  printf("  Encerrando sistema. Ate logo!\n"); break;
        }
    } while (opcao != 0);

    // Libera toda memoria alocada dinamicamente
    fila_destruir(&fila);
    lista_destruir(&historico);
    arvore_destruir(&arvore);
    hash_destruir(&hash);

    return 0;
}
