/* Charles Buyas, cjb8qf, 4-13-17, linkedlist.c */

#include <stdio.h>
#include <stdlib.h>

struct list_item {
  struct list_item *next;
  int value;
};

void insertItem(struct list_item **head, int value) {
  if (*head == NULL) {
    *head = (struct list_item *) malloc((sizeof(struct list_item*)));
    (*head)->value = value;
    (*head)->next = NULL;
  }
  else {
    struct list_item * tail = *head;
    while (tail->next != NULL) {
      tail = tail->next;
    }
    tail->next = (struct list_item *) malloc((sizeof(struct list_item*)));
    tail->next->value = value;
  }
}

int main() {
  struct list_item * head = NULL;
  int n;
  int element;
  printf("Enter number of values: ");
  scanf("%d", &n);
  for (int i = 0 ; i < n ; i++ ) {
    printf("Enter node value %d: ", i+1);
    scanf("%d", &element);
    insertItem(&head, element);
  }
  struct list_item * item = head;
  while (item != NULL) {
    printf("%d\n", item->value);
    item = item->next;
  }
  while (head != NULL) {
    item = head->next;
    free(head);
    head = item;
  }
  return 0;
}
