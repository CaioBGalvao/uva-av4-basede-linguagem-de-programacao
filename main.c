/* =========================================================================
 * Arquivo: main.c
 * Objetivo: Menu principal e fluxo de execução do programa.
 *
 * Autoria:
 *   Nome:      [NOME DO ESTUDANTE AQUI]
 *   Matrícula: [MATRICULA AQUI]
 *   Data:      2025-12-06
 * ========================================================================= */
#include "flaviozon.h"

int main()
{
    int opcao = 0;

    printf("=====================================\n");
    printf("     Bem-vindo ao Flaviozon!  \n");
    printf("=====================================\n");

    while (opcao != 3)
    {
        printf("\nMenu Principal:\n");
        printf("1 - Comprar\n");
        printf("2 - Ver Carrinho\n");
        printf("3 - Finalizar Pedido\n");
        NewFunction();
        if (scanf("%d", &opcao) != 1)
        {
            // limpar entrada inválida
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            opcao = 0;
            printf("Entrada invalida. Tente novamente.\n");
            continue;
        }

        switch (opcao)
        {
        case 1:
            iniciarCompra();
            break;
        case 2:
            mostrarCarrinho();
            break;
        case 3:
            finalizarPedido();
            printf("\nObrigado por comprar no FlavioZON!\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }
    }

    return 0;
}

void NewFunction()
{
    NewFunction();
}

void NewFunction()
{
    printf("Escolha uma opcao: ");
}
