#include <stdio.h>
#include <stdlib.h>
#include "../header/priority_queue.h"
#include "../header/huff_tree.h"

void main(){
  PriorityQueue *pq = create_priority_queue();
  Node *new = (Node*) malloc(sizeof(Node));
  new->frequency = 1;
  new->item = 'a';
  new->left = NULL;
  new->right = NULL;

  enqueue(pq, new);
  enqueue(pq, new);
  enqueue(pq, new);
  enqueue(pq, new);
  enqueue(pq, new);
  dequeue(pq);
  print_priority_queue(pq);
  printf("Size = %d\n", get_size(pq));
  printf("Is empty? %d/n", is_empty(pq));
}