// Copyright 2026 Oleg Safonov
// 5. Использование регулярных выражений в программах

#include <stdio.h>
#include <string.h>

#include "ip_validator.h"

int main() {
  char input[128];

  printf(
      "Проверка IPv4 (формат XXX.XXX.XXX.XXX). Введите 'exit' для выхода.\n");

  while (1) {
    printf("\nВведите IP: ");
    // 1. Читаем всю строку целиком
    if (fgets(input, sizeof(input), stdin) == NULL)
      break;

    // 2. Убираем символ '\n', который fgets всегда добавляет в конце
    input[strcspn(input, "\n")] = 0;

    // 3. Проверяем на выход
    if (strcmp(input, "exit") == 0)
      break;

    // 4. Проверяем пустой ввод (если пользователь просто нажал Enter)
    if (input[0] == '\0')
      continue;

    // 5. Валидируем
    if (validate_ip_full(input)) {
      printf("[OK] '%s' - корректный IP.\n", input);
    } else {
      printf("[FAIL] '%s' - ошибка.\n", input);
    }
  }

  printf("Программа завершена.\n");
  return 0;
}
