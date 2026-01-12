// Copyright 2026 Oleg Safonov
// 7. Работа с файлами и файловой системой в программах

#include <stdio.h>

#include "file_io.h"

int main() {
  Node *list = NULL;
  const char *filename = "database.bin";

  // 1. Создание данных
  Student s1 = {"Иванов Глеб", 101, 4.5f};
  Student s2 = {"Петрова Ева", 102, 3.8f};
  Student s3 = {"Иванов Олег", 103, 4.2f}; // Однофамилец
  insert_front(&list, s1);
  insert_front(&list, s2);
  insert_front(&list, s3);

  printf("Исходный список\n");
  print_list(list);

  // 2. Сохранение
  if (save_to_file(list, filename)) {
    printf("\n[OK] Данные сериализованы в %s\n", filename);
  } else {
    printf("\n[ERROR] Ошибка записи файла.\n");
  }

  // 3. Загрузка в новый список
  Node *restored_list = load_from_file(filename);
  printf("\nВосстановленный список\n");
  print_list(restored_list);

  // Очистка
  clear_list(&list);
  clear_list(&restored_list);

  return 0;
}
