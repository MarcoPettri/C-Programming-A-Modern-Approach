// Exercise 17.11

/*
Write the following function:

    int count_occurrences(struct node *list, int n);

The list parameter points to a linked list; the function should return the
number of times that n appears in this list. Assume that the node structure is
the one defined in Section 17.5


*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node *Node;
struct node {
  int data;
  Node next;
};

int count_occurrences(Node list, int n);
Node insert(Node list, int n);
void free_list(Node list);

int main(void) {
  Node list = NULL;
  list = insert(list, 1);
  list = insert(list, 2);
  list = insert(list, 3);
  list = insert(list, 4);
  list = insert(list, 5);

  printf("%d\n", count_occurrences(list, 3));
  printf("%d\n", count_occurrences(list, 6));

  free_list(list);
  return 0;
}

void free_list(Node list) {
  Node temp;
  while (list != NULL) {
    temp = list;
    list = list->next;
    free(temp);
  }
}

int count_occurrences(Node list, int n) {
  int count = 0;
  for (; list != NULL; list = list->next) {
    if (list->data == n) {
      count++;
    }
  }
  return count;
}

Node insert(Node list, int n) {
  Node new_node = (Node)malloc(sizeof(struct node));
  if (!new_node) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  new_node->data = n;
  new_node->next = list;
  return new_node;
}
