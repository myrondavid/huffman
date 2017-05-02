# Projeto de estrutura de dados do curso de ciência da computação do Instituto de Computação - UFAL

O projeto se divide em módulos sendo eles:
  1. Seminário sobre Self-Organizing Lists
  2. Implementação do algorítimo de Huffman
  3. Contagem e plotagem da comparação entre duas estruturas de dados: Listas vs. Árvore de Busca Binária
  4. Testes unitários para uma estrutura de dados: Fila de Prioridades

* ## Instruções para compilação e execução dos módulos
  * Cada módulo, com exceção do 1 possuem um Makefile e podem ser compilados com o utilitário Make.
  * Requisitos para compilação: 
    * Compilador GCC
    * Utilitário Make (pode ser compilado sem utilização do make, porém é recomendada sua utilização para facilitar o procedimento de compilação)
    * R (Para plotagem)
    * CUnit (Para testes unitários)
  * Como compilar usando MAKE:
    * Para o huffman:
      * Utilizando o terminal, entre no diretório 2 e digite "make compile", o utilitário irá gerar o executável main
    * Para a comparação de estruturas:
      * Utilizando o terminal, entre no diretório 3 e digite "make compile_all", o utilitário irá gerar o executável main
      * Para plotar os gráficos, digite "make plot_graph"
    * Para os testes unitários:
      * Utilizando o terminal, entre no diretório 4 e digite "make compile", o utilitário irá gerar o executável main_tests
  
