#include <stdio.h>
#include "../inc/huff_tree.h"

#ifndef TABLE_H
#define TABLE_H

  typedef struct bit_node BitNode;

  typedef struct table Table;


  /*
  Função que cria uma tabela
  Recebe - int : o tamanho da tabela
  Retorna - Table* : a tabela criada
  */
  Table* create_table(int size);
  

  /*
  Cria um nó do tipo BitNode
  Recebe - char : o bit representado por um char, pode ser 0 ou 1
  Retorna - BitNode* : o nó do tipo BitNode
  */
  BitNode* create_bit_node(char item);


  /*
  Função que adiciona um nó do tipo BitNode a uma lista da tabela
  Recebe 
    - Table* : a tabela que contem todas as listas de BitNodes
    - unsigned char : a posição da tabela a qual o nó será adicionado
    - char : o bit que será adicionado (0 ou 1)
  */
  void add_to_list(Table* list, unsigned char position, char bit);
  

  /*
  Função que preenche a tabela com o binário de huffman de cada byte(caractere)
  Recebe
    - Node* : a arvore de huffman
    - Table* : a tabela que será preenchida
    - char* : uma string vazia com tamanho suficiente da maxima altura da arvore(17)
    - char* : outra string vazia que será usada para concatenar com a outra
  Retorna - void (só preenche a tabela)
  */
  void fill_table(Node* bt, Table* table, char* code, char* string);


  /*
  Função que escreve os bytes(caracteres) codificados no arquivo
  Recebe
    - unsigned char* : os bytes do arquivo em formato de char
    - size_t : o tamanho do arquivo
    - FILE* : o arquivo de destino
    - Table* : a tabela com os bytes codificados em formato de lista
  Retorna - int : o tamanho do lixo
  */
  int write_in_file(unsigned char *file_content, size_t file_size, FILE *dest_file, Table* table);


  /*
  Função que imprime a tabela de caracteres codificados pela arvore de huffman(utilizada para testes)
  Recebe
    - Table* : a tabela
    - int : o tamanho da tabela
  Retorna - void
  */
  void print_table(Table* table, int size);

  //Dá free na tabela
  void free_table(Table *table, int size);

#endif
