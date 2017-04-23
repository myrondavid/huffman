#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/huff_tree.h"
#include "../inc/priority_queue.h"

void main(){
  PriorityQueue *pq = create_priority_queue();

  Node *bt = create_node('a', 10);
  Node *bt2 = create_node('b', 5);
  Node *bt3 = create_node('c', 9);
  Node *bt4 = create_node('d', 7);
  Node *bt5 = create_node('e', 2);
  
  pq = enqueue(pq, bt);
  pq = enqueue(pq, bt2);
  pq = enqueue(pq, bt3);
  pq = enqueue(pq, bt4);
  pq = enqueue(pq, bt5);

  dequeue(pq);
  print_priority_queue(pq);
  printf("Size = %d\n", get_size(pq));
  printf("Is empty? %d\n", is_empty(pq));
  printf("\n");
}