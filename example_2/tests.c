#include "geometry.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

// Вспомогательная функция для сравнения double с плавающей точкой
int is_close(double a, double b) {
  // 1e-9 — это точность до 9 знака после запятой
  return fabs(a - b) < 1e-9;
}

void test_circle() {
  assert(is_close(circle_perimeter(1.0), 2 * MY_PI));
  assert(is_close(circle_area(1.0), MY_PI));
  printf("[  PASSED  ] Circle tests\n");
}

void test_rectangle() {
  assert(is_close(rect_area(5.0, 4.0), 20.0));
  assert(is_close(rect_perimeter(5.0, 4.0), 18.0));
  printf("[  PASSED  ] Rectangle tests\n");
}

void test_triangle() {
  assert(is_close(triangle_area(3.0, 4.0, 5.0), 6.0));
  assert(is_close(triangle_perimeter(3.0, 4.0, 5.0), 12.0));
  printf("[  PASSED  ] Triangle tests\n");
}

int main() {
  printf("[==========] Running tests from example_2\n");

  test_circle();
  test_rectangle();
  test_triangle();

  printf("[  PASSED  ] All tests from example_2\n");
  return 0;
}
