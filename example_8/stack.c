// Copyright 2026 Oleg Safonov

#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void init_stack(Stack *s) { s->top = NULL; }

bool is_empty(Stack *s) { return s->top == NULL; }

void push(Stack *s, char value) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (!new_node)
    return;
  new_node->data = value;
  new_node->next = s->top;
  s->top = new_node;
}

char pop(Stack *s) {
  if (is_empty(s))
    return '\0';
  Node *temp = s->top;
  char value = temp->data;
  s->top = temp->next;
  free(temp);
  return value;
}

char peek(Stack *s) {
  if (is_empty(s))
    return '\0';
  return s->top->data;
}

void clear_stack(Stack *s) {
  while (!is_empty(s)) {
    pop(s);
  }
}
