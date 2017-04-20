#include <stdio.h>
#include <stdlib.h>
#include "../header/priority_queue.h"

void main(){
  PriorityQueue *pq = create_priority_queue();
  int c = 2;

  enqueue(pq, &c, 1);
  //print_priority_queue(pq);
}