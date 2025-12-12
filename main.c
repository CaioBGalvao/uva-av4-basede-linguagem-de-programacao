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

// Função auxiliar para limpar o buffer do teclado
void limparBufferEntrada() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

int main() {
  Carrinho meuCarrinho;

  int opcao = 0;

  inicializarProdutos();

  inicializarCarrinho(&meuCarrinho);

  printf("=====================================\n");
  printf("     Bem-vindo ao Flaviozon!  \n");
  printf("=====================================\n");

  while (opcao != 5) // funções
  {
    printf("\nMenu Principal:\n");
    printf("1 - Listar Produtos\n");
    printf("2 - Adicionar Carrinho\n");
    printf("3 - Visualizar Carrinho\n");
    printf("4 - Finalizar Compra\n");
    printf("5 - Sair\n");

    if (scanf("%d", &opcao) != 1) {

      limparBufferEntrada();
      printf("Entrada inválida!\n");
      continue;
    }

    switch (opcao) {
    case 1:
      listarProdutos(); // produto.c
      break;

    case 2: {

      int id, quantidade;

      printf("\nDigite o ID do produto: ");
      if (scanf("%d", &id) != 1) {
        limparBufferEntrada();
        printf("Entrada inválida!\n");
        break;
      }

      printf("Digite a quantidade: ");
      if (scanf("%d", &quantidade) != 1) {
        limparBufferEntrada();
        printf("Entrada inválida!\n");
        break;
      }

      Produto p = buscarProduto(id);

      if (p.id == -1) {
        printf("Produto não encontrado!\n");
      } else {
        int ok = adicionarAoCarrinho(&meuCarrinho, p, quantidade);
        if (ok)
          printf("Produto adicionado ao carrinho!\n");
        else
          printf("Carrinho cheio! Não foi possível adicionar.\n");
      }
    } break;

    case 3: // ver carrinho
      visualizarCarrinho(meuCarrinho);
      break;

    case 4: // finalizar a compra
    {
      if (meuCarrinho.qtdProdutos == 0) {
        printf("\nSeu carrinho está vazio!\n");
        break;
      }

      int regiao;

      printf("\nSelecione sua região para calcular o frete:\n");
      printf("1 - Sul\n");
      printf("2 - Sudeste\n");
      printf("3 - Norte\n");
      printf("4 - Nordeste\n");
      printf("Digite a opcao: ");

      int regiaoOpcao;

      if (scanf("%d", &regiaoOpcao) != 1 || regiaoOpcao < 1 ||
          regiaoOpcao > 4) {
        printf("Região inválida!\n");
        limparBufferEntrada();
        break;
      }

      regiao = (Regiao)regiaoOpcao;

      float pesoTotal = calcularPesoTotalCarrinho(meuCarrinho);
      float frete = calcularFrete(regiao, pesoTotal);
      float totalItens = calcularTotalCarrinho(meuCarrinho);
      float totalFinal = totalItens + frete;

      printf("\n========== RESUMO DA COMPRA ==========\n");
      printf("Subtotal dos produtos: R$ %.2f\n", totalItens);
      printf("Frete (%s): R$ %.2f\n", obterNomeRegiao(regiao), frete);
      printf("TOTAL FINAL: R$ %.2f\n", totalFinal);

      int confirmar;
      printf("\nDeseja finalizar a compra?\n1 - Sim\n2 - Não\nEscolha: ");
      scanf("%d", &confirmar);

      if (confirmar == 1) {
        gerarNotaFiscal(meuCarrinho, regiao, frete, totalFinal);
        inicializarCarrinho(&meuCarrinho); // limpa carrinho
        printf("\nCompra finalizada com sucesso!\n");
      } else {
        printf("\nCompra cancelada.\n");
      }
    } break;

    default:
      printf("Opcao inválida! Tente novamente.\n");
    }
  }

  return 0;
}