// Copyright 2026 Oleg Safonov
// 2. Сборка программ

#include <stdio.h>

#include "geometry.h"

int main() {
  double r = 5.0;
  double w = 4.0, h = 6.0;
  double ta = 3.0, tb = 4.0, tc = 5.0;

  printf("Геометрические вычисления\n");

  printf("Круг (r=%.1f): S = %.2f, P = %.2f\n", r, circle_area(r),
         circle_perimeter(r));

  printf("Прямоугольник (%.1fx%.1f): S = %.2f, P = %.2f\n", w, h,
         rect_area(w, h), rect_perimeter(w, h));

  printf("Треугольник (%.1f, %.1f, %.1f): S = %.2f, P = %.2f\n", ta, tb, tc,
         triangle_area(ta, tb, tc), triangle_perimeter(ta, tb, tc));

  return 0;
}
