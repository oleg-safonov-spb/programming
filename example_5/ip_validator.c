// Copyright 2026 Oleg Safonov

#include "ip_validator.h"

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

int validate_ip_full(const char *ip) {
  regex_t regex;
  int result;

  // Шаблон проверяет только структуру: 4 группы цифр (1-3 шт) через точки
  const char *pattern = "^[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}$";

  // Компиляция регулярного выражения
  if (regcomp(&regex, pattern, REG_EXTENDED | REG_NOSUB) != 0) {
    return 0;
  }

  // Выполнение поиска
  result = regexec(&regex, ip, 0, NULL, 0);
  regfree(&regex);

  // Если формат не соответствует регулярному выражению
  if (result != 0) {
    return 0;
  }

  // Проверка диапазонов 0-255 для каждого октета
  int octets[4];
  if (sscanf(ip, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2],
             &octets[3]) != 4) {
    return 0;
  }

  for (int i = 0; i < 4; i++) {
    if (octets[i] < 0 || octets[i] > 255) {
      return 0;
    }
  }

  return 1;
}
