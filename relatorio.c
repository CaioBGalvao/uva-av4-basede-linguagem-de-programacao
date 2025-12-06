/* =========================================================================
 * Arquivo: relatorio.c
 * Objetivo: Implementação da geração de Nota Fiscal e arquivos.
 *
 * Autoria:
 *   Nome:      [NOME DO ESTUDANTE AQUI]
 *   Matrícula: [MATRICULA AQUI]
 *   Data:      2025-12-06
 * ========================================================================= */

#include "flaviozon.h"

void gerarNotaFiscal(Carrinho c, Regiao regiao, float valorFrete,
                     float valorTotal) {
  FILE *arquivo;
  char nomeArquivo[50];

  // Gera nome único simples baseado em timestamp ou randômico
  // Para simplificar, usaremos um estático ou randômico simples
  srand(time(NULL));
  int idNota = rand() % 10000;
  sprintf(nomeArquivo, "NF_%04d.txt", idNota);

  arquivo = fopen(nomeArquivo, "w");
  if (arquivo == NULL) {
    printf("Erro ao criar arquivo de nota fiscal!\n");
    return;
  }

  // Obter data atual
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  // Calcular "Previsão de Entrega" (Data atual + 5 dias)
  // Nota: Lógica simplificada de data
  struct tm tmEntrega = tm;
  tmEntrega.tm_mday += 5;
  mktime(&tmEntrega); // Normaliza a data

  fprintf(arquivo, "=================================================\n");
  fprintf(arquivo, "                 FLAVIOZON - NOTA FISCAL         \n");
  fprintf(arquivo, "=================================================\n");
  fprintf(arquivo, "Data da Compra: %02d/%02d/%d %02d:%02d\n", tm.tm_mday,
          tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
  fprintf(arquivo, "Previsao Entrega: %02d/%02d/%d\n", tmEntrega.tm_mday,
          tmEntrega.tm_mon + 1, tmEntrega.tm_year + 1900);
  fprintf(arquivo, "Destino: %s\n", obterNomeRegiao(regiao));
  fprintf(arquivo, "-------------------------------------------------\n");
  fprintf(arquivo, "ITENS:\n\n");

  for (int i = 0; i < c.qtdProdutos; i++) {
    fprintf(arquivo, "[%03d] %-20s | Qtd: %d | R$ %.2f\n",
            c.itens[i].produto.id, c.itens[i].produto.nome,
            c.itens[i].quantidade,
            c.itens[i].produto.preco * c.itens[i].quantidade);
  }

  fprintf(arquivo, "-------------------------------------------------\n");
  fprintf(arquivo, "Subtotal Itens: R$ %.2f\n", valorTotal - valorFrete);
  fprintf(arquivo, "Frete:          R$ %.2f\n", valorFrete);
  fprintf(arquivo, "TOTAL FINAL:    R$ %.2f\n", valorTotal);
  fprintf(arquivo, "=================================================\n");
  fprintf(arquivo, "Obrigado pela preferencia!\n");

  fclose(arquivo);

  printf("\n[SUCESSO] Compra finalizada!\n");
  printf("Nota Fiscal gerada em: %s\n", nomeArquivo);
}
