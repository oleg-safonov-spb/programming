// Copyright 2026 Oleg Safonov
// 3. Указатели и массивы

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matrix.h"

int main() {
  int n, m;
  srand((unsigned int)time(NULL));

  char buf[100];
  printf("Введите размеры матрицы N и M: ");

  if (fgets(buf, sizeof(buf), stdin) == NULL) {
    return 1; // Ошибка чтения
  }

  if (sscanf(buf, "%d %d", &n, &m) != 2 || n <= 0 || m <= 0) {
    printf("Ошибка: размеры должны быть положительными целыми числами.\n");
    return 1;
  }

  // 1. Создаем исходную матрицу
  int **matrix = allocate_matrix(n, m);
  if (!matrix) {
    fprintf(stderr, "Ошибка: не удалось выделить память под матрицу.\n");
    return 1;
  }

  fill_matrix(matrix, n, m);
  printf("\nИсходная матрица (%dx%d):\n", n, m);
  print_matrix(matrix, n, m);

  // 2. Создаем транспонированную матрицу
  int **t_matrix = transpose_matrix(matrix, n, m);
  if (!t_matrix) {
    fprintf(stderr, "Ошибка: не удалось выделить память под матрицу.\n");
    // Перед выходом нужно очистить первую матрицу!
    free_matrix(matrix, n);
    return 1;
  }

  printf("\nТранспонированная матрица (%dx%d):\n", m, n);
  print_matrix(t_matrix, m, n);

  // 3. Корректное освобождение всей памяти
  free_matrix(t_matrix, m); // Чистим вторую (размер M x N)
  free_matrix(matrix, n);   // Чистим первую (размер N x M)

  printf("\nВся динамическая память успешно освобождена.\n");

  return 0;
}
