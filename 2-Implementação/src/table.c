#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/table.h"
#include "../inc/huff_tree.h"

struct bit_node{
  char bit;
  BitNode *next;
};

struct table{
  BitNode *first;
  BitNode *last;
};


Table *create_table(int size){
  int i;
  Table *table = (Table*)malloc(size*sizeof(Table));
  for(i = 0; i < size; i++){
    table[i].first = NULL;
    table[i].last = NULL;
  }
  return table;

}


BitNode *create_bit_node(char item){

  BitNode *newNode = (BitNode*)malloc(sizeof(BitNode));
  newNode->bit = item;
  newNode->next = NULL;
  return newNode;

}


void add_to_list(Table *list, unsigned char position, char bit){

  BitNode *newNode = create_bit_node(bit);
  if(list[position].first == NULL){
    list[position].first = newNode;
    list[position].last = newNode;
  }
  else{
    list[position].last->next = newNode;
    list[position].last = newNode;
  }

}


void fill_table(Node *bt, Table *table, char *next_binary, char *code){
  strcat(code, next_binary);
  if(is_leaf(bt)){
    int i;
    //take the char as the array index and code as the "binary" of said char
    for(i = 0; i < strlen(code); i++){
      add_to_list(table, get_tree_item(bt), code[i]);//sets the table char by char of the code with BitNodes
    }
    return;
  }
  fill_table(get_left_tree(bt), table, "0", code);
  code[strlen(code)-1] = '\0';
  fill_table(get_right_tree(bt), table, "1", code);
  code[strlen(code)-1] = '\0';
  return;
}


int write_in_file(unsigned char *file_content, size_t file_size, FILE *dest_file, Table *table){
  int i, j = 7;
  BitNode *current = NULL;
  unsigned char byte = 0;
  //percorre a tabela
  for(i = 0; i < file_size; i++){
    current = table[file_content[i]].first;
    
    for(; j >= 0; j--){
      if(current->bit == '1'){
        (byte |= 1<<j); //seta o byte percorrendo a lista de bits na tabela
      }
      if(current->next == NULL){ //se chegar no final da lista
        if(i == file_size-1){
          putc(byte, dest_file);  //caso seja o final do arquivo, escreve o byte e volta pro primeiro for
          break;
        }
        else if(j == 0){
          putc(byte, dest_file); //caso tenha acabado o byte, volta o contador para que um novo byte seja preenchido
          j = 8;
          byte = 0;
        }
        j--;  //vai decrescendo o contador do byte atual
        break;
      }
      current = current->next; //avança a posição da lista
      if(j == 0){ //caso tenha acabado o tamanho do byte atual, zera o contador e volta o contador do byte para um novo ser preenchido
        putc(byte, dest_file);
        j = 8;
        byte = 0;
      }
    }
  }
  return j; //o que fica no contador é o tamanho do lixo
}


void print_table(Table *table, int size){
  int i;
  BitNode *second;
  for(i = 0; i < size; i++){
    if(table[i].first != NULL){

      second = table[i].first;

      printf("%c = ", i);
      while(second != NULL){

        printf("%c", second->bit);
        second = second->next;

      }
      printf("\n");
    }

  }

  return;

}

void free_table(Table *table, int size){
  int i;
  for(i = 0; i < size; i++){

    if(table[i].first != NULL){

      BitNode *first = table[i].first;
      BitNode *second = first->next;
      table[i].first = NULL;

      while(second != NULL){
        free(first);
        first = second;
        second = first->next;
      }

    }

  }
  free(table);
  return;
}
