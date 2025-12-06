#ifndef FLAVIOZON_H
#define FLAVIOZON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* ==========================================================================
 *                          CONSTANTES E MACROS
 * ========================================================================== */

/** Tamanho maximo para nomes de produtos e strings gerais */
#define MAX_NOME 100

/** Quantidade maxima de itens distintos que o carrinho suporta */
#define MAX_ITENS 50

/* ==========================================================================
 *                          ESTRUTURAS DE DADOS
 * ========================================================================== */

/**
 * @brief Enumeração para as regiões de entrega disponiveis.
 * Utilizado para calculo de frete.
 */
typedef enum {
    SUL = 1,
    SUDESTE = 2,
    NORTE = 3,
    NORDESTE = 4
} Regiao;

/**
 * @brief Representa um Produto no catalogo da loja.
 */
typedef struct {
    int id;                 // Identificador unico do produto
    char nome[MAX_NOME];    // Nome comercial do produto
    float preco;            // Preco unitario em Reais (R$)
    float peso;             // Peso unitario em Kg
} Produto;

/**
 * @brief Representa um item selecionado dentro do carrinho de compras.
 * Conecta um produto a uma quantidade desejada.
 */
typedef struct {
    Produto produto;        // Copia dos dados do produto selecionado
    int quantidade;         // Quantidade do item
} ItemCarrinho;

/**
 * @brief Estrutura principal do Carrinho de Compras.
 * Mantem o estado atual da sessao de compra do usuario.
 */
typedef struct {
    ItemCarrinho itens[MAX_ITENS];  // Array fixo de itens
    int qtdProdutos;                // Numero atual de itens distintos no array (0 a MAX_ITENS)
} Carrinho;

/* ==========================================================================
 *                          PROTOTIPOS DE FUNCOES
 * ========================================================================== */

/* --------------------------------------------------------------------------
 * Módulo: PRODUTOS (Responsavel pelo catalogo)
 * -------------------------------------------------------------------------- */

/**
 * @brief Inicializa o catalogo de produtos simulado.
 * 
 * DEVE SER IMPLEMENTADO EM: produtos.c
 * 
 * Detalhes da Implementacao:
 *  - Esta funcao deve preencher um vetor estatico interno (local ao arquivo produtos.c)
 *    com pelo menos 6 produtos pre-definidos.
 *  - Exemplos de produtos: "Robô Gigante", "Pato de Borracha", "Livro C".
 *  - Deve ser chamada no inicio da execucao (na main) para preparar os dados.
 */
void inicializarProdutos();

/**
 * @brief Lista todos os produtos disponiveis no catalogo formatados na tela.
 * 
 * DEVE SER IMPLEMENTADO EM: produtos.c
 * 
 * Detalhes da Implementacao:
 *  - Percorre o catalogo interno e imprime os dados de cada produto.
 *  - Formato sugerido: "ID | Nome | Preco | Peso".
 *  - Deve exibir os precos com duas casas decimais (Ex: R$ 29.90).
 */
void listarProdutos();

/**
 * @brief Busca um produto pelo seu ID unico.
 * 
 * DEVE SER IMPLEMENTADO EM: produtos.c
 * 
 * @param id O ID do produto a ser buscado.
 * @return Produto Retorna a estrutura do produto se encontrado.
 *         Se nao encontrar, deve retornar um Produto com ID = -1 ou similar para indicar erro.
 */
Produto buscarProduto(int id);

/* --------------------------------------------------------------------------
 * Módulo: CARRINHO (Responsavel pela sessao de compra)
 * -------------------------------------------------------------------------- */

/**
 * @brief Inicializa a estrutura do carrinho de compras.
 * 
 * DEVE SER IMPLEMENTADO EM: carrinho.c
 * 
 * Detalhes da Implementacao:
 *  - Define a quantidade de produtos (qtdProdutos) como 0.
 *  - Limpa qualquer lixo de memoria no array de itens se necessario.
 * 
 * @param c Ponteiro para a estrutura Carrinho a ser zerada.
 */
void inicializarCarrinho(Carrinho *c);

/**
 * @brief Adiciona um produto ao carrinho ou incrementa sua quantidade se ja existir.
 * 
 * DEVE SER IMPLEMENTADO EM: carrinho.c
 * 
 * Detalhes da Implementacao:
 *  1. Verifica se o produto ja existe no array `c->itens`.
 *     - Se SIM: Incrementa a quantidade desse item com `quantidade`.
 *     - Se NAO: Verifica se ha espaco no array (< MAX_ITENS).
 *         - Se houver espaco, adiciona o novo produto na posicao `c->qtdProdutos`
 *           e incrementa o contador `c->qtdProdutos`.
 * 
 * @param c Ponteiro para o carrinho.
 * @param p O produto a ser adicionado.
 * @param quantidade A quantidade a ser adicionada.
 * @return int Retorna 1 se sucesso, 0 se erro (ex: carrinho cheio).
 */
int adicionarAoCarrinho(Carrinho *c, Produto p, int quantidade);

/**
 * @brief Exibe o conteudo atual do carrinho.
 * 
 * DEVE SER IMPLEMENTADO EM: carrinho.c
 * 
 * Detalhes da Implementacao:
 *  - Imprime cabecalho "--- SEU CARRINHO ---".
 *  - Lista cada item: Nome, Preco Unitario, Quantidade, Subtotal do item (Preco * Qtd).
 *  - Este modulo NAO calcula o total final nem frete, apenas lista o conteudo.
 *  - Se vazio, imprimir "Carrinho vazio".
 * 
 * @param c Carrinho a ser visualizado.
 */
void visualizarCarrinho(Carrinho c);

/**
 * @brief Permite alterar a quantidade de um item ja existente no carrinho.
 * 
 * DEVE SER IMPLEMENTADO EM: carrinho.c (OPCIONAL/EXTRA)
 * 
 * Detalhes da Implementacao:
 *  - Busca o produto no carrinho pelo ID.
 *  - Atualiza a quantidade para o novo valor.
 *  - Se a nova quantidade for 0, pode remover o item (deslocando o array).
 * 
 * @param c Ponteiro para o carrinho.
 * @param idProduto ID do produto a ser alterado.
 * @param novaQuantidade Nova quantidade desejada.
 * @return int 1 se sucesso, 0 se produto nao encontrado.
 */
int atualizarQuantidadeCarrinho(Carrinho *c, int idProduto, int novaQuantidade);

/**
 * @brief Calcula o preco total dos itens no carrinho (Sem Frete).
 * 
 * DEVE SER IMPLEMENTADO EM: carrinho.c
 * 
 * Detalhes da Implementacao:
 *  - Soma (Preco * Quantidade) de todos os itens.
 * 
 * @param c Carrinho a ser calculado.
 * @return float O valor total em Reais.
 */
float calcularTotalCarrinho(Carrinho c);

/**
 * @brief Calcula o peso total de todos os produtos no carrinho (para calculo de frete).
 * 
 * DEVE SER IMPLEMENTADO EM: carrinho.c (Funcao auxiliar para o modulo Frete)
 * 
 * Detalhes da Implementacao:
 *  - Soma (Peso * Quantidade) de todos os itens.
 * 
 * @param c Carrinho para calculo.
 * @return float Peso total em Kg.
 */
float calcularPesoTotalCarrinho(Carrinho c);

/* --------------------------------------------------------------------------
 * Módulo: FRETE (Responsavel pela logistica)
 * -------------------------------------------------------------------------- */

/**
 * @brief Calcula o valor do frete baseado na regiao e no peso total.
 * 
 * DEVE SER IMPLEMENTADO EM: frete.c
 * 
 * Tabela de Precos (Baseada no PDF/README):
 *  - SUL (1):      Leve(<=2kg)=30.00, Pesado(>2kg)=50.00
 *  - SUDESTE (2):  Leve(<=2kg)=25.00, Pesado(>2kg)=45.00
 *  - NORTE (3):    Leve(<=2kg)=35.00, Pesado(>2kg)=55.00
 *  - NORDESTE (4): Leve(<=2kg)=40.00, Pesado(>2kg)=60.00
 * 
 * @param regiao Enum da regiao escolhida pelo usuario.
 * @param pesoTotal Peso total somado do carrinho.
 * @return float Valor do frete em Reais.
 */
float calcularFrete(Regiao regiao, float pesoTotal);

/**
 * @brief Auxiliar para obter o nome da regiao em string.
 * util para impressao no relatorio final.
 * 
 * @param regiao Enum da regiao.
 * @return const char* Nome da regiao (ex: "Sudeste").
 */
const char* obterNomeRegiao(Regiao regiao);

/* --------------------------------------------------------------------------
 * Módulo: RELATORIO (Responsavel pelo fechamento e arquivos)
 * -------------------------------------------------------------------------- */

/**
 * @brief Gera a nota fiscal final e salva em arquivo.
 * 
 * DEVE SER IMPLEMENTADO EM: relatorio.c
 * 
 * Detalhes da Implementacao:
 *  1. Obtem a data/hora atual do sistema (time.h).
 *  2. Calcula uma data estimada de entrega (ex: Data Atual + X dias).
 *  3. Cria um arquivo de saida (sugestao: "NF_<random>.txt" ou "resumo_compra.txt").
 *  4. Escreve no arquivo:
 *     - Cabecalho FLAVIOZON.
 *     - Detalhes de cada item comprado.
 *     - Subtotal, Valor do Frete e Total Final.
 *     - Dados de entrega (Regiao, previsao).
 *  5. Exibe uma mensagem de sucesso na tela com o nome do arquivo gerado.
 * 
 * @param c O carrinho finalizado.
 * @param regiao A regiao de entrega selecionada.
 * @param valorFrete O custo calculado do frete.
 * @param valorTotal O custo total da compra (Itens + Frete).
 */
void gerarNotaFiscal(Carrinho c, Regiao regiao, float valorFrete, float valorTotal);

#endif // FLAVIOZON_H
