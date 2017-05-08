#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../inc/decompress.h"
#include "../inc/huff_tree.h"

int is_bit_i_set(unsigned char c, int i) {
	unsigned char mask = 1 << i;
	return mask & c;
}

void decompress(unsigned char *file_content, long int file_size, char *dest_filename) {
  int trash_size = 0, tree_size = file_content[1]; // tree_size está incompleto aqui, será preciso calcular os bits restantes do primeiro byte 
  unsigned char byte1 = file_content[0];
  unsigned char byte2 = file_content[1];

  //Calcula o tamanho da arvore pelo cabeçalho
  int i, j;
  for(i = 0, j = 8; i < 5; ++i, ++j) { 
    if(is_bit_i_set(byte1, i))
      tree_size += pow(2, j);
  }

  //Pega o tamanho do lixo pelo cabeçalho
  trash_size = byte1 >> 5;

  //Passa a arvore para um string
  char tree_str[tree_size+1];
  for(i = 2; i < tree_size+2; ++i) {
    tree_str[i-2] = file_content[i];
  }
  tree_str[tree_size] = '\0';

  //Transforma a arvore da string em um arvore de verdade
  i = 0;
  Node *tree = str_to_tree(tree_str, &i);
  Node *aux_tree = tree;

  //cria o arquivo de destino
  FILE *dest_file = fopen(dest_filename, "w");

  //Pecorre o arquivo  e a arvore escrevendo os bytes no arquivo descompactado
  for(i = tree_size + 2; i < file_size - 1; ++i) {
    for(j = 7; j >= 0; --j) {
      if(is_bit_i_set(file_content[i], j)) {
        aux_tree = get_right_tree(aux_tree);
      } else {
        aux_tree = get_left_tree(aux_tree);
      }

      if(is_leaf(aux_tree)) {
        putc(get_tree_item(aux_tree), dest_file);
        aux_tree = tree;
      }
    }
  }

  //analiza o utimo byte caso tenha lixo ou não
  for(i = 7; i >= trash_size; --i) {
    if(is_bit_i_set(file_content[file_size - 1], i)) {
      aux_tree = get_right_tree(aux_tree);
    } else {
      aux_tree = get_left_tree(aux_tree);
    }

    if(is_leaf(aux_tree)) {
      putc(get_tree_item(aux_tree), dest_file);
      aux_tree = tree;
    }
  }

  free_tree(tree);
  fclose(dest_file);
}
