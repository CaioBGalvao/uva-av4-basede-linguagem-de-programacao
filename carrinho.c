/* =========================================================================
 * Arquivo: carrinho.c
 * Objetivo: Implementação da lógica do carrinho de compras.
 *
 * Autoria:
 *   Nome:      [NOME DO ESTUDANTE AQUI]
 *   Matrícula: [MATRICULA AQUI]
 *   Data:      2025-12-06
 * ========================================================================= */

#include "flaviozon.h"

void inicializarCarrinho(Carrinho *c) {
  c->qtdProdutos = 0;
  // Opcional: zerar memória do array para segurança, mas apenas zerar o
  // contador já basta logicaente
  memset(c->itens, 0, sizeof(c->itens));
  printf("[CARRINHO] Carrinho inicializado.\n");
}

int adicionarAoCarrinho(Carrinho *c, Produto p, int quantidade) {
  if (quantidade <= 0)
    return 0;

  // 1. Verifica se já existe
  for (int i = 0; i < c->qtdProdutos; i++) {
    if (c->itens[i].produto.id == p.id) {
      c->itens[i].quantidade += quantidade;
      return 1;
    }
  }

  // 2. Se não existe, adiciona novo
  if (c->qtdProdutos < MAX_ITENS) {
    c->itens[c->qtdProdutos].produto = p;
    c->itens[c->qtdProdutos].quantidade = quantidade;
    c->qtdProdutos++;
    return 1;
  }

  // Carrinho cheio
  return 0;
}

void visualizarCarrinho(Carrinho c) {
  printf("\n--- SEU CARRINHO ---\n");
  if (c.qtdProdutos == 0) {
    printf("Carrinho vazio.\n");
    return;
  }

  float subtotalGeral = 0;
  for (int i = 0; i < c.qtdProdutos; i++) {
    float subtotalItem = c.itens[i].produto.preco * c.itens[i].quantidade;
    subtotalGeral += subtotalItem;
    printf("%d x %s (R$ %.2f) = R$ %.2f\n", c.itens[i].quantidade,
           c.itens[i].produto.nome, c.itens[i].produto.preco, subtotalItem);
  }
  printf("Total Parcial: R$ %.2f\n", subtotalGeral);
  printf("--------------------\n");
}

int atualizarQuantidadeCarrinho(Carrinho *c, int idProduto,
                                int novaQuantidade) {
  for (int i = 0; i < c->qtdProdutos; i++) {
    if (c->itens[i].produto.id == idProduto) {
      if (novaQuantidade <= 0) {
        // Remover item (deslocar array)
        for (int j = i; j < c->qtdProdutos - 1; j++) {
          c->itens[j] = c->itens[j + 1];
        }
        c->qtdProdutos--;
      } else {
        c->itens[i].quantidade = novaQuantidade;
      }
      return 1;
    }
  }
  return 0; // Produto não encontrado
}

float calcularTotalCarrinho(Carrinho c) {
  float total = 0;
  for (int i = 0; i < c.qtdProdutos; i++) {
    total += c.itens[i].produto.preco * c.itens[i].quantidade;
  }
  return total;
}

float calcularPesoTotalCarrinho(Carrinho c) {
  float pesoTotal = 0;
  for (int i = 0; i < c.qtdProdutos; i++) {
    pesoTotal += c.itens[i].produto.peso * c.itens[i].quantidade;
  }
  return pesoTotal;
}
