#include "bracket.h"
#include "stack.h"
#include <assert.h>
#include <stdio.h>

void test_stack_basic() {
  Stack s;
  init_stack(&s);

  // Проверка начального состояния
  assert(is_empty(&s) == true);

  // Проверка Push
  push(&s, 'a');
  assert(is_empty(&s) == false);
  assert(peek(&s) == 'a');

  push(&s, 'b');
  assert(peek(&s) == 'b');

  // Проверка Pop (LIFO)
  assert(pop(&s) == 'b');
  assert(peek(&s) == 'a');
  assert(pop(&s) == 'a');

  // Проверка после очистки
  assert(is_empty(&s) == true);

  printf("[  PASSED  ] Stack basic LIFO tests\n");
}

void test_bracket_logic() {
  // Позитивные сценарии
  assert(check_brackets("( [ { } ] )") == BRACKETS_BALANCED);
  assert(check_brackets("a + b * (c - d)") == BRACKETS_BALANCED);
  assert(check_brackets("") ==
         BRACKETS_NONE); // Если пустая строка считается за "отсутствие скобок"

  // Негативные сценарии
  assert(check_brackets("( [ ) ]") == BRACKETS_ERROR); // Неверный порядок
  assert(check_brackets("((())") == BRACKETS_ERROR);   // Не закрыта
  assert(check_brackets("())") == BRACKETS_ERROR);     // Лишняя закрывающая
  assert(check_brackets("{ [ ]") == BRACKETS_ERROR);   // Несоответствие типов

  printf("[  PASSED  ] Bracket validation tests\n");
}

int main() {
  printf("[==========] Running tests from example_8\n");

  test_stack_basic();
  test_bracket_logic();

  printf("[  PASSED  ] All tests from example_8\n");
  return 0;
}
