#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef struct List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List* list = (List*) calloc(1, sizeof(List));
    list->head = NULL;
    list->current = NULL;
    list->tail = NULL;
    return list;
}

void * firstList(List * list) {
  if (list == NULL) return NULL;
  if (list->head && list->head->data)
  {
    list->current = list->head;
    return list->head->data;
  }
  return NULL;
}

void * nextList(List * list) {
  if (list->current == NULL) return NULL;
  Node *aux = list->current->next;
  list->current = aux;
  return list->current;
}

void * lastList(List * list) {
  if (list == NULL) return NULL;
  if (list->tail && list->tail->data)
  {
    list->current = list->tail;
    return list->tail->data;
  }
  return NULL;
}

void * prevList(List * list) {
  return NULL;
}

void pushFront(List * list, void * data) {
  
}

void pushBack(List * list, void * data) {
  /*Node* n = createNode(data);
  if (list->head == NULL)
    list->head = n;
  else
    list->tail->next = n;
  list->tail = n;*/
  list->current = list->tail;
  pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  
  
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}