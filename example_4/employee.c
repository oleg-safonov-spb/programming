// Copyright 2026 Oleg Safonov

#include "employee.h"

#include <stdio.h>
#include <string.h>

int compare_employees(const void *a, const void *b) {
  const Employee *emp1 = (const Employee *)a;
  const Employee *emp2 = (const Employee *)b;

  // 1 уровень: Сравнение отделов (по алфавиту)
  int dept_cmp = strcmp(emp1->department, emp2->department);
  if (dept_cmp != 0) {
    return dept_cmp;
  }

  // 2 уровень: Зарплаты (по убыванию)
  if (emp1->salary < emp2->salary)
    return 1;
  if (emp1->salary > emp2->salary)
    return -1;
  return 0;
}

void print_staff_table(Employee *staff, int n) {
  printf("--------------------------------------------------\n");
  printf("%s\t| %s\t| %s\t| %s\n", "Фамилия", "Отдел", "Зарплата, р.",
         "Стаж, л.");
  printf("--------------------------------------------------\n");
  for (int i = 0; i < n; i++) {
    printf("%s\t| %s\t| %10.2f\t| %2d\n", staff[i].surname, staff[i].department,
           staff[i].salary, staff[i].experience);
  }
  printf("--------------------------------------------------\n");
}
