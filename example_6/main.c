// Copyright 2026 Oleg Safonov
// 6. Реализация линейных списков

#include <stdio.h>

#include "student_list.h"

int main() {
  Node *list = NULL;

  Student s1 = {"Иванов Глеб", 101, 4.5f};
  Student s2 = {"Петрова Ева", 102, 3.8f};
  Student s3 = {"Иванов Олег", 103, 4.2f}; // Однофамилец
  insert_front(&list, s1);
  insert_front(&list, s2);
  insert_front(&list, s3);

  printf("\nСписок студентов\n");
  print_list(list);

  Student *best = find_best(list);
  if (best) {
    printf("\nЛучший студент: %s с баллом %.2f\n", best->name, best->gpa);
  }

  printf("\nУдаление студента '%s'...\n", s3.name);
  delete_by_name(&list, s3);

  printf("\nСписок студентов после удаления\n");
  print_list(list);

  clear_list(&list);
  printf("\nПамять очищена. Программа завершена.\n");

  return 0;
}
