/* =========================================================================
 * Arquivo: frete.c
 * Objetivo: Implementação do módulo de cálculo de frete.
 *
 * Autoria:
 *   Nome:      Guilherme Brazil Nascimento
 *   Matrícula: 1250203978
 *   Data:      2025-12-06
 * ========================================================================= */
#include "flaviozon.h"

//
// FUNÇÕES DO MÓDULO FRETE
//

/**
 * @brief Calcula o valor do frete com base na região e no peso total.
 */
float calcularFrete(Regiao regiao, float pesoTotal) {

  // Validação de peso negativo
  if (pesoTotal < 0) {
    return 0.0;
  }

  float frete = 0;
  int isPesado = (pesoTotal > 2.0);

  switch (regiao) {
  case SUL:
    // <= 2kg: R$ 30,00 | > 2kg: R$ 50,00
    frete = isPesado ? 50.0 : 30.0;
    break;

  case SUDESTE:
    // <= 2kg: R$ 25,00 | > 2kg: R$ 45,00
    frete = isPesado ? 45.0 : 25.0;
    break;

  case NORTE:
    // <= 2kg: R$ 35,00 | > 2kg: R$ 55,00
    frete = isPesado ? 55.0 : 35.0;
    break;

  case NORDESTE:
    // <= 2kg: R$ 40,00 | > 2kg: R$ 60,00
    frete = isPesado ? 60.0 : 40.0;
    break;

  default:
    printf("[ERRO] Regiao invalida para calculo!\n");
    frete = -1.0;
  }

  return frete;
}

/**
 * @brief Retorna o nome da região para ser usado na Nota Fiscal.
 */
const char *obterNomeRegiao(Regiao regiao) {
  switch (regiao) {
  case SUL:
    return "Sul"; // Aspas retas corrigidas
  case SUDESTE:
    return "Sudeste";
  case NORTE:
    return "Norte";
  case NORDESTE:
    return "Nordeste";
  default:
    return "Regiao Invalida";
  }
}