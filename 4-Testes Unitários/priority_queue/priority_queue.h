#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

  typedef struct node Node;
  typedef struct pq PriorityQueue;

  struct node {
    int item;
    int priority;
    Node *next;
  };

  struct pq {
    Node *first;
  };

  PriorityQueue* create_priority_queue();

  PriorityQueue* enqueue(PriorityQueue *pq, int item, int priority);

  int dequeue(PriorityQueue *pq);

  int maximum(PriorityQueue *pq);

  int is_empty(PriorityQueue *pq);

  void free_queue(PriorityQueue *pq);

#endif /* PRIORITY_QUEUE_H */
