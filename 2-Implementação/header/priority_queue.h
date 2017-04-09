#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

  typedef struct priority_queue PriorityQueue;
  typedef struct node Node;

  struct node {
    int priority;
    int item;
    Node *next_node;
  };

  struct priority_queue {
    Node *first;
  };

PriorityQueue* create_priority_queue();
void enqueue(PriorityQueue *pq, int item, int priority);
Node dequeue(PriorityQueue *pq);
int is_empty(PriorityQueue *pq);
int maximum(PriorityQueue *pq);
void print_priority_queue(PriorityQueue *pq);

#endif /* PRIORITY_QUEUE_H */