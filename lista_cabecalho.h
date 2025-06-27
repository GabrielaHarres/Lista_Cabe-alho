#ifndef LISTA_CABECALHO_H
#define LISTA_CABECALHO_H

// estrutura de um nó da lista
typedef struct No {
    int valor;
    struct No* proximo;
} No;

// estrutura da lista com nó de cabeçalho
typedef struct {
    No* cabeca;
} Lista;

// protótipos das funções
Lista* criarLista();
void inserirInicio(Lista* lista, int valor);
void inserirFim(Lista* lista, int valor);
int removerValor(Lista* lista, int valor);
void imprimirLista(Lista* lista);
int contarElementos(Lista* lista);
int buscarValor(Lista* lista, int valor);
void reverterLista(Lista* lista);
int obterMaior(Lista* lista);
int obterMenor(Lista* lista);
int estaVazia(Lista* lista);
Lista* copiarLista(Lista* lista);
void concatenarListas(Lista* l1, Lista* l2);
void removerDuplicatas(Lista* lista);
void liberarLista(Lista* lista);

#endif