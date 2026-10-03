// Exercise 17.12

/*

Write the following function:

    struct node *find_last(struct node *list, int n);

The list parameter points to a linked list. The function should return a pointer
to the last node that contains n; it should return NULL if n doesn’t appear in
the list. Assume that the node structure is the one defined in Section 17.5

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node *Node;
struct node {
  int data;
  Node next;
};

Node insert(Node list, int n);
void free_list(Node list);
Node find_last(Node list, int n);

int main(void) {
  Node list = NULL;
  list = insert(list, 3);
  list = insert(list, 2);
  list = insert(list, 3);
  list = insert(list, 4);
  list = insert(list, 3);

  printf("%d\n", find_last(list, 3)->data);

  Node result = find_last(list, 6);
  if (!result) {
    printf("NULL\n");
  } else {
    printf("%d\n", result->data);
  }

  free_list(list);
  return 0;
}

Node find_last(Node list, int n) {

  if (!list)
    return NULL;

  Node last = NULL;
  do {
    if (list->data == n) {
      last = list;
    }
  } while ((list = list->next));

  return last;
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

void free_list(Node list) {
  Node temp;
  while (list != NULL) {
    temp = list;
    list = list->next;
    free(temp);
  }
}
