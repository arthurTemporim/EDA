#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_VALUES 30

typedef struct _list _list, List;
typedef struct _node _node, Node;

struct _node {
  int value;
  Node *previous;
  Node *next;
};

struct _list {
  int count;
  Node *head;
  Node *tail;
};

int add_value(List**, int);
Node *add_node(int);
int swap_node(List *, Node*, Node*);
int quicksort(List *, int, int);
void print(Node*);
void print_end(Node*);

int main (int argc, char *argv[]) {
  List *list;
  list = NULL;
  int iterator;

  srand(time(NULL));

  for (iterator = 0; iterator < NUMBER_VALUES; iterator++) {
    add_value(&list,  rand()%100 + 1);
  }
  print(list->head);
  quicksort(list, 0, list->count - 1);
  print(list->head);
  return 1;
}

Node *add_node(int value) {
  Node *tmp = (Node*)malloc(sizeof(Node));
  tmp->value = value;
  tmp->next = NULL;
  tmp->previous = NULL;

  return tmp;
}

int add_value(List **list, int value) {
  Node * node = add_node(value);

  if (*list == NULL) {
    *list = (List*)malloc(sizeof(List));
    (*list)->head = node;
    (*list)->tail = node;
    (*list)->count = 1;
  } else {
    (*list)->tail->next = node;
    (*list)->tail->next->previous = (*list)->tail;
    (*list)->tail = (*list)->tail->next;
    (*list)->count += 1;
  }
}

int swap_node(List *list, Node *first_node, Node *second_node) {
  Node *first_previous = first_node->previous;
  Node *first_next = first_node->next;

  first_node->previous = second_node->previous;
  first_node->next = second_node->next;

  second_node->previous = first_previous;
  second_node->next = first_next;

  if (first_node->previous == first_node) {
    first_node->previous = second_node;
  } else {
    // do nothing
  }
  if (second_node->next == second_node) {
    second_node->next = first_node;
  } else {
    // do nothing
  }

  if (first_node->next != NULL) {
    first_node->next->previous = first_node;
  } else {
    list->tail = first_node;
  }
  first_node->previous->next = first_node;

  if (second_node->previous != NULL) {
    second_node->previous->next = second_node;
  } else {
    list->head = second_node;
  }
  second_node->next->previous = second_node;

  return 1;
}

int quicksort(List *list, int pivot, int last) {
  int aux_first, aux_last;
  Node *node_pivot, *node_first, *node_last;
  while (pivot < last) {
    node_pivot = list->head;
    node_last = list->tail;
    for (aux_first = 0; aux_first < pivot; aux_first++) {
      node_pivot = node_pivot->next;
    }
    for (aux_last = list->count - 1; aux_last > last; aux_last--) {
      node_last = node_last->previous;
    }
    node_first = node_pivot->next;
    aux_first++;

    while(aux_first <= aux_last) {
      while (node_first->value < node_pivot->value) {
        aux_first++;
        node_first = node_first->next;
      }
      while (node_last->value > node_pivot->value) {
        aux_last--;
        node_last = node_last->previous;
      }
      if(aux_first <= aux_last) {
        swap_node(list, node_first, node_last);
        Node *aux = node_first;
        node_first = node_last;
        node_last = aux;
        aux_first++;
        aux_last--;
      }
    }
    quicksort(list, pivot, aux_last);
    quicksort(list, aux_first, last);
  }
  return 1;
}

void print(Node *tmp) {
  if (tmp != NULL) {
    printf("%d ", tmp->value);
    print(tmp->next);
  } else {
    printf("\n");
  }

  // exiting print
}

void print_end(Node *tmp) {
  if (tmp != NULL) {
    printf("%d ", tmp->value);
    print_end(tmp->previous);
  } else {
    printf("\n");
  }

  // exiting print
}
