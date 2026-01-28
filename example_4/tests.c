#include "employee.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Вспомогательная функция для сравнения зарплат (double)
int is_close(double a, double b) {
  // 1e-9 — это точность до 9 знака после запятой
  return fabs(a - b) < 1e-9;
}

void test_compare_employees() {
  // Данные для тестов
  Employee e_hr_high = {"Ivanov", "HR", 5000.0, 5};
  Employee e_hr_low = {"Petrov", "HR", 3000.0, 10};
  Employee e_it_med = {"Sidorov", "IT", 4000.0, 3};

  // Тест 1: Разные отделы (HR vs IT)
  // "HR" идет раньше "IT" по алфавиту, значит результат < 0
  assert(compare_employees(&e_hr_high, &e_it_med) < 0);

  // Тест 2: Один отдел, разные зарплаты (HR: 5000 vs 3000)
  // Сортировка по УБЫВАНИЮ зарплаты.
  // Тот, у кого 5000, должен быть "меньше" (стоять выше в списке), чем тот, у
  // кого 3000. Следовательно, компаратор должен вернуть отрицательное число.
  assert(compare_employees(&e_hr_high, &e_hr_low) < 0);

  // Тест 3: Обратная проверка зарплат (3000 vs 5000)
  assert(compare_employees(&e_hr_low, &e_hr_high) > 0);

  // Тест 4: Одинаковые отделы и одинаковые зарплаты
  Employee e_hr_copy = {"Sokolov", "HR", 5000.0, 2};
  assert(compare_employees(&e_hr_high, &e_hr_copy) == 0);

  printf("[  PASSED  ] Comparator tests (Department asc, Salary desc)\n");
}

void test_employee_struct_init() {
  Employee e = {"Smirnov", "Dev", 7500.0, 4};
  assert(strcmp(e.department, "Dev") == 0);
  assert(is_close(e.salary, 7500.0));
  printf("[  PASSED  ] Structure initialization tests\n");
}

int main() {
  printf("[==========] Running tests from example_4\n");
  test_employee_struct_init();
  test_compare_employees();
  printf("[  PASSED  ] All tests from example_4\n");
  return 0;
}
