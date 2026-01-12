// Copyright 2026 Oleg Safonov
// 8. Реализация динамических структур данных стек и очередь

#include <stdio.h>
#include <string.h>

#include "bracket.h"

int main() {
  char expression[100];
  printf("Проверка баланса скобок ({[ ]}). Введите 'exit' для выхода.\n");

  while (1) {
    printf("\nВведите выражение (можно с пробелами): ");

    // 1. Читаем всю строку, включая пробелы и \n
    if (fgets(expression, sizeof(expression), stdin) == NULL) {
      break; // Ошибка ввода или EOF
    }

    // 2. Удаляем символ переноса строки '\n' в конце
    // strcspn находит позицию первого символа из набора "\n",
    // и мы ставим туда завершающий нуль-символ.
    expression[strcspn(expression, "\n")] = '\0';

    // 3. Проверяем команду выхода
    if (strcmp(expression, "exit") == 0) {
      break;
    }

    // 4. Проверяем на пустой ввод (если пользователь нажал Enter)
    if (expression[0] == '\0') {
      continue;
    }

    // 5. Проверяем баланс скобок
    BracketResult result = check_brackets(expression);

    switch (result) {
    case BRACKETS_BALANCED:
      printf("[OK] Скобки расставлены верно.\n");
      break;
    case BRACKETS_ERROR:
      printf("[ERROR] Ошибка в скобках!\n");
      break;
    case BRACKETS_NONE:
      printf("[NONE] Скобки отсутствуют.\n");
      break;
    }
  }

  printf("Программа завершена.\n");
  return 0;
}
