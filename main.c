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

    while (opcao != 5) // funções
    {
        printf("\nMenu Principal:\n");
        printf("1 - Comprar Produto\n");
        printf("2 - Ver Carrinho\n");
        printf("3 - Calcular Frete\n");
        printf("4 - Gerar Relatorio\n");
        printf("5 - Finalizar Pedido\n");

        NewFunction(); // "Escolha uma opção:"

        if (scanf("%d", &opcao) != 1)
        {
        
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
            iniciarCompra();      // produto.c
            break;

        case 2:
            mostrarCarrinho();    // carrinho.c
            break;

        case 3:
            calcularFrete();      // frete.c
            break;

        case 4:
            gerarRelatorio();     // relatorio.c
            break;

        case 5:
            finalizarPedido();    // relatorio.c ou outro arquivo
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
    printf("Escolha uma opcao: ");
}