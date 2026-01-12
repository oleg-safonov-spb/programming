// Copyright 2026 Oleg Safonov

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct {
  char surname[50];
  char department[50];
  double salary;
  int experience;
} Employee;

// Прототип функции-компаратора для qsort
int compare_employees(const void *a, const void *b);

// Прототип функции для вывода таблицы
void print_staff_table(Employee *staff, int n);

#endif
