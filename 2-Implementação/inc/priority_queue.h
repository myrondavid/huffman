#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

typedef struct node Node;
typedef struct priority_queue PriorityQueue;

struct priority_queue {
  Node *first;
};

//Cria um fila de prioridades vazia
PriorityQueue* create_priority_queue();

/*
Verifica se a fila está vazia
Recebe - PriorityQueue* : fila de prioridade
Retorna - int : 1(true) ou 0(false)
*/
int is_empty(PriorityQueue *pq);

/*
Função que adiciona um nó na fila de prioridades
Recebe
  - PriorityQueue* : a fila onde o nó será adicionado
  - Node* : o nó que será adicionado a fila
Retorna - PriorityQueue* : A fila com o nó adicionado
*/
PriorityQueue* enqueue(PriorityQueue *pq, Node *n);

/*
Função que remove um nó da fila e o retorna
Recebe - PriorityQueue* : fila que o nó será retirado
Retorna - Node* : nó removido
*/
Node* dequeue(PriorityQueue *pq);

/*
Função que retorna o nó com menor frequência
Recebe - PriorityQueue* : fila de prioridade
Retorna - Node* : nó com menor frequência
*/
Node* maximum(PriorityQueue *pq);

/*
Função que imprime a fila de prioridades como saida na tela
Recebe - PriorityQueue* : fila que a ser impressa
Retorna - void
*/
void print_priority_queue(PriorityQueue *pq);

/*
Função que retorna o tamanho da fila de prioridades
Recebe - PriorityQueue* : a fila
Retorna - int : o tamanho da fila
*/
int get_size(PriorityQueue *pq);

/*
Função que cria um nó do tipo Node
Recebe
  -unsigned char : o byte(caractere)
  -int : a frequencia do byte
Retorna - Node* : nó criado
*/
Node* create_node(unsigned char item, int frequency);

//Dá free em todos os nós da fila
void free_queue(PriorityQueue *pq);

#endif /* PRIORITY_QUEUE_H */