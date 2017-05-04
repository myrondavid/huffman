#include "CUnit/Basic.h"
#include "../priority_queue/priority_queue.h"

PriorityQueue* setup_test() {
  PriorityQueue *pq = create_priority_queue();

  enqueue(pq, 1, 12);
  enqueue(pq, 2, 100);  
  enqueue(pq, 3, 2);

  return pq;
}

void create_priority_queue_test() {
  PriorityQueue *pq = create_priority_queue();

  CU_ASSERT_NOT_EQUAL(pq, NULL);

  free_queue(pq);
}

void is_empty_test() {
  PriorityQueue *pq = create_priority_queue();

  /* Empty Queue */
  CU_ASSERT_EQUAL(is_empty(pq), 1);


  /* Not Empty */
  enqueue(pq, 12, 3);
  CU_ASSERT_EQUAL(is_empty(pq), 0);

  free_queue(pq);
}

void maximum_test() {
  PriorityQueue *pq = create_priority_queue();

  /* Empty Queue */
  CU_ASSERT_EQUAL(maximum(pq), -1);


  /* Not Empty */
  enqueue(pq, 1, 3);
  enqueue(pq, 2, 10);
  CU_ASSERT_EQUAL(maximum(pq), 2);

  free_queue(pq);
}

void enqueue_test() {
  PriorityQueue *pq = setup_test();  

  CU_ASSERT_NOT_EQUAL(enqueue(pq, 1, 12), NULL);

  free_queue(pq);
}

void dequeue_test() {
  PriorityQueue *pq = setup_test();  

  /* The dequeued items should be based on the frequency order */
  CU_ASSERT_EQUAL(dequeue(pq), 2);
  CU_ASSERT_EQUAL(dequeue(pq), 1);
  CU_ASSERT_EQUAL(dequeue(pq), 3);

  free_queue(pq);
}

int main() {
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  CU_pSuite p_suite = NULL;

  p_suite = CU_add_suite("Priority Queue test suite", 0, 0);

  if (p_suite == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (CU_add_test(p_suite, "create_priority_queue_test", create_priority_queue_test) == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (CU_add_test(p_suite, "is_empty_test", is_empty_test) == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (CU_add_test(p_suite, "enqueue_test", enqueue_test) == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  } 

  if (CU_add_test(p_suite, "dequeue_test", dequeue_test) == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  } 

  if (CU_add_test(p_suite, "maximum_test", maximum_test) == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  } 

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
