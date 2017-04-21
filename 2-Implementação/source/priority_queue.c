#include <stdio.h>
#include <stdlib.h>
#include "../header/huff_tree.h"
#include "../header/priority_queue.h"

PriorityQueue* create_priority_queue(){
  PriorityQueue *pq = (PriorityQueue*) malloc(sizeof(PriorityQueue));
  pq->first = NULL; 
  return pq;
}

int is_empty(PriorityQueue *pq){
    return(pq->first == NULL);
}

void enqueue(PriorityQueue *pq, Node *n){
    Qnode *new = (Qnode*) malloc(sizeof(Qnode));
    new->data = n;
    new->next_node = NULL;
    if(is_empty(pq) || (n->frequency > pq->first->data->frequency)){
        new->next_node = pq->first;
        pq->first = new;
    }
    else{
        Qnode *current = pq->first;
        while((current->next_node != NULL) && (current->data->frequency > n->frequency)){
            current = current->next_node;
        }
        new->next_node = current->next_node;
        current->next_node = new;
    }
}

Node* dequeue(PriorityQueue *pq){
    if(!is_empty(pq)){
        Qnode *current = pq->first;
        pq->first = pq->first->next_node;
        current->next_node = NULL;
        return current->data;
    }
    else{
        return NULL;
    }
}


Node* maximum(PriorityQueue *pq){
    if(!is_empty(pq))
        return pq->first->data;
    else
        return NULL;
}

void print_priority_queue(PriorityQueue *pq){
  Qnode *new = (Qnode*) malloc(sizeof(Qnode));
  new = pq->first;
  while(new != NULL){
    printf("%c\n", new->data->item);
    new = new->next_node;
  }
}

int get_size(PriorityQueue *pq){
  int size = 0;
  Qnode *new = (Qnode*) malloc(sizeof(Qnode));
  new = pq->first;
  while(new != NULL){
    size++;
    new = new->next_node;
  }
  return size;
}