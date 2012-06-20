#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>

typedef struct NodeT {
  struct NodeT *next;
  int value;
} Node;

typedef struct ListT {
  Node *head;
  int length;
} List;

List *createList() {
  List *newList = (List*) malloc(sizeof(List));
  newList->head = NULL;
  newList->length = 0;
  return newList;
}

Node *createNode(int value) {
  Node *newNode = (Node*) malloc(sizeof(Node));
  newNode->next = NULL;
  newNode->value = value;
  return newNode;
}

/**
 * Insert value at position. The list is zero indexed.
 */
void insertNode(List *ls, int value, int position) {
  Node *newNode = createNode(value);
  if (position == 0 || ls->head == NULL) {
    newNode->next = ls->head;
    ls->head = newNode;
  }
  Node *cur = ls->head;
  Node *prev = NULL;
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
void removeNode(List *ls, int position) {
  if (position >= ls->length) return;

  Node *cur = ls->head;
  Node *prev = NULL;

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

void push(List *ls, int value) {
  Node *newNode = createNode(value);
  newNode->next = ls->head;
  ls->head = newNode;
  ls->length++;
}

int pop(List *ls) {
  Node *toDelete = ls->head;
  int toReturn = toDelete->value;
  ls->head = ls->head->next;
  free(toDelete);
  ls->length--;
  return toReturn;
}

