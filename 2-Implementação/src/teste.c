#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/huff_tree.h"
#include "../inc/priority_queue.h"

void main(){
  PriorityQueue *pq = create_priority_queue();
  PriorityQueue *dq = create_priority_queue();


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

  dq->first = dequeue(pq);

  

  print_priority_queue(pq);
  printf("Size = %d\n", get_size(pq));
  printf("Is empty? %d\n", is_empty(pq));
  printf("\n");

  print_priority_queue(dq);
  printf("Size = %d\n", get_size(dq));
  printf("Is empty? %d\n", is_empty(dq));

  Node *tree = queue_to_tree(pq);
  printf("Tree Size = %d\n", calculate_tree_size(tree, 0));
  print_tree(tree);
  printf("\n");
}