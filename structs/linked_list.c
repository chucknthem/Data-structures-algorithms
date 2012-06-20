#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>

#define INVALID_VALUE -1

typedef struct NodeT {
  struct NodeT* next;
  int value;
} Node;

typedef struct ListT {
  Node* head;
  int length;
} List;

List* createList() {
  List* newList = (List*) malloc(sizeof(List));
  newList->head = NULL;
  newList->length = 0;
  return newList;
}

Node* createNode(int value) {
  Node* newNode = (Node*) malloc(sizeof(Node));
  newNode->next = NULL;
  newNode->value = value;
  return newNode;
}

void destroyNode(Node* node) {
  free(node);
}

void destroyList(List* list) {
  if (!list) return;
  while (list->head) {
    Node* next = list->head->next;
    free(list->head);
    list->head = next;
  }

  free(list);
}

/**
 * Insert value at position. The list is zero indexed.
 */
void insertNode(List* ls, int value, int position) {
  Node* newNode = createNode(value);
  if (position == 0 || ls->head == NULL) {
    newNode->next = ls->head;
    ls->head = newNode;
  }
  Node* cur = ls->head;
  Node* prev = NULL;
  while(position-- && cur) 
    prev = cur;
    cur = cur->next;

  newNode->next = cur;
  prev->next = newNode;
  ls->length++;
}

/**
 * Delete the node at position where position starts at 0.
 */
void removeNode(List* ls, int position) {
  if (position >= ls->length) return;

  Node* cur = ls->head;
  Node* prev = NULL;

  if (position == 0) {
    ls->head = ls->head->next;
  } else {
    // Find the node to delete.
    for(; cur && position; position--, cur = cur->next)
      prev = cur;
    prev->next = cur->next;
  }

  free(cur);
  ls->length--;
}

void push(List* ls, int value) {
  Node* newNode = createNode(value);
  newNode->next = ls->head;
  ls->head = newNode;
  ls->length++;
}

void pushNode(List* ls, Node* node) {
  node->next = ls->head;
  ls->head = node;
  ls->length++;
}

int pop(List* ls) {
  Node* node = ls->head; 
  int value = INVALID_VALUE;
  if (node) {
    ls->head = node->next;
    ls->length--;
    value = node->value;
    destroyNode(node);
  }

  return value;
}

Node* popNode(List* ls) {
  Node* node = ls->head;
  if (node) {
    ls->head = node->next;
    ls->length--;
  }

  return node;
}

/* 
 * What is the reverse of null (the empty list)? null.
 * What is the reverse of a one element list? the element.
 * What is the reverse of an n element list? the reverse of the second element on followed by the first element.
 */
Node* reverseRecursiveNodeList(Node* node) {
  if (!(node && node->next)) return node;
  Node* next = node->next;
  node->next = NULL;
  Node* rest = reverseRecursiveNodeList(next);
  next->next = node;
  return rest;
}

Node* reverseNodeList(Node* node) {
  if (!(node && node->next)) 
    return node;
  Node* cur = node;
  Node* next = node->next;
  node->next = NULL;
  Node* tmp;
  while (next) {
    tmp = next->next;
    next->next = cur;
    cur = next;
    next = tmp;
  }

  return cur;
}

void reverseRecursive(List* ls) {
  ls->head = reverseRecursiveNodeList(ls->head);
}

void reverse(List* ls) {
  ls->head = reverseNodeList(ls->head);
}

void printList(List* list) {
  Node* current;
  for (current = list->head; current != NULL; current = current->next) {
    printf("%d ", current->value);
  }
  putchar('\n');
}

int main(void) {
  List* list = createList();
  push(list, 4);
  push(list, 8);
  push(list, 1);
  push(list, 9);
  push(list, 3);
  push(list, 5);
  push(list, 8);
  push(list, 7);

  printf("starting list\n");
  printList(list);

  int top = pop(list);
  printf("popped %d\n", top);
  printList(list);

  reverse(list);
  printf("iterative reverse\n");
  printList(list);

  reverseRecursive(list);
  printf("recursive reverse\n");
  printList(list);
  
  destroyList(list);
  return 0;
}

