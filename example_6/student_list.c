// Copyright 2026 Oleg Safonov

#include "student_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void delete_by_name(Node **head, Student s) {
  Node *current = *head;
  Node *prev = NULL;

  while (current != NULL) {
    if (strcmp(current->data.name, s.name) == 0) {
      if (prev == NULL) {
        // Если удаляем голову
        *head = current->next;
      } else {
        // Если удаляем в середине или конце
        prev->next = current->next;
      }

      free(current);
      return; // Завершаем после первого удаления
    }
    // Переход к следующему узлу
    prev = current;
    current = current->next;
  }
}

Student *find_best(Node *head) {
  if (head == NULL)
    return NULL;

  Node *current = head;
  Node *best_node = head;

  while (current != NULL) {
    if (current->data.gpa > best_node->data.gpa) {
      best_node = current;
    }
    current = current->next;
  }
  return &(best_node->data);
}
