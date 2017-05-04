#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"



PriorityQueue* create_priority_queue() {
  PriorityQueue *pq = (PriorityQueue*) malloc(sizeof(PriorityQueue));
  pq->first = NULL;

  return pq;
}

int is_empty(PriorityQueue *pq) {
  return (pq->first == NULL);
}

PriorityQueue* enqueue(PriorityQueue *pq, int item, int priority) {
  Node *new_node = (Node*) malloc(sizeof(Node));
  new_node->item = item;
  new_node->priority = priority;

  if (is_empty(pq) || (priority > pq->first->priority)) {
    new_node->next = pq->first;
    pq->first = new_node;
  } else {
    Node *current = pq->first;

    while ((current->next != NULL) && (current->next->priority > priority)) {
      current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
  }

  return pq;
}

int dequeue(PriorityQueue *pq) {
  if (!is_empty(pq)) {
    Node *dequeued = pq->first;
    int dequeued_item = dequeued->item;

    pq->first = dequeued->next;
    free(dequeued);

    return dequeued_item;
    //return 0;
  } else {
    return -1;
  }
}

int maximum(PriorityQueue *pq) {
  if(!is_empty(pq)) {
    return pq->first->item;
  } else {
    return -1;
  }
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
