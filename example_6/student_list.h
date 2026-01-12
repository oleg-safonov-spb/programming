// Copyright 2026 Oleg Safonov

#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

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
void delete_by_name(Node **head, Student s);
Student *find_best(Node *head);

#endif
