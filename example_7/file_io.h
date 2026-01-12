// Copyright 2026 Oleg Safonov

#ifndef FILE_IO_H
#define FILE_IO_H

typedef struct Student {
  char name[50];
  int group;
  float gpa;
} Student;

typedef struct Node {
  Student data;
  struct Node *next;
} Node;

void insert_front(Node **head, Student s);
void print_list(Node *head);
void clear_list(Node **head);
int save_to_file(Node *head, const char *filename);
Node *load_from_file(const char *filename);

#endif
