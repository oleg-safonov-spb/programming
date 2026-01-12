// Copyright 2026 Oleg Safonov

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct Node {
  char data;
  struct Node *next;
} Node;

typedef struct Stack {
  Node *top;
} Stack;

void init_stack(Stack *s);
bool is_empty(Stack *s);
void push(Stack *s, char value);
char pop(Stack *s);
char peek(Stack *s);
void clear_stack(Stack *s);

#endif
