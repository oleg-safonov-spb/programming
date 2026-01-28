#include "student_list.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Вспомогательная функция для сравнения float
int is_close_f(float a, float b) { return fabsf(a - b) < 1e-6f; }

void test_insert_and_find_best() {
  Node *head = NULL;

  // Тест 1: Поиск в пустом списке
  assert(find_best(head) == NULL);

  // Добавляем студентов
  Student s1 = {"Ivanov", 101, 4.5f};
  Student s2 = {"Petrov", 102, 4.8f};
  Student s3 = {"Sidorov", 101, 4.2f};

  insert_front(&head, s1);
  insert_front(&head, s2);
  insert_front(&head, s3);

  // Тест 2: Поиск лучшего (должен быть Petrov с 4.8)
  Student *best = find_best(head);
  assert(best != NULL);
  assert(strcmp(best->name, "Petrov") == 0);
  assert(is_close_f(best->gpa, 4.8f));

  clear_list(&head);
  assert(head == NULL);
  printf("[  PASSED  ] Insert and Find Best tests\n");
}

void test_delete_by_name() {
  Node *head = NULL;
  Student s1 = {"Ivanov", 101, 4.5f};
  Student s2 = {"Petrov", 102, 4.8f};

  insert_front(&head, s1);
  insert_front(&head, s2);

  // Тест 3: Удаление существующего студента
  delete_by_name(&head, s2); // Удаляем Petrov
  Student *best = find_best(head);
  assert(strcmp(best->name, "Ivanov") == 0); // Теперь лучший Ivanov

  // Тест 4: Удаление последнего студента
  delete_by_name(&head, s1);
  assert(head == NULL);

  clear_list(&head);
  printf("[  PASSED  ] Delete by name tests\n");
}

int main() {
  printf("[==========] Running tests from example_6\n");

  test_insert_and_find_best();
  test_delete_by_name();

  printf("[  PASSED  ] All tests from example_6\n");
  return 0;
}
