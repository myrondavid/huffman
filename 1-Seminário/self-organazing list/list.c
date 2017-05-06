#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node* create_list() {
  return NULL;
}

Node* insert_node(Node *first, int item) {
  Node *new_node = (Node*) malloc(sizeof(Node));
  new_node->item = item;
  new_node->next_node = first;
  new_node->prev_node = NULL;

  if(first != NULL)
    first->prev_node = new_node;
  return new_node;
}

Node* search(Node *first, int item) {
  Node *node;
  for(node = first; node->next_node != NULL; node = node->next_node) {
    if(node->item == item) return node;
  }
  return NULL;
}

Node* search_movetofront(Node *first, int item) {
  Node *node;
  Node *prev;
  for(node = first; node->next_node != NULL; node = node->next_node) {
    if(node->item == item){
      node->next_node->prev_node = node->prev_node;
      node->prev_node = node->next_node;
      node->next_node = first;
      node->prev_node = NULL;
      return node;
    } 
  }
  return NULL;
}

Node* remove_node(Node *first, int item) {
  Node *node = search(first, item);
  if(node == NULL) return first;

  if(node == first)
    first = node->next_node;
  else
    node->prev_node->next_node = node->next_node;

  if(node->next_node != NULL)
    node->next_node->prev_node = node->prev_node;

  free(node);
  return first;
}

int is_empty(Node *first) {
  return (first == NULL);
}

void print_doubly_linked_list_forward(Node *first) {
  if(!is_empty(first)) {
    print_doubly_linked_list_forward(first->next_node);

    printf("%d ", first->item);
  }
}

void print_doubly_linked_list_backward(Node *last) {
  if(!is_empty(last)) {
    print_doubly_linked_list_backward(last->prev_node);

    printf("%d ", last->item);
  }
}
