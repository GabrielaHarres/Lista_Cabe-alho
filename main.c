#include <stdio.h>
#include <stdlib.h>
#include "lista_cabecalho.h"

void menu() {
    printf("\n==== MENU LISTA COM CABECALHO ====\n");
    printf("1. Inserir no inicio\n");
    printf("2. Inserir no fim\n");
    printf("3. Remover valor\n");
    printf("4. Mostrar lista\n");
    printf("5. Contar elementos\n");
    printf("6. Buscar valor\n");
    printf("7. Reverter lista\n");
    printf("8. Maior valor\n");
    printf("9. Menor valor\n");
    printf("10. Verificar se esta vazia\n");
    printf("11. Copiar lista\n");
    printf("12. Concatenar nova lista\n");
    printf("13. Remover duplicatas\n");
    printf("0. Sair\n");
    printf("==================================\n");
    printf("Opcao: ");
}

int main() {
    Lista* lista = criarLista();
    Lista* copia = NULL;
    int opcao, valor;

    // preenche lista inicial
    for (int i = 1; i <= 5; i++) {
        inserirFim(lista, i);
    }

    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Valor para inserir no inicio: ");
                scanf("%d", &valor);
                inserirInicio(lista, valor);
                break;

            case 2:
                printf("Valor para inserir no fim: ");
                scanf("%d", &valor);
                inserirFim(lista, valor);
                break;

            case 3:
                printf("Valor a remover: ");
                scanf("%d", &valor);
                if (removerValor(lista, valor))
                    printf("Removido.\n");
                else
                    printf("Nao encontrado.\n");
                break;

            case 4:
                imprimirLista(lista);
                break;

            case 5:
                printf("Total: %d elemento(s)\n", contarElementos(lista));
                break;

            case 6:
                printf("Valor para buscar: ");
                scanf("%d", &valor);
                if (buscarValor(lista, valor))
                    printf("Encontrado!\n");
                else
                    printf("Nao encontrado.\n");
                break;

            case 7:
                reverterLista(lista);
                printf("Lista invertida.\n");
                break;

            case 8:
                valor = obterMaior(lista);
                if (valor == -1)
                    printf("Lista vazia.\n");
                else
                    printf("Maior: %d\n", valor);
                break;

            case 9:
                valor = obterMenor(lista);
                if (valor == -1)
                    printf("Lista vazia.\n");
                else
                    printf("Menor: %d\n", valor);
                break;

            case 10:
                if (estaVazia(lista))
                    printf("Lista vazia.\n");
                else
                    printf("Lista nao esta vazia.\n");
                break;

            case 11:
                copia = copiarLista(lista);
                printf("Lista copiada: ");
                imprimirLista(copia);
                break;

            case 12: {
                Lista* nova = criarLista();
                int qtd, num;
                printf("Quantos valores na nova lista? ");
                scanf("%d", &qtd);
                for (int i = 0; i < qtd; i++) {
                    printf("Valor %d: ", i + 1);
                    scanf("%d", &num);
                    inserirFim(nova, num);
                }
                concatenarListas(lista, nova);
                printf("Listas concatenadas.\n");
                break;
            }

            case 13:
                removerDuplicatas(lista);
                printf("Duplicatas removidas.\n");
                break;

            case 0:
                liberarLista(lista);
                if (copia) liberarLista(copia);
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}