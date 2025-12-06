/* =========================================================================
 * Arquivo: produtos.c
 * Objetivo: Implementação do módulo de catálogo de produtos.
 *
 * Autoria:
 *   Nome: Gabriel Bittencourt
 *   Matrícula: 1250111508
 *   Data:      2025-12-13
 * ========================================================================= */
#include "flaviozon.h"

static Produto catalogo[10];
static int total_produtos = 0;
//-------------------------------------------------------
// Inicializacao do Banco de Dados
//-------------------------------------------------------
void inicializarProdutos() {
    catalogo[0].id= 1;
    strcpy(catalogo[0].nome, "Jordan 4 Retro Black Cat");
    catalogo[0].preco = 1300.00;
    catalogo[0].peso = 1.2; //kg

    catalogo[1].id= 2;
    strcpy(catalogo[1].nome, "Jordan 1 Retro High OG");
    catalogo[1].preco = 1100.00;
    catalogo[1].peso = 0.9; //kg

    catalogo[2].id= 3;
    strcpy(catalogo[2].nome, "Jordan 1 Retro Low OG SP");
    catalogo[2].preco = 2100.00;
    catalogo[2].peso = 0.750; //kg

    catalogo[3].id= 4;
    strcpy(catalogo[3].nome, "Jordan 5 Retro");
    catalogo[3].preco = 900.00;
    catalogo[3].peso = 1; //kg

    catalogo[4].id= 5;
    strcpy(catalogo[4].nome, "Jordan 4 Retro Metallic Gold (Women's");
    catalogo[4].preco = 1000.00;
    catalogo[4].peso = 1; //kg

    catalogo[5].id= 6;
    strcpy(catalogo[5].nome, "Jordan 4 Retro Mist Blue");
    catalogo[5].preco = 4000.00;
    catalogo[5].peso = 1; //kg

    catalogo[6].id= 7;
    strcpy(catalogo[6].nome, "Jordan 1 Low OG Obsidian UNC");
    catalogo[6].preco = 500.00;
    catalogo[6].peso = 1; //kg

    catalogo[7].id= 8;
    strcpy(catalogo[7].nome, "Nike Air Force 1 Low Kobe Bryant Court Purple");
    catalogo[7].preco = 700.00;
    catalogo[7].peso = 1; //kg

    catalogo[8].id= 9;
    strcpy(catalogo[8].nome, "Nike Air Force 1 Low LX Leaf Camo");
    catalogo[8].preco = 800.00;
    catalogo[8].peso = 1; //kg

    catalogo[9].id= 10;
    strcpy(catalogo [9].nome, "Nike Air Force 1 Low '07 LV8 Bred");
    catalogo[9].preco = 600.00;
    catalogo[9].peso = 1; //kg

}
//-------------------------------------------------------
//Listagem de produtos
//-------------------------------------------------------
void listarProdutos() {
    printf("\n===== LISTA DE PRODUTOS =====\n");
    printf( "Nome, Preco, Peso (kg)");

    for (int i = 0 ; i < total_produtos ; i++) {
        printf ("%03d | %s | R$ %8.2f | %8.2f kg\n",
        catalogo[i].id,
        catalogo[i].nome,
        catalogo[i].preco,
        catalogo[i].peso);

    }
}

//------------------------------------------------------
// Busca por ID - Retorna ponteiro para um produto ou NULL
//------------------------------------------------------

Produto buscarProdutoID(int id) {
    for (int i = 0 ; i < total_produtos ; i++) {
        if (catalogo[i].id == id) {
            return catalogo[i];
        }
    }

}