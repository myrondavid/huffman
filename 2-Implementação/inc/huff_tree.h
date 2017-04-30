#include <stdio.h>
#include "priority_queue.h"

#ifndef HUFF_TREE_H
#define HUFF_TREE_H

  typedef struct node Node;
  struct node{
    char item;
    int frequency;
    Node *next;
    Node *left;
    Node *right;
  };

  /*
  Função que cria uma arvore de huffman(hufftree) a partir de uma fila de prioridades
  Recebe - PriorityQueue : ponteiro da fila de prioridades
  Retorna - Hufftree : nó(ponteiro) da arvore de huffman
  */
  Node* queue_to_tree(PriorityQueue* pq);

  /*
  Função que cria um nó da arvore
  Recebe 
    - char : item
    - Node* : nó esquerdo
    - Node* : nó direito
  Retorna - Node* : nó criado
  */
  Node* create_tree_node(char item, Node *left, Node *right);


  /*
  Função que cria uma arvore a partir de uma string de arvore impressa
  Recebe
    - string : arvore impressa em pré-ordem transversal
    - int : index(necessário ser 0 ao chamar a função)
  Retorna - Hufftree* : a arvore recriada a partir da string
  */ 
  Node* str_to_tree(char* str, int* i);

  /*
  Função que verifica se o nó é folha
  Recebe - Node* : o nó da arvore 
  Retorna - int : 1 ou 0
  */
  int is_leaf(Node* bt);

  //Retorna o nó esquerdo de um nó recebido
  Node* get_left_tree(Node* bt);

  //Retorna o nó direito de um nó recebido
  Node* get_right_tree(Node* bt);

  //Retorna o item de um nó recebido
  char get_tree_item(Node* bt);

  /*
  Função que calcula a quantidade de nós de uma arvore percorrendo ela de forma recursiva
  Recebe
    - Node* : arvore
    - int : contador(deve ser 0 quando a função for chamada)
  Retorna - int : tamanho(quantidade de nós) da arvore
  */
  int calculate_tree_size(Node* bt, int size);


  /*
  Função que escreve arvore em pré-ordem transversal no arquivo comprimido
  Recebe
    - Node* : Arvore
    - FILE* : Arquivo de destino
  */
  void print_tree_in_file(Node* bt, FILE *dest_file);

  //Dá free em todos os nós da arvore
  void free_tree(Node* bt);

#endif
