// Copyright 2026 Oleg Safonov
// 4. Стандартная библиотека

#include <stdio.h>
#include <stdlib.h>

#include "employee.h"

int main() {
  Employee staff[] = {
      {"Иванов", "ИТ", 150000.0, 5},  {"Петров", "УП", 80000.0, 3},
      {"Сидоров", "ИТ", 180000.0, 8}, {"Белов", "ИТ", 120000.0, 4},
      {"Морозов", "УП", 75000.0, 1},  {"Волков", "ИТ", 200000.0, 10},
      {"Павлов", "УП", 90000.0, 4},   {"Тихонов", "ИТ", 135000.0, 3}};

  int n = sizeof(staff) / sizeof(staff[0]);

  printf("Массив сотрудников\n");
  print_staff_table(staff, n);

  // Сортировка
  qsort(staff, n, sizeof(Employee), compare_employees);

  printf("\nМассив сотрудников после сортировки (Отдел -> Зарплата)\n");
  print_staff_table(staff, n);

  return 0;
}
