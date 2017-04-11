#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

PriorityQueue* create_priority_queue(){

}

int is_empty(PriorityQueue *pq){
    return(pq->first == NULL);
}

void enqueue(PriorityQueue *pq, void *item, int priority);{
    Node *new = (Node*) malloc(sizeof(Node));
    new->item = item;
    new->priority = priority;
    if(is_empty(pq) || (priority > pq->first->priority)){
        new->next_node = pq->first;
        pq->first = new;
    }
    else{
        Node *current = pq->first;
        while((current->next_node != NULL) && (current->next_node->priority > priority)){
            current = current->next_node;
        }
        new->next_node = current->next_node;
        current->next_node = new;
    }
}

Node dequeue(PriorityQueue *pq){
    if(!is_empty(pq)){
        Node *current = pq->first;
        pq->first = pq->first->next_node;
        current->next_node = NULL;
        return current;
    }
    else{
        return NULL;
    }
}


int maximum(PriorityQueue *pq){
    if(!is_empty(pq))
        return pq->first->item;
    else
        return -1;
}

void print_priority_queue(PriorityQueue *pq){

}