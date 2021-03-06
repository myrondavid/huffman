#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <time.h>

#include "list/inc/list.h"
#include "bst/inc/bst.h"

#define CSV_HEADER "SEARCHES,LIST,BST\n"
#define CSV_FILENAME "list_vs_bst.csv"

/* If change this value here, change in the .R too */
#define SIZE 100

void generate_csv_file(int *searches, int *comp_list, int *comp_bst) {
  FILE *file;
  char line[30];
  int i;

  file = fopen(CSV_FILENAME, "w");
  fputs(CSV_HEADER, file);

  for(i = 0; i < SIZE; ++i) {
    sprintf(line, "%d,%d,%d\n", searches[i], comp_list[i], comp_bst[i]);

    fputs(line, file);
  }

  fclose(file);
}

int main() {
  int i, g;
  int searches[20000], comp_list[20000], comp_bst[20000];

  BinaryTree *bst = create_empty_bst();
  Node *list = create_list();

  srand ( time(NULL) );
  for(i = 0; i < 10000; ++i) {
    g = rand()%10000-1;

    list = insert_node(list, g);
    bst = add_branch(bst, g);
  }

  for(i = 0; i < SIZE; ++i) {
    g = rand()%10000-1;

    searches[i] = g;
    comp_list[i] = compare_search(list, i);
    comp_bst[i] = compare_search_bst(bst, i);
  }

  generate_csv_file(searches, comp_list, comp_bst);



  return 0;
}
