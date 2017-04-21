#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

  typedef struct priority_queue PriorityQueue;
  typedef struct node Node;
  typedef struct qnode Qnode;

  struct qnode{
    Node *data;
    Qnode *next_node;
  };

  struct priority_queue {
    Qnode *first;
  };

PriorityQueue* create_priority_queue();
int is_empty(PriorityQueue *pq);
void enqueue(PriorityQueue *pq, Node *n);
Node* dequeue(PriorityQueue *pq);
Node* maximum(PriorityQueue *pq);
void print_priority_queue(PriorityQueue *pq);
int get_size(PriorityQueue *pq);

#endif /* PRIORITY_QUEUE_H */