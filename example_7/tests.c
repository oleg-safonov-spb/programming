#include "file_io.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Вспомогательная функция для сравнения float
int is_close_f(float a, float b) { return fabsf(a - b) < 1e-6f; }

void test_file_io_integrity() {
  const char *test_filename = "test_students.bin";
  Node *original_list = NULL;

  // 1. Подготовка данных
  Student s1 = {"Ivanov", 101, 4.5f};
  Student s2 = {"Petrov", 202, 3.8f};
  insert_front(&original_list, s1);
  insert_front(&original_list, s2);

  // 2. Сохранение в файл
  int save_res = save_to_file(original_list, test_filename);
  assert(save_res == 1); // Предполагаем, что 1 - успех

  // 3. Загрузка в новый список
  Node *loaded_list = load_from_file(test_filename);
  assert(loaded_list != NULL);

  // 4. Проверка данных (с учетом того, что insert_front инвертирует порядок)
  // Первым в загруженном списке должен быть Petrov (так как он вставлялся
  // последним)
  assert(strcmp(loaded_list->data.name, "Petrov") == 0);
  assert(loaded_list->data.group == 202);
  assert(is_close_f(loaded_list->data.gpa, 3.8f));

  assert(loaded_list->next != NULL);
  assert(strcmp(loaded_list->next->data.name, "Ivanov") == 0);
  assert(loaded_list->next->data.group == 101);
  assert(is_close_f(loaded_list->next->data.gpa, 4.5f));

  // 5. Очистка
  clear_list(&original_list);
  clear_list(&loaded_list);
  remove(test_filename); // Удаляем временный файл теста

  printf("[  PASSED  ] File I/O integrity test\n");
}

void test_load_nonexistent_file() {
  // Тест на попытку чтения несуществующего файла
  Node *list = load_from_file("non_existent_file.xyz");
  assert(list == NULL);
  printf("[  PASSED  ] Non-existent file handling test\n");
}

int main() {
  printf("[==========] Running tests from example_7\n");

  test_file_io_integrity();
  test_load_nonexistent_file();

  printf("[  PASSED  ] All tests from example_7\n");
  return 0;
}
