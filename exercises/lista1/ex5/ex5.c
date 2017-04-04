#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define LIST_SIZE 20

typedef struct _list _list, List;
struct _list {
	int value;
	List *next;
};

int list_push(List**, List*, int);
int list_get(List*, int);
int binary_search(List*, int, int, int);

int main (int argc, char *argv[]) {
  List* list;
	int iterator, entry_value;
	list = NULL;

	for (iterator = 0; iterator < LIST_SIZE; iterator++) {
		list_push(&list, list, iterator);
	}
	scanf("%d", &entry_value);
	printf("%d\n", binary_search(list, 0, LIST_SIZE, entry_value));

  return 0;
}

int list_push(List** list, List* head, int value) {
	if (*list == NULL) {
		*list = (List*) malloc(sizeof(List));
		(*list)->value = value;
		(*list)->next = *list;
		return 1;
	} else {
		if (head == (*list)->next) {
			List *aux = (List*) malloc(sizeof(List));
			(aux)->value = value;
			(aux)->next = head;
			(*list)->next = aux;
			return 1;
		} else {
			list_push(&((*list)->next), head, value);
		}
	}
}

int binary_search(List *list, int min, int max, int value) {
	List *aux = list;
	int mid_value = (max-min)/2;
	while(mid_value) {
		aux = aux->next;
		mid_value--;
	}

  if (value == aux->value) {
    return (max+min)/2;
  }

	if (min >= max) {
		return -1;
	} else {
		if (aux->value > value) {
			return binary_search(list, min, ((max+min)/2) - 1, value);
		} else {
			return (max+min)/2 + binary_search(aux, min, max - ((max+min)/2) + 1, value);
		}
	}
}
