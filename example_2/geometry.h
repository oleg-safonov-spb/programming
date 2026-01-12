// Copyright 2026 Oleg Safonov

#ifndef GEOMETRY_H
#define GEOMETRY_H

// Константа PI
#define MY_PI 3.14159265358979323846

// Прототипы функций для круга
double circle_area(double radius);
double circle_perimeter(double radius);

// Прототипы для прямоугольника
double rect_area(double width, double height);
double rect_perimeter(double width, double height);

// Прототипы для треугольника (по трем сторонам - формула Герона)
double triangle_area(double a, double b, double c);
double triangle_perimeter(double a, double b, double c);

#endif
