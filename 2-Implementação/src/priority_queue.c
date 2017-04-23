#include <stdio.h>
#include <stdlib.h>
#include "../inc/huff_tree.h"
#include "../inc/priority_queue.h"


PriorityQueue* create_priority_queue() {
  PriorityQueue *pqueue = (PriorityQueue*) malloc(sizeof(PriorityQueue));
  pqueue->first = NULL;
  return pqueue;
}

int is_empty(PriorityQueue *pq) {
  return (pq->first == NULL);
}

PriorityQueue* enqueue(PriorityQueue *pq, Node *n) {
  if (is_empty(pq) || (n->frequency <= pq->first->frequency)) {
    n->next = pq->first;
    pq->first = n;
  } else {
    Node *current = pq->first;
    while ((current->next != NULL) && (current->next->frequency < n->frequency)) {
      current = current->next;
    }
    n->next = current->next;
    current->next = n;
  }
  return pq;
}

Node* dequeue(PriorityQueue *pq) {
  if (!is_empty(pq)) {
    Node *dequeued = pq->first;
    pq->first = pq->first->next;
    return dequeued;
  } else {
    return NULL;
  }
}

Node *maximum(PriorityQueue *pq) {
  if(!is_empty(pq)) {
    return pq->first;
  } else {
    return NULL;
  }
}

void print_priority_queue(PriorityQueue *pq){
  Node *n = pq->first;
  while(n != NULL){
    printf("%c %d\n", n->item, n->frequency);
    n = n->next;
  }
}

int get_size(PriorityQueue *pq){
  int size = 0;
  Node *n = pq->first;
  while(n != NULL){
    n = n->next;
    size++;
  }
  return size;
}

void free_list(Node *node) {
  if(node == NULL) return;
  free_list(node->next);
  free(node);
}

void free_queue(PriorityQueue *pq) {
  free_list(pq->first);
  free(pq);
}

Node* create_node(unsigned char item, int frequency){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->item = item;
  newNode->frequency = frequency;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->next = NULL;
  return newNode;
}
