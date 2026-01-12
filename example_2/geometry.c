// Copyright 2026 Oleg Safonov

#include "geometry.h"

#include <math.h>

double circle_area(double radius) { return MY_PI * radius * radius; }

double circle_perimeter(double radius) { return 2 * MY_PI * radius; }

double rect_area(double width, double height) { return width * height; }

double rect_perimeter(double width, double height) {
  return 2 * (width + height);
}

double triangle_perimeter(double a, double b, double c) { return a + b + c; }

double triangle_area(double a, double b, double c) {
  double p = triangle_perimeter(a, b, c) / 2.0;
  return sqrt(p * (p - a) * (p - b) * (p - c));
}
