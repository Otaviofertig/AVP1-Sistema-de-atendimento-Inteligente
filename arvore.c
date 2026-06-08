/*
 * arvore.c
 * RESPONSAVEL: Integrante B
 *
 * Arvore Binaria de Busca (BST — Binary Search Tree) organizada pelo ID.
 *
 * Por que arvore para buscar por ID?
 *   Na lista, buscar um ID exige olhar no a no (O(n)).
 *   Na arvore, a cada passo eliminamos metade dos nos restantes: O(log n).
 *
 * Regra da BST:
 *   - ID menor que o no atual → vai para a ESQUERDA
 *   - ID maior que o no atual → vai para a DIREITA
 *
 * Exemplo com IDs inseridos na ordem 4, 2, 6, 1, 3:
 *
 *         4
 *        / \
 *       2   6
 *      / \
 *     1   3
 *
 * Percurso em-ordem (esquerda → raiz → direita) lista os IDs em ordem crescente.
 */

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

/*
 * arvore_init
 * Inicializa a arvore vazia.
 * Faca a->raiz = NULL.
 */
void arvore_init(Arvore *a) {
    /* TODO */
}

/*
 * criar_no  (funcao auxiliar interna — use static)
 * Aloca e inicializa um novo NoArvore.
 * Passos:
 *   1. malloc(sizeof(NoArvore))
 *   2. Se NULL, retorne NULL
 *   3. Copie o atendimento: no->atendimento = at
 *   4. no->esquerda = NULL; no->direita = NULL
 *   5. Retorne o ponteiro para o novo no
 */

/*
 * inserir_rec  (funcao auxiliar recursiva — use static)
 * Insere o atendimento na posicao correta da sub-arvore com raiz em 'no'.
 * Logica:
 *   - Se no == NULL: chegamos no lugar certo, crie e retorne um novo no
 *   - Se at.id < no->atendimento.id: no->esquerda = inserir_rec(no->esquerda, at)
 *   - Se at.id > no->atendimento.id: no->direita  = inserir_rec(no->direita,  at)
 *   - Se at.id == no->atendimento.id: ID duplicado, nao insira nada
 *   - Sempre retorne 'no' ao final (exceto quando era NULL)
 */

/*
 * arvore_inserir
 * Chama inserir_rec a partir da raiz e atualiza a->raiz com o retorno.
 * Retorne 1.
 */
int arvore_inserir(Arvore *a, Atendimento at) {
    /* TODO: a->raiz = inserir_rec(a->raiz, at); */
    return 1;
}

/*
 * buscar_rec  (funcao auxiliar recursiva — use static)
 * Busca o no com o id informado a partir da sub-arvore 'no'.
 * Logica:
 *   - Se no == NULL: nao encontrou, retorne 0
 *   - Se id == no->atendimento.id: encontrou! copie para *dest e retorne 1
 *   - Se id < no->atendimento.id: busque na sub-arvore esquerda
 *   - Se id > no->atendimento.id: busque na sub-arvore direita
 */

/*
 * arvore_buscar
 * Chama buscar_rec a partir da raiz.
 * Retorna 1 se encontrou (e preenche *dest), 0 se nao encontrou.
 */
int arvore_buscar(const Arvore *a, int id, Atendimento *dest) {
    /* TODO */
    return 0;
}

/*
 * em_ordem_rec  (funcao auxiliar recursiva — use static)
 * Percorre a arvore em-ordem: esquerda → no atual → direita.
 * Isso garante que os atendimentos sejam impressos em ordem crescente de ID.
 * Para cada no, chame imprimir_atendimento(&no->atendimento).
 */

/*
 * arvore_listar_em_ordem
 * Se a arvore estiver vazia, imprima aviso e retorne.
 * Caso contrario, chame imprimir_cabecalho() e depois em_ordem_rec(a->raiz).
 */
void arvore_listar_em_ordem(const Arvore *a) {
    /* TODO */
}

/*
 * encontrar_minimo  (funcao auxiliar — use static)
 * Retorna o no com menor ID em uma sub-arvore.
 * O menor ID esta sempre no no mais a ESQUERDA possivel.
 * Percorra para esquerda enquanto no->esquerda != NULL.
 * Retorne o ponteiro para esse no (sem remover).
 */

/*
 * remover_rec  (funcao auxiliar recursiva — use static)
 * Remove o no com o id informado da sub-arvore com raiz em 'no'.
 * Ha tres casos possíveis:
 *
 * CASO 1 — No folha (sem filhos):
 *   Libere o no com free() e retorne NULL.
 *
 * CASO 2 — No com apenas um filho:
 *   Salve o filho que existe, libere o no atual e retorne o filho salvo.
 *   - Se no->esquerda == NULL: guarde no->direita, free(no), retorne o guardado
 *   - Se no->direita  == NULL: guarde no->esquerda, free(no), retorne o guardado
 *
 * CASO 3 — No com dois filhos:
 *   Nao remova o no diretamente. Em vez disso:
 *   a. Encontre o SUCESSOR EM-ORDEM: o no com o menor ID na sub-arvore DIREITA
 *      (use encontrar_minimo(no->direita))
 *   b. Copie o atendimento do sucessor para o no atual
 *   c. Remova o sucessor da sub-arvore direita (ele tem no maximo um filho)
 *
 * Sinalize se removeu usando o ponteiro int *removeu.
 * Sempre retorne 'no' (possivelmente modificado).
 */

/*
 * arvore_remover
 * Chama remover_rec a partir da raiz.
 * Use uma variavel local int removeu = 0 e passe &removeu para a funcao recursiva.
 * Atualize a->raiz com o retorno.
 * Retorne removeu (1 se achou e removeu, 0 se nao encontrou o id).
 */
int arvore_remover(Arvore *a, int id) {
    /* TODO */
    return 0;
}

/*
 * destruir_rec  (funcao auxiliar recursiva — use static)
 * Libera toda a memoria da arvore em pos-ordem: filhos antes do pai.
 * Logica:
 *   - Se no == NULL, retorne
 *   - Chame destruir_rec(no->esquerda)
 *   - Chame destruir_rec(no->direita)
 *   - free(no)
 */

/*
 * arvore_destruir
 * Chama destruir_rec(a->raiz) e depois faz a->raiz = NULL.
 */
void arvore_destruir(Arvore *a) {
    /* TODO */
}
