/* =========================================================================
 * Arquivo: carrinho.c
 * Objetivo: Implementação da lógica do carrinho de compras.
 *
 * Autoria:
 *   Nome:      Wallace Calisto da Silva Santos
 *   Matrícula: 1250115639
 *   Data:      2025-12-13
 * ========================================================================= */
#include <stdio.h>
#include <string.h> // Necessario para o memset
#include "flaviozon.h"

//-------------------------------------------------------
// Inicializa o carrinho limpando a memoria
//-------------------------------------------------------
void inicializarCarrinho(Carrinho *c) {
    // Garante que o array comece zerado para evitar lixo de memoria
    memset(c->itens, 0, sizeof(c->itens));
    c->qtdProdutos = 0;
}

//-------------------------------------------------------
// Adiciona produto ou soma quantidade (Retorna 1 se ok, 0 se erro)
//-------------------------------------------------------
int adicionarAoCarrinho(Carrinho *c, Produto p, int quantidade) {
    int i;

    // Verifica se a quantidade e valida
    if (quantidade <= 0) {
        return 0; // Erro: Quantidade invalida
    }

    // Procura se o produto ja existe no carrinho
    for (i = 0; i < c->qtdProdutos; i++) {
        if (c->itens[i].produto.id == p.id) {
            // Se achou, so atualiza a quantidade
            c->itens[i].quantidade += quantidade;
            return 1; // Sucesso
        }
    }

    // Se nao achou, verifica se ainda cabe no carrinho
    if (c->qtdProdutos >= MAX_ITENS) {
        return 0; // Erro: Carrinho cheio
    }

    // Adiciona o produto novo na proxima posicao livre
    int posicao = c->qtdProdutos;
    c->itens[posicao].produto = p;
    c->itens[posicao].quantidade = quantidade;
    
    c->qtdProdutos++; // Aumenta o contador de itens

    return 1; // Sucesso
}

//-------------------------------------------------------
// Mostra a lista de produtos e o total
//-------------------------------------------------------
void visualizarCarrinho(Carrinho c) {
    int i;
    
    printf("\n===== SEU CARRINHO =====\n");

    if (c.qtdProdutos == 0) {
        printf("Carrinho vazio.\n");
    } else {
        printf("Item | Preco Unit. | Qtd | Subtotal\n");
        
        for (i = 0; i < c.qtdProdutos; i++) {
            Produto p = c.itens[i].produto;
            int qtd = c.itens[i].quantidade;
            float subtotal = p.preco * qtd;

            printf("%d. %s | R$ %.2f | %d | R$ %.2f\n", 
                   i + 1, p.nome, p.preco, qtd, subtotal);
        }
    }
    
    // Calcula e mostra o total geral da compra
    float totalGeral = calcularTotalCarrinho(c);
    printf("------------------------\n");
    printf("TOTAL DA COMPRA: R$ %.2f\n", totalGeral);
    printf("========================\n");
}

//-------------------------------------------------------
// Calcula o valor total em Reais (Soma tudo)
//-------------------------------------------------------
float calcularTotalCarrinho(Carrinho c) {
    float total = 0.0;
    int i;
    
    for (i = 0; i < c.qtdProdutos; i++) {
        total += (c.itens[i].produto.preco * c.itens[i].quantidade);
    }
    
    return total;
}

//-------------------------------------------------------
// Calcula o peso total em Kg (Para o Frete)
//-------------------------------------------------------
float calcularPesoTotalCarrinho(Carrinho c) {
    float pesoTotal = 0.0;
    int i;

    for (i = 0; i < c.qtdProdutos; i++) {
        pesoTotal += (c.itens[i].produto.peso * c.itens[i].quantidade);
    }

    return pesoTotal;
}

//-------------------------------------------------------
// Atualiza quantidade ou remove se for zero
//-------------------------------------------------------
int atualizarQuantidadeCarrinho(Carrinho *c, int idProduto, int novaQuantidade) {
    int i, j;

    for (i = 0; i < c->qtdProdutos; i++) {
        // Procura o produto pelo ID
        if (c->itens[i].produto.id == idProduto) {
            
            // Se for zero ou menos, remove do array
            if (novaQuantidade <= 0) {
                // Puxa os itens da frente para tras para tapar o buraco
                for (j = i; j < c->qtdProdutos - 1; j++) {
                    c->itens[j] = c->itens[j + 1];
                }
                c->qtdProdutos--; // Diminui o tamanho do carrinho
            } 
            else {
                // Se for maior que zero, apenas atualiza
                c->itens[i].quantidade = novaQuantidade;
            }
            return 1; // Sucesso
        }
    }
    return 0; // Erro: Nao achou o produto
}