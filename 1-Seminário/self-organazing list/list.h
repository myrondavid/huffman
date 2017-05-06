#ifndef LIST_H
#define LIST_H

  typedef struct node Node;
  
  struct node {
    int item;
    Node *next_node;
    Node *prev_node;
  };

  Node* create_list();

  Node* insert_node(Node *first, int item);

  Node* search(Node *first, int item);

  Node* search_movetofront(Node *first, int item);

  Node* remove_node(Node *first, int item);

  int is_empty(Node *first);

  void print_list_forward(Node *first);

  void print_list_backward(Node *last);

#endif /* LIST_H */
