/* =========================================================================
 * Arquivo: produtos.c
 * Objetivo: Implementação do módulo de catálogo de produtos.
 *
 * Autoria:
 *   Nome:      [NOME DO ESTUDANTE AQUI]
 *   Matrícula: [MATRICULA AQUI]
 *   Data:      2025-12-06
 * ========================================================================= */

#include "flaviozon.h"

// Banco de dados interno (simulado)
static Produto catalogo[10];
static int totalProdutosCatalogo = 0;

void inicializarProdutos() {
  // Produto 1
  catalogo[0].id = 1;
  strcpy(catalogo[0].nome, "Robô Gigante");
  catalogo[0].preco = 250000.00;
  catalogo[0].peso = 15000.0;

  // Produto 2
  catalogo[1].id = 2;
  strcpy(catalogo[1].nome, "Pato de Borracha");
  catalogo[1].preco = 15.90;
  catalogo[1].peso = 0.1;

  // Produto 3
  catalogo[2].id = 3;
  strcpy(catalogo[2].nome, "Livro C Avançado");
  catalogo[2].preco = 89.90;
  catalogo[2].peso = 0.8;

  // Produto 4
  catalogo[3].id = 4;
  strcpy(catalogo[3].nome, "Monitor 24pol");
  catalogo[3].preco = 1200.00;
  catalogo[3].peso = 3.5;

  // Produto 5
  catalogo[4].id = 5;
  strcpy(catalogo[4].nome, "Teclado Mecânico");
  catalogo[4].preco = 350.00;
  catalogo[4].peso = 1.2;

  // Produto 6
  catalogo[5].id = 6;
  strcpy(catalogo[5].nome, "Mouse Gamer");
  catalogo[5].preco = 180.00;
  catalogo[5].peso = 0.2;

  totalProdutosCatalogo = 6;
  printf("\n[PRODUTOS] Catálogo inicializado com %d produtos.\n",
         totalProdutosCatalogo);
}

void listarProdutos() {
  printf("\n=== CATALOGO DE PRODUTOS ===\n");
  printf("ID  | Preco       | Peso(kg) | Nome\n");
  printf("----------------------------------------------------\n");
  for (int i = 0; i < totalProdutosCatalogo; i++) {
    printf("%03d | R$ %8.2f | %8.2f | %s\n", catalogo[i].id, catalogo[i].preco,
           catalogo[i].peso, catalogo[i].nome);
  }
  printf("----------------------------------------------------\n");
}

Produto buscarProduto(int id) {
  Produto erro;
  erro.id = -1; // Flag de erro

  for (int i = 0; i < totalProdutosCatalogo; i++) {
    if (catalogo[i].id == id) {
      return catalogo[i];
    }
  }
  return erro;
}
