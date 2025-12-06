/* =========================================================================
 * Arquivo: frete.c
 * Objetivo: Implementação do módulo de cálculo de frete.
 *
 * Autoria:
 *   Nome:      [NOME DO ESTUDANTE AQUI]
 *   Matrícula: [MATRICULA AQUI]
 *   Data:      2025-12-06
 * ========================================================================= */

#include "flaviozon.h"

float calcularFrete(Regiao regiao, float pesoTotal) {
  float valorFrete = 0.0;
  int isPesado = (pesoTotal > 2.0); // Se > 2kg é pesado

  switch (regiao) {
  case SUL:
    valorFrete = isPesado ? 50.00 : 30.00;
    break;
  case SUDESTE:
    valorFrete = isPesado ? 45.00 : 25.00;
    break;
  case NORTE:
    valorFrete = isPesado ? 55.00 : 35.00;
    break;
  case NORDESTE:
    valorFrete = isPesado ? 60.00 : 40.00;
    break;
  default:
    printf("[ERRO] Região inválida para cálculo!\n");
    return 0.0;
  }

  return valorFrete;
}

const char *obterNomeRegiao(Regiao regiao) {
  switch (regiao) {
  case SUL:
    return "Sul";
  case SUDESTE:
    return "Sudeste";
  case NORTE:
    return "Norte";
  case NORDESTE:
    return "Nordeste";
  default:
    return "Desconhecida";
  }
}
