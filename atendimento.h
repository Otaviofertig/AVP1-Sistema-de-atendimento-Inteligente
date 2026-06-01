#ifndef ATENDIMENTO_H
#define ATENDIMENTO_H

#define MAX_CLIENTE 50
#define MAX_CATEGORIA 30
#define MAX_STATUS 20

typedef struct {
    int id;
    char cliente[MAX_CLIENTE];
    char categoria[MAX_CATEGORIA];
    int prioridade;       // 1 = baixa, 2 = media, 3 = alta
    int tempo_estimado;   // em minutos
    char status[MAX_STATUS]; // aberto, atendido, cancelado
} Atendimento;

int proximo_id(void);
void imprimir_atendimento(const Atendimento *a);
void imprimir_cabecalho(void);
const char *prioridade_label(int p);

#endif
