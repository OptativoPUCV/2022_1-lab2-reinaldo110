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
    Node * first;
    Node * last;
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
    list->first = NULL;
    list->current = NULL;
    list->last = NULL;
    return list;
}

void * firstList(List * list) {
  if (list == NULL) return NULL;
  if (list->first && list->first->data)
  {
    list->current = list->first;
    return list->first->data;
  }
  return NULL;
}

void * nextList(List * list) {
  return NULL;
}

void * lastList(List * list) {
  if (list == NULL) return NULL;
  if (list->last && list->last->data)
  {
    list->current = list->last;
    return list->last->data;
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
  if (list->first == NULL)
    list->first = n;
  else
    list->last->next = n;
  list->last = n;*/
  list->current = list->last;
  pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  
  
}

void * popFront(List * list) {
    list->current = list->first;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->last;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  return NULL;
}

void cleanList(List * list) {
    while (list->first != NULL) {
        popFront(list);
    }
}