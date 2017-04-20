#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/huff_tree.h"
#include "../header/priority_queue.h"
#include "../header/compress.h"


#define ASCII_SIZE 256

void compress(unsigned char *file_content, long int file_size, char *dest_filename) {
  int i, frequency[ASCII_SIZE] = {0};
  Heap* heap = create_heap(ASCII_SIZE);
  PriorityQueue* pq = create_priority_queue();
  Node* bt = NULL;
  int tree_size, trash_size;
  unsigned char byte1;
  unsigned char byte2;
  
  for(i = 0; i < file_size; i++){
    ++frequency[file_content[i]];                                       /* Conta a frequencia de cada byte(caractere) */
  }

  for(i = 0; i < ASCII_SIZE; i++){
    if(frequency[i] > 0){
      enqueue(pq, i, frequency[i]);                        /* Uses the index of the array as the char and the value of each index as the frequency when creating nodes */
    }
  }
//fiz até aqui
  bt = heap_to_tree(heap);                                                /* Makes the huff tree out of a heap */
  tree_size = calculate_tree_size(bt, 0);                                 /* Calculates the number of nodes in the huff tree */
  free(heap);

  Table* table = create_table(ASCII_SIZE);                                       /* Creates the table that will contain the value of each bit of the characters present in the text, according to the huff tree */

  char* empty_string = (char*)calloc(17, sizeof(char));                   /* Empty string used to allocate the memory space needed for the average huff binary code of a letter */

  fill_table(bt, table, "", empty_string);                                /* Transforms binary tree "bt" into the coding for each character */

  free(empty_string);

  byte1 = (tree_size>>8);                                                 /* Sets first three bits of the tree size in the first byte */
  byte2 = tree_size;                                                      /* Sets the remainder of the tree size in the second byte */

  FILE *dest_file = fopen(dest_filename, "w");                            /* Creates the destination file */

  putc(0, dest_file);                                                     /* Prints first byte in the destination file as 0, since we don't have the trash size yet */
  putc(byte2, dest_file);                                                 /* Prints second byte in the destination file */

  print_tree_in_file(bt, dest_file);                                      /* Prints the tree in the destination file */

  free_tree(bt);

  trash_size = write_in_file(file_content, file_size, dest_file, table);  /* Prints the compressed content and returns the trash size */
  free_table(table, ASCII_SIZE);

  rewind(dest_file);                                                      /* Rewinds the dest_file pointer to the beginning of the destination file */

  trash_size = trash_size<<5;                                             /* Sets trash size to the first three bits */
  byte1 |= trash_size;                                                    /* Adds trash size to the start of the first byte */
  putc(byte1, dest_file);                                                 /* Prints first byte in the destination file */
  fclose(dest_file);

}
