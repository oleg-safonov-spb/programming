// Copyright 2026 Oleg Safonov

#include "file_io.h"

#include <stdio.h>
#include <stdlib.h>

void insert_front(Node **head, Student s) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (!new_node)
    return;
  new_node->data = s;
  new_node->next = *head;
  *head = new_node;
}

void print_list(Node *head) {
  if (!head) {
    printf("Список пуст.\n");
    return;
  }
  printf("--------------------------------------------------\n");
  printf(" %15s\t| %15s\t| %15s\n", "Фамилия", "Группа", "Средний балл");
  printf("--------------------------------------------------\n");
  while (head != NULL) {
    printf(" %15s\t| %10d\t| %.2f\n", head->data.name, head->data.group,
           head->data.gpa);
    head = head->next;
  }
  printf("--------------------------------------------------\n");
}

void clear_list(Node **head) {
  Node *current = *head;
  while (current != NULL) {
    Node *next = current->next;
    free(current);
    current = next;
  }
  *head = NULL;
}

int save_to_file(Node *head, const char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (!fp)
    return 0;

  Node *current = head;
  while (current != NULL) {
    if (fwrite(&(current->data), sizeof(Student), 1, fp) != 1) {
      fclose(fp);
      return 0;
    }
    current = current->next;
  }
  fclose(fp);
  return 1;
}

Node *load_from_file(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp)
    return NULL;

  Node *head = NULL;
  Node *tail = NULL;
  Student s;

  while (fread(&s, sizeof(Student), 1, fp) == 1) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node)
      break;
    new_node->data = s;
    new_node->next = NULL;

    if (head == NULL) {
      head = new_node;
      tail = new_node;
    } else {
      tail->next = new_node;
      tail = new_node;
    }
  }
  fclose(fp);
  return head;
}
