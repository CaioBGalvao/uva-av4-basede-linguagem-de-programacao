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

void exibirMenu() {
  printf("\n=== FLAVIOZON - MENU ===\n");
  printf("1. Listar Produtos\n");
  printf("2. Adicionar Produto ao Carrinho\n");
  printf("3. Visualizar Carrinho\n");
  printf("4. Finalizar Compra\n");
  printf("5. Sair\n");
  printf("Escolha uma opcao: ");
}

void limparBufferEntrada() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

int main() {
  Carrinho meuCarrinho;
  int opcao = 0;

  // Inicialização dos módulos
  inicializarProdutos();
  inicializarCarrinho(&meuCarrinho);

  while (opcao != 5) {
    exibirMenu();
    if (scanf("%d", &opcao) != 1) {
      printf("Entrada invalida. Tente novamente.\n");
      limparBufferEntrada();
      continue;
    }

    switch (opcao) {
    case 1:
      listarProdutos();
      break;

    case 2: {
      int id, qtd;
      printf("Digite o ID do produto: ");
      scanf("%d", &id);
      printf("Digite a quantidade: ");
      scanf("%d", &qtd);

      Produto p = buscarProduto(id);
      if (p.id == -1) {
        printf("[ERRO] Produto nao encontrado!\n");
      } else {
        if (adicionarAoCarrinho(&meuCarrinho, p, qtd)) {
          printf("[SUCESSO] Produto adicionado!\n");
        } else {
          printf("[ERRO] Nao foi possivel adicionar (Carrinho cheio ou qtd "
                 "invalida).\n");
        }
      }
      break;
    }

    case 3:
      visualizarCarrinho(meuCarrinho);
      break;

    case 4: {
      if (meuCarrinho.qtdProdutos == 0) {
        printf("[AVISO] Carrinho vazio. Adicione itens antes de finalizar.\n");
        break;
      }

      printf("\n--- FINALIZAR COMPRA ---\n");
      printf("Regioes disponiveis:\n");
      printf("1 - Sul\n");
      printf("2 - Sudeste\n");
      printf("3 - Norte\n");
      printf("4 - Nordeste\n");
      printf("Selecione sua regiao (1-4): ");

      int reg;
      scanf("%d", &reg);
      if (reg < 1 || reg > 4) {
        printf("[ERRO] Regiao invalida!\n");
        break;
      }

      Regiao regiaoEscolhida = (Regiao)reg;
      float pesoTotal = calcularPesoTotalCarrinho(meuCarrinho);
      float valorFrete = calcularFrete(regiaoEscolhida, pesoTotal);
      float subtotal = calcularTotalCarrinho(meuCarrinho);
      float totalFinal = subtotal + valorFrete;

      printf("\n--- RESUMO ---\n");
      printf("Subtotal: R$ %.2f\n", subtotal);
      printf("Frete (%s, %.2f Kg): R$ %.2f\n", obterNomeRegiao(regiaoEscolhida),
             pesoTotal, valorFrete);
      printf("TOTAL A PAGAR: R$ %.2f\n", totalFinal);

      printf("Confirma a compra? (1-Sim, 0-Nao): ");
      int confirm;
      scanf("%d", &confirm);

      if (confirm == 1) {
        gerarNotaFiscal(meuCarrinho, regiaoEscolhida, valorFrete, totalFinal);
        inicializarCarrinho(&meuCarrinho); // Limpa para nova compra
        printf("Pressione ENTER para continuar...");
        limparBufferEntrada();
        getchar();
      } else {
        printf("Compra cancelada.\n");
      }
      break;
    }

    case 5:
      printf("Saindo do sistema...\n");
      break;

    default:
      printf("Opcao invalida!\n");
    }
  }

  return 0;
}
