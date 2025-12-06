# Projeto Integrado: E-Commerce "Fláviozon"

Bem-vindo ao guia oficial do projeto final. Este documento descreve a arquitetura, as regras de negócio e a especificação técnica para o desenvolvimento do sistema de E-commerce modular em C.

## 🎯 Objetivo

Desenvolver um sistema de loja virtual console-based utilizando a linguagem C, focado em **modularização**, **manipulação de arquivos** e **estruturas de dados heterogêneas**.

O sistema simula o fluxo de compras de uma loja ("Fláviozon"), desde a seleção de produtos até a geração da nota fiscal com cálculo de frete.

## 🏗️ Arquitetura do Sistema

Para garantir a organização e permitir o trabalho em paralelo, o sistema foi dividido em **5 módulos independentes**, conectados por um arquivo de cabeçalho comum (`flaviozon.h`).

## 🔗 Recursos de Estudo e Documentação

Para quem está começando ou precisa relembrar conceitos de C, aqui estão links essenciais:

* **Tutoriais Básicos**:
  * [W3Schools: Tutorial de C](https://www.w3schools.com/c/index.php) (Excelente para iniciantes)
  * [GeeksforGeeks: C Programming](https://www.geeksforgeeks.org/c-programming-language/) (Muito completo)
  * [Cprogramming.com](https://www.cprogramming.com/)

* **Referências de Funções**:
  * [CPPReference (C headers)](https://en.cppreference.com/w/c/header)
  * `stdio.h` (printf, scanf): [Detalhes](https://cplusplus.com/reference/cstdio/)
  * `string.h` (strcpy, strcmp): [Detalhes](https://cplusplus.com/reference/cstring/)
  * `stdlib.h` (malloc, rand): [Detalhes](https://cplusplus.com/reference/cstdlib/)

### Estrutura de Arquivos

```text
/projeto
├── flaviozon.h      # [Contrato] Definições globais, structs e protótipos
├── main.c           # [Guardião] Menu principal e fluxo do programa
├── produtos.c       # [Estoque] Gestão do catálogo de produtos
├── carrinho.c       # [Compras] Gestão da sacola de compras
├── frete.c          # [Logística] Cálculo de custos de envio
└── relatorio.c      # [Fiscal] Geração de Nota Fiscal e arquivos
```

---

## 📚 Definições Globais (`flaviozon.h`)

Este arquivo deve conter todas as `structs` e `defines` compartilhados. Nenhuma variável global deve ser criada aqui, apenas definições de tipos.

### Principais Estruturas

1. **`Produto`**: Representa um item da loja.
    * ID (int)
    * Nome (string)
    * Preço (float)
    * Peso em Kg (float)
2. **`Carrinho`**: Armazena o estado atual da compra.
    * Array de Itens (quantidade máxima definida por `#define MAX_ITENS`)
    * Quantidade total de produtos incluídos
3. **`Regiao`** (Enum ou Int): Mapeia as regiões para cálculo de frete.
    * 1 = Sul
    * 2 = Sudeste
    * 3 = Norte
    * 4 = Nordeste

---

## 🛠️ Especificação dos Módulos

Cada integrante é responsável por implementar um dos módulos abaixo. As assinaturas das funções devem seguir estritamente o definido no `flaviozon.h`.

### 1. Módulo Main (`main.c`)

**Responsabilidade**: Ponto de entrada e orquestração.

* Deve inicializar os dados necessários.
* Exibir um **Menu Interativo** em loop:
    1. Listar Produtos
    2. Adicionar ao Carrinho
    3. Visualizar Carrinho
    4. Finalizar Compra
    5. Sair
* Capturar a entrada do usuário e chamar as funções dos outros módulos.
* Tratar erros básicos de entrada.

> **Dica de Implementação**: Use um loop `do-while` para manter o menu rodando até a pessoa escolher "Sair". Lembre-se de limpar o "buffer" do teclado após ler números com `scanf` antes de ler strings, para evitar pular leituras.

### 2. Módulo Produtos (`produtos.c`)

**Responsabilidade**: Banco de dados (Simulado) e Exibição.

* **Inicialização**: Deve preencher um vetor estático com pelo menos 6 produtos pré-definidos (ex: "Robô Gigante", "Pato de Borracha", "Livro C Avançado").
* **Listagem**: Função para imprimir todos os produtos formatados (Nome | Preço | ID).
* **Busca**: Função que recebe um ID e retorna os dados do produto (ou erro se não existir).

> **Dica de Implementação**: Você não precisa de banco de dados real. Crie um vetor global `static Produto catalogo[6]` dentro do arquivo `produtos.c` e preencha os dados manualmente linha por linha na função de inicialização.

### 3. Módulo Carrinho (`carrinho.c`)

**Responsabilidade**: Lógica de sessão de compra.

* **Adicionar**: Recebe um produto e quantidade. Se o produto já existir no carrinho, apenas incrementa a quantidade. Se não, adiciona na próxima posição livre.
* **Remover (Opcional)**: Remove um item do array.
* **Totalização**: Percorre o array calculando a soma `(preço * quantidade)` de todos os itens.

> **Dica de Implementação**: O carrinho tem um contador `qtdProdutos`. Ao adicionar um item novo, você o coloca na posição `itens[qtdProdutos]` e depois aumenta esse contador (`qtdProdutos++`). Cuidado para não estourar o limite `MAX_ITENS`.

### 4. Módulo Frete (`frete.c`)

**Responsabilidade**: Regras de negócio de logística.

* Deve solicitar ao usuário o destino (Região).
* **Tabela de Preços (Conforme PDF)**:

    | Região | Frete Padrão (<= 2Kg) | Frete Pesado (> 2Kg) |
    | :--- | :--- | :--- |
    | **Sul (1)** | R$ 30,00 | R$ 50,00 |
    | **Sudeste (2)** | R$ 25,00 | R$ 45,00 |
    | **Norte (3)** | R$ 35,00 | R$ 55,00 |
    | **Nordeste (4)** | R$ 40,00 | R$ 60,00 |

* **Entrada**: Recebe o peso total do carrinho e a região.
* **Saída**: Retorna o valor do frete (float).

### 5. Módulo Relatório (`relatorio.c`)

**Responsabilidade**: Persistência de dados e Saída final.

* Deve utilizar a biblioteca `<time.h>` para pegar a data/hora atual.
* Calcular data simulada de entrega (sempre posterior à data atual).
* **Gerar Arquivo**: Criar um arquivo (ex: `resumo_compra.txt`) contendo:
  * Código, Nome, Peso e Preço de cada produto.
  * Local de Entrega (Região).
  * Preço do Frete, Preço Total.
  * Data/Hora da Compra e Data Prevista de Entrega.

> **Dica de Implementação**: Pesquise sobre `fopen` (modo "w" para escrita), `fprintf` (funciona igual ao `printf` mas escreve no arquivo) e `fclose`. Não esqueça de fechar o arquivo no final!

---

## 🚀 Instruções de Compilação

Para compilar o projeto completo, todos os arquivos `.c` devem ser passados para o compilador `gcc`:

```bash
gcc main.c produtos.c carrinho.c frete.c relatorio.c -o flaviozon
```

Para rodar:

```bash
./flaviozon
```

## 📝 Dicas para os Desenvolvedores

* **Commite sempre**: Usem Git para versionar.
* **Testem isoladamente**: Antes de juntar com o `main.c`, crie uma `main` temporária no seu arquivo só para testar se sua função faz o que deve.
* **Comentários**: Documentem o código para facilitar a leitura pelos colegas.

---
*Bom código a todos!*
