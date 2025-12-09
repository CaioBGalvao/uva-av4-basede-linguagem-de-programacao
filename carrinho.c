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
#include "flaviozon.h"

//-------------------------------------------------------
// Funcao para zerar o carrinho no inicio
//-------------------------------------------------------
void inicializarCarrinho(Carrinho *c) {
    c->qtdProdutos = 0;
}

//-------------------------------------------------------
// Adiciona produto ou aumenta quantidade se ja tiver
//-------------------------------------------------------
int adicionarAoCarrinho(Carrinho *c, Produto p, int quantidade) {
    int i;
    int ja_existe = 0; // Variavel pra saber se achou o item

    // Primeiro varre o carrinho pra ver se o produto ja ta la
    for (i = 0; i < c->qtdProdutos; i++) {
        if (c->itens[i].produto.id == p.id) {
            c->itens[i].quantidade = c->itens[i].quantidade + quantidade;
            printf("Produto ja estava no carrinho. Nova quantidade: %d\n", c->itens[i].quantidade);
            ja_existe = 1; // Marca que encontrou
            break; // Para o loop
        }
    }

    // Se nao existia, vamos tentar adicionar
    if (ja_existe == 0) {
        // Verifica se o carrinho ta cheio antes
        if (c->qtdProdutos >= MAX_ITENS) {
            printf("Erro: O carrinho esta cheio!\n");
            return 0; // Retorna 0 indicando erro
        }
        
        // Se tem espaco, adiciona no final
        int posicao = c->qtdProdutos;
        c->itens[posicao].produto = p;
        c->itens[posicao].quantidade = quantidade;
        
        c->qtdProdutos++; // Aumenta o contador de itens
        printf("Produto %s adicionado!\n", p.nome);
    }

    return 1; // Deu tudo certo
}

//-------------------------------------------------------
// Mostra na tela o que tem no carrinho
//-------------------------------------------------------
void visualizarCarrinho(Carrinho c) {
    int i;
    
    printf("\n===== SEU CARRINHO =====\n");

    if (c.qtdProdutos == 0) {
        printf("Carrinho vazio.\n");
    } else {
        printf("Item | Preco | Qtd | Total Item\n");
        
        for (i = 0; i < c.qtdProdutos; i++) {
            // Pegando os dados pra ficar mais facil de ler
            Produto p = c.itens[i].produto;
            int qtd = c.itens[i].quantidade;
            float total_item = p.preco * qtd;

            printf("%d. %s | R$ %.2f | %d | R$ %.2f\n", 
                   i + 1, p.nome, p.preco, qtd, total_item);
        }
    }
    printf("------------------------\n");
}

//-------------------------------------------------------
// Soma o preco de tudo
//-------------------------------------------------------
float calcularTotalCarrinho(Carrinho c) {
    float total = 0.0;
    int i;
    
    for (i = 0; i < c.qtdProdutos; i++) {
        float valor = c.itens[i].produto.preco * c.itens[i].quantidade;
        total = total + valor;
    }
    
    return total;
}

//-------------------------------------------------------
// Calcula o peso total (o modulo de frete vai usar isso)
//-------------------------------------------------------
float calcularPesoTotalCarrinho(Carrinho c) {
    float peso_total = 0.0;
    int i;

    for (i = 0; i < c.qtdProdutos; i++) {
        float peso_item = c.itens[i].produto.peso * c.itens[i].quantidade;
        peso_total = peso_total + peso_item;
    }

    return peso_total;
}

//-------------------------------------------------------
// Funcao extra (ainda nao implementada)
//-------------------------------------------------------
int atualizarQuantidadeCarrinho(Carrinho *c, int idProduto, int novaQuantidade) {
    return 0; 
}