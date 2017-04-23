#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

typedef struct node Node;
typedef struct priority_queue PriorityQueue;

struct priority_queue {
  Node *first;
};


PriorityQueue* create_priority_queue();
int is_empty(PriorityQueue *pq);
PriorityQueue* enqueue(PriorityQueue *pq, Node *n);
Node* dequeue(PriorityQueue *pq);
Node* maximum(PriorityQueue *pq);
void print_priority_queue(PriorityQueue *pq);
int get_size(PriorityQueue *pq);
Node* create_node(unsigned char item, int frequency);
void free_queue(PriorityQueue *pq);

#endif /* PRIORITY_QUEUE_H */