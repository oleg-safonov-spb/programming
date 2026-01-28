#include "ip_validator.h"
#include <assert.h>
#include <stdio.h>

void test_valid_ips() {
  // Позитивные тесты
  assert(validate_ip_full("127.0.0.1") == 1);
  assert(validate_ip_full("0.0.0.0") == 1);
  assert(validate_ip_full("255.255.255.255") == 1);
  assert(validate_ip_full("192.168.1.1") == 1);
  printf("[  PASSED  ] Valid IP tests\n");
}

void test_invalid_range_ips() {
  // Числа вне диапазона 0-255
  assert(validate_ip_full("256.0.0.1") == 0);
  assert(validate_ip_full("192.168.1.300") == 0);
  assert(validate_ip_full("123.456.78.90") == 0);
  printf("[  PASSED  ] Invalid range tests\n");
}

void test_invalid_format_ips() {
  // Некорректное количество сегментов или лишние символы
  assert(validate_ip_full("192.168.1") == 0);     // Мало сегментов
  assert(validate_ip_full("192.168.1.1.1") == 0); // Много сегментов
  assert(validate_ip_full("192.168.1.a") == 0);   // Буквы
  assert(validate_ip_full("192.168..1") == 0);    // Пустой сегмент
  assert(validate_ip_full("abc.def.gh.ij") == 0); // Полный бред
  assert(validate_ip_full("") == 0);              // Пустая строка
  assert(validate_ip_full("192. 168.1.1") == 0);  // Пробелы
  printf("[  PASSED  ] Invalid format tests\n");
}

int main() {
  printf("[==========] Running tests from example_5\n");

  test_valid_ips();
  test_invalid_range_ips();
  test_invalid_format_ips();

  printf("[  PASSED  ] All tests from example_5\n");
  return 0;
}
