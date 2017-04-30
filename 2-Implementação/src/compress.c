#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/compress.h"
#include "../inc/priority_queue.h"
#include "../inc/huff_tree.h"
#include "../inc/table.h"

#define ASCII_SIZE 256

void compress(unsigned char *file_content, long int file_size, char *dest_filename) {
  int i, frequency[ASCII_SIZE] = {0};
  PriorityQueue* pq = create_priority_queue();
  Node* bt = NULL;
  int tree_size, trash_size;
  unsigned char byte1;
  unsigned char byte2;

  for(i = 0; i < file_size; i++){

    ++frequency[file_content[i]];                                         //Conta a frequencia que cada byte(caractere) aparece no arquivo e salva no array frequency

  }

  for(i = 0; i < ASCII_SIZE; i++){
    if(frequency[i] > 0){
      pq = enqueue(pq, create_node(i, frequency[i]));                     //Adiciona cada byte(caractere) existente no arquivo a uma fila de prioridades utilizando a  frequencia de cada um
    }
  }

  bt = queue_to_tree(pq);                                                 //Usa a fila para gerar a arvore de huffman
  tree_size = calculate_tree_size(bt, 0);                                 //Calcula o numero de nós da arvore(seu tamanho)
  free(pq);

  Table* table = create_table(ASCII_SIZE);                                //Cria a tabela que vai armazenar o novo binário de cada byte(caractere) seguindo o padrão da arvore de huffman       

  char* empty_string = (char*)calloc(17, sizeof(char));                   //String vazia com o tamanho máximo de bits que um binário de huffman teria.

  fill_table(bt, table, "", empty_string);                                //Preenche a tabela com o novo binário de cada caractere através da arvore de huffman

  free(empty_string);

  byte1 = (tree_size>>8);                                                 //Seta o resto de byte 1 com o que passa do tamanho da arvore caso passe de 11111111
  byte2 = tree_size;                                                      //Seta o byte 2 com o resto do tamanho da arvore
  //Ex. Se a arvore tiver tamanho 8191(max) o byte 1 vai ser 00011111 e o 2 11111111

  FILE *dest_file = fopen(dest_filename, "w");                            //Cria o arquivo de destino

  putc(0, dest_file);                                                     //Escreve o primeiro byte no arquivo como 0 pois ainda não há o tamanho do lixo
  putc(byte2, dest_file);                                                 //Escreve o segundo byte no arquivo

  print_tree_in_file(bt, dest_file);                                      //Escreve a arvore no arquivo

  free_tree(bt);

  trash_size = write_in_file(file_content, file_size, dest_file, table);  //Escreve o conteúdo comprimido no arquivo e retorna o tamanho do lixo
  free_table(table, ASCII_SIZE);

  rewind(dest_file);                                                      //Função que retorna o ponteiro para o começo do arquivo

  trash_size = trash_size<<5;                                             //Seta o tamanho do lixo para seus 3 primeiros bits
  byte1 |= trash_size;                                                    //Seta o tamanho do lixo no primeiro byte
  putc(byte1, dest_file);                                                 //Escreve o primeiro byte no arquivo
  fclose(dest_file);

}
