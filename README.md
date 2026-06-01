# Sistema de Atendimento Inteligente

Projeto desenvolvido para a Avaliação Prática da Unidade Curricular **Estruturas de Dados | Linguagem C**.

---

## Integrantes

| Integrante | Responsabilidades |
|------------|-------------------|
| Integrante A | TAD Atendimento (`atendimento.h/c`), fila dinâmica (`fila.h/c`), menu principal (`main.c`) e testes básicos |
| Integrante B | Lista encadeada (`lista.h/c`), ordenação (`ordenacao.h/c`), árvore binária (`arvore.h/c`), hash (`hash.h/c`) e estatísticas |

---

## Estruturas de Dados Implementadas

| Estrutura | Arquivo | Finalidade |
|-----------|---------|-----------|
| Fila dinâmica | `fila.h/c` | Controla a ordem de atendimento (FIFO) |
| Lista encadeada | `lista.h/c` | Mantém o histórico completo de atendimentos |
| Árvore binária de busca | `arvore.h/c` | Busca eficiente por ID |
| Tabela hash | `hash.h/c` | Agrupamento e busca por categoria |
| Insertion sort | `ordenacao.h/c` | Ordenação por prioridade e por tempo estimado |

---

## Compilação

### Linux / macOS
```bash
gcc main.c atendimento.c fila.c lista.c arvore.c hash.c ordenacao.c -o sistema
```

### Windows (MinGW / GCC)
```bash
gcc main.c atendimento.c fila.c lista.c arvore.c hash.c ordenacao.c -o sistema.exe
```

### Com warnings ativados (recomendado)
```bash
gcc -Wall -Wextra main.c atendimento.c fila.c lista.c arvore.c hash.c ordenacao.c -o sistema
```

---

## Execução

### Linux / macOS
```bash
./sistema
```

### Windows
```bash
sistema.exe
```

---

## Funcionalidades

### Obrigatórias
- [x] Cadastrar atendimentos com todos os campos obrigatórios
- [x] Fila dinâmica para controle da ordem de atendimento
- [x] Lista encadeada para histórico de atendimentos
- [x] Atender o próximo item da fila (status → `atendido`)
- [x] Listar fila de espera
- [x] Listar histórico de atendimentos
- [x] Busca sequencial por nome do cliente (busca parcial)
- [x] Busca sequencial por prioridade
- [x] Ordenação por prioridade (maior primeiro)
- [x] Ordenação por tempo estimado (menor primeiro)
- [x] Código organizado em módulos `.h` / `.c`
- [x] Menu funcional no terminal

### Avançadas
- [x] Árvore binária de busca por ID
- [x] Tabela hash por categoria (função djb2)
- [x] Estatísticas: total, atendidos, cancelados, por prioridade e tempo médio
- [x] Liberação correta de toda memória alocada dinamicamente
- [x] Responsabilidades separadas por TAD — `main.c` apenas coordena

### Extras
- [x] Cancelamento de atendimento (remove da fila e altera status no histórico)
- [x] Busca parcial por nome do cliente (`strstr`)
- [x] Remoção na árvore binária

---

## Estrutura do Projeto

```
projeto-estruturas-dados/
│
├── README.md
├── main.c
│
├── atendimento.h / atendimento.c   — struct e funções base
├── fila.h        / fila.c          — fila dinâmica (FIFO)
├── lista.h       / lista.c         — lista encadeada (histórico)
├── arvore.h      / arvore.c        — árvore binária de busca
├── hash.h        / hash.c          — tabela hash por categoria
└── ordenacao.h   / ordenacao.c     — algoritmos de ordenação
```

---

## Menu do Sistema

```
===== SISTEMA DE ATENDIMENTOS =====
 1  - Cadastrar atendimento
 2  - Atender proximo da fila
 3  - Cancelar atendimento
 4  - Listar fila de espera
 5  - Listar historico
 6  - Buscar por nome do cliente
 7  - Buscar por prioridade
 8  - Buscar por ID (arvore binaria)
 9  - Buscar por categoria (hash)
10  - Ordenar historico por prioridade
11  - Ordenar historico por tempo estimado
12  - Exibir estatisticas
 0  - Sair
```
