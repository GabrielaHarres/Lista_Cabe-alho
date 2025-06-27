#include <stdio.h>
#include <stdlib.h>
#include "lista_cabecalho.h"

// cria uma nova lista com nó de cabeçalho
Lista* criarLista() {
    Lista* nova = (Lista*) malloc(sizeof(Lista));
    nova->cabeca = (No*) malloc(sizeof(No));
    nova->cabeca->proximo = NULL;
    return nova;
}

// insere um novo valor no início da lista
void inserirInicio(Lista* lista, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = lista->cabeca->proximo;
    lista->cabeca->proximo = novo;
}

// insere um novo valor no fim da lista
void inserirFim(Lista* lista, int valor) {
    No* atual = lista->cabeca;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    atual->proximo = novo;
}

// remove o primeiro nó com o valor indicado
int removerValor(Lista* lista, int valor) {
    No* anterior = lista->cabeca;
    No* atual = anterior->proximo;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) return 0;

    anterior->proximo = atual->proximo;
    free(atual);
    return 1;
}

// mostra os elementos da lista
void imprimirLista(Lista* lista) {
    No* atual = lista->cabeca->proximo;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// conta a quantidade de nós (tirando o cabeçalho)
int contarElementos(Lista* lista) {
    int cont = 0;
    No* atual = lista->cabeca->proximo;
    while (atual != NULL) {
        cont++;
        atual = atual->proximo;
    }
    return cont;
}

// verifica se um valor existe na lista
int buscarValor(Lista* lista, int valor) {
    No* atual = lista->cabeca->proximo;
    while (atual != NULL) {
        if (atual->valor == valor) return 1;
        atual = atual->proximo;
    }
    return 0;
}

// inverte a lista 
void reverterLista(Lista* lista) {
    No* anterior = NULL;
    No* atual = lista->cabeca->proximo;
    No* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    lista->cabeca->proximo = anterior;
}

// retorna o maior valor da lista
int obterMaior(Lista* lista) {
    if (lista->cabeca->proximo == NULL) return -1;

    int max = lista->cabeca->proximo->valor;
    No* atual = lista->cabeca->proximo->proximo;

    while (atual != NULL) {
        if (atual->valor > max) max = atual->valor;
        atual = atual->proximo;
    }

    return max;
}

// retorna o menor valor da lista
int obterMenor(Lista* lista) {
    if (lista->cabeca->proximo == NULL) return -1;

    int min = lista->cabeca->proximo->valor;
    No* atual = lista->cabeca->proximo->proximo;

    while (atual != NULL) {
        if (atual->valor < min) min = atual->valor;
        atual = atual->proximo;
    }

    return min;
}

// vrifica se a lista ta vazia
int estaVazia(Lista* lista) {
    return lista->cabeca->proximo == NULL;
}

// faz uma cópia profunda da lista
Lista* copiarLista(Lista* lista) {
    Lista* nova = criarLista();
    No* atual = lista->cabeca->proximo;
    No* fim = nova->cabeca;

    while (atual != NULL) {
        No* novo = (No*) malloc(sizeof(No));
        novo->valor = atual->valor;
        novo->proximo = NULL;
        fim->proximo = novo;
        fim = novo;
        atual = atual->proximo;
    }

    return nova;
}

// concatena lista l2 ao fim de l1 e libera l2
void concatenarListas(Lista* l1, Lista* l2) {
    No* fim = l1->cabeca;
    while (fim->proximo != NULL) {
        fim = fim->proximo;
    }

    fim->proximo = l2->cabeca->proximo;
    free(l2->cabeca);
    free(l2);
}

// remove valores repetidos da lista
void removerDuplicatas(Lista* lista) {
    No* atual = lista->cabeca->proximo;

    while (atual != NULL) {
        No* anterior = atual;
        No* comparador = atual->proximo;

        while (comparador != NULL) {
            if (comparador->valor == atual->valor) {
                anterior->proximo = comparador->proximo;
                free(comparador);
                comparador = anterior->proximo;
            } else {
                anterior = comparador;
                comparador = comparador->proximo;
            }
        }

        atual = atual->proximo;
    }
}

// libera toda a memória da lista
void liberarLista(Lista* lista) {
    No* atual = lista->cabeca;

    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    free(lista);
}