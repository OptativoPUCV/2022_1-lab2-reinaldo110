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
  if (list->current == NULL || list->current->next == NULL) return NULL;
  list->current = list->current->next;
  return list->current->data;
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
  if (list->current == NULL || list->current->prev == NULL) return NULL;
  list->current = list->current->prev;
  return list->current->data;
}

void pushFront(List * list, void * data) {
  Node* n = createNode(data);
  if (list->tail == NULL && list->head == NULL)
  {
    list->head = n;
    list->tail = n;
  }
  else
  {
    n->next = list->head;
    list->head = n;
  }
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
  Node* n = createNode(data);
  if (list->current != list->tail)
  {
    list->current->next = n;
    n->prev = list->current;
  }
  else
  {
    list->tail->next = n;
    n->prev = list->tail;
    list->tail = n;
  }
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
  Node* n = list->current;
  if (list->current == list->head)
  {
    list->head = list->current->next;
    list->head->prev = NULL;
    list->head->next = list->current->next->next;
    free(list->current);
    return n->data;
  }
  else if (list->current == list->tail)
  {
    list->current->prev = list->tail;
    free(list->current);
    return n->data;
  }
  return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}