# Sistema de Atendimento Inteligente

Projeto desenvolvido para a **Avaliação Prática 1 (AVP1)**
Unidade Curricular: **Estruturas de Dados | Linguagem C**

- **Abertura:** 01/06/2026
- **Vencimento:** 15/06/2026
- **Formato:** Trabalho em dupla

---

## Integrantes e Divisão de Responsabilidades

| Integrante | Responsabilidades |
|------------|-------------------|
| Otávio Fertig | TAD Atendimento, Fila dinâmica, Lista encadeada, `main.c`, menu principal |
| Wesley | Árvore binária de busca, Tabela hash, Ordenação, Estatísticas |

> A apresentação poderá conter perguntas para qualquer integrante sobre qualquer parte do projeto. Ambos devem compreender o sistema completo.

---

## Estrutura do Projeto

```
AVP1-Sistema-de-atendimento-Inteligente/
│
├── README.md          — documentação do projeto
├── Makefile           — comando para compilar o projeto automaticamente
│
└── src/
    ├── main.c         — menu principal e coordenação entre os módulos
    │
    ├── atendimento.h  — definição da struct Atendimento e constantes
    ├── atendimento.c  — funções base: geração de ID, impressão formatada
    │
    ├── fila.h         — definição da struct Fila e NoFila
    ├── fila.c         — fila dinâmica FIFO: enqueue, dequeue, listar
    │
    ├── lista.h        — definição da struct Lista e NoLista
    ├── lista.c        — lista encadeada: inserir, buscar, cancelar, estatísticas
    │
    ├── arvore.h       — definição da struct Arvore e NoArvore
    ├── arvore.c       — árvore binária de busca por ID: inserir, buscar, remover
    │
    ├── hash.h         — definição da struct TabelaHash e NoHash
    ├── hash.c         — tabela hash por categoria: inserir, buscar
    │
    ├── ordenacao.h    — assinaturas das funções de ordenação
    └── ordenacao.c    — Insertion Sort por prioridade e por tempo estimado
```

---

## O que cada arquivo faz

### `atendimento.h` / `atendimento.c`
Define a estrutura base `Atendimento` usada por todos os módulos:
- `id`, `cliente`, `categoria`, `prioridade`, `tempo_estimado`, `status`
- `proximo_id()` — gera IDs sequenciais automaticamente
- `imprimir_atendimento()` — imprime uma linha formatada com os dados
- `imprimir_cabecalho()` — imprime o cabeçalho da tabela

### `fila.h` / `fila.c`
Fila dinâmica (FIFO — First In, First Out) para controle da ordem de atendimento.
- Cada atendimento cadastrado entra no **fim** da fila
- Quando alguém é atendido, sai do **início** da fila
- Cresce dinamicamente com `malloc` — sem tamanho fixo

### `lista.h` / `lista.c`
Lista encadeada simples usada como histórico de atendimentos.
- Guarda **todos** os atendimentos: abertos, atendidos e cancelados
- Inserção no início em tempo O(1)
- Permite busca por nome (parcial) e por prioridade
- Permite cancelar atendimento e atualizar status

### `arvore.h` / `arvore.c`
Árvore binária de busca (BST) organizada pelo `id`.
- IDs menores ficam à esquerda; maiores, à direita
- Busca por ID em tempo O(log n) — mais eficiente que percorrer a lista
- Suporta remoção com os três casos: nó folha, um filho, dois filhos

### `hash.h` / `hash.c`
Tabela hash para agrupar e buscar atendimentos por `categoria`.
- Usa a função djb2 para converter o nome da categoria em um índice
- Acesso médio O(1) — muito mais rápido que busca sequencial
- Colisões tratadas com encadeamento (lista ligada por bucket)

### `ordenacao.h` / `ordenacao.c`
Algoritmo Insertion Sort para ordenar o histórico de atendimentos.
- `ordenar_por_prioridade()` — maior prioridade primeiro (Alta → Baixa)
- `ordenar_por_tempo()` — menor tempo estimado primeiro
- Não modifica o histórico original — ordena uma cópia em vetor

### `main.c`
Ponto de entrada do programa. Contém o menu interativo e coordena os módulos.
- Leitura e validação de entradas do usuário
- Chama as funções dos TADs para cada opção do menu
- Libera toda a memória alocada ao encerrar

---

## Compilação

### Usando o Makefile (recomendado)
```bash
make
```

### Manualmente — Linux / macOS
```bash
gcc -Wall src/*.c -o sistema
```

### Manualmente — Windows (MinGW / GCC)
```bash
gcc -Wall src/*.c -o sistema.exe
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
===================================
```

---

## Requisitos do Enunciado

### Obrigatórios (nota base)

- [x] Cadastrar atendimentos com todos os campos obrigatórios
- [x] Fila dinâmica para controle da ordem de atendimento
- [x] Lista encadeada para histórico de atendimentos
- [x] Atender o próximo item da fila (status → `atendido`)
- [x] Listar fila de espera
- [x] Listar histórico de atendimentos
- [x] Busca sequencial por nome do cliente (busca parcial com `strstr`)
- [x] Busca sequencial por prioridade
- [x] Ordenação por prioridade (maior primeiro)
- [x] Ordenação por tempo estimado (menor primeiro)
- [x] Código organizado em arquivos `.h` e `.c`
- [x] Menu funcional no terminal
- [x] `README.md` com instruções de compilação e execução
- [x] Entrega via repositório Git

### Avançados (nota 10)

- [ ] Árvore binária de busca para consultar por ID *(pendente — Integrante B)*
- [ ] Tabela hash para buscar por categoria *(pendente — Integrante B)*
- [x] Estatísticas: total, atendidos, cancelados, por prioridade e tempo médio
- [x] Liberação correta de toda memória alocada dinamicamente
- [x] Responsabilidades separadas entre TADs — `main.c` apenas coordena
- [x] Explicação técnica das estruturas utilizadas (ver seção abaixo)

### Extras (opcionais)

- [x] Cancelar atendimento (remove da fila e altera status no histórico)
- [x] Busca parcial por nome do cliente
- [x] Remoção na árvore binária *(pendente — Integrante B)*
- [x] Validação de entradas do usuário no menu
- [ ] Salvar e carregar atendimentos em arquivo `.txt` ou `.csv`
- [ ] Medir tempo de busca comparando lista, árvore e hash

---

## Justificativa Técnica das Estruturas

### Fila Dinâmica
O atendimento segue a ordem de chegada (FIFO). Alternativas como vetor fixo desperdiçariam memória ou exigiriam mover todos os elementos ao remover o primeiro.

### Lista Encadeada
O histórico precisa crescer sem limite. A lista encadeada aloca cada nó com `malloc` sob demanda e insere no início em O(1). Um vetor exigiria realocar toda a memória ao crescer.

### Árvore Binária de Busca
Buscar por ID na lista exige percorrer nó por nó — O(n). Na árvore, cada comparação elimina metade dos nós restantes — O(log n) na média.

### Tabela Hash
Buscar por categoria em uma lista seria O(n). A função djb2 converte o nome da categoria em um índice direto no vetor de buckets — acesso médio O(1). Colisões são tratadas com encadeamento.

### Insertion Sort
Para volumes pequenos e médios (centenas de registros), o Insertion Sort é simples, estável e eficiente na prática. Usa ponteiro de função para reutilizar o mesmo algoritmo com critérios diferentes.
