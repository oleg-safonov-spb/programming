// Copyright 2026 Oleg Safonov

#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

int **allocate_matrix(int n, int m) {
  // Выделяем память под массив указателей на строки
  int **matrix = (int **)malloc(n * sizeof(int *));
  if (!matrix)
    return NULL;

  for (int i = 0; i < n; i++) {
    matrix[i] = (int *)malloc(m * sizeof(int));

    // Если память под строку не выделилась:
    if (!matrix[i]) {
      // Освобождаем все ПРЕДЫДУЩИЕ успешно выделенные строки
      for (int j = 0; j < i; j++) {
        free(matrix[j]);
      }
      // Освобождаем сам массив указателей
      free(matrix);
      return NULL;
    }
  }
  return matrix;
}

void fill_matrix(int **matrix, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      matrix[i][j] = rand() % 100;
    }
  }
}

void print_matrix(int **matrix, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%3d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int **transpose_matrix(int **matrix, int n, int m) {
  // Выделяем память под матрицу M x N
  int **t_matrix = allocate_matrix(m, n);
  if (!t_matrix)
    return NULL;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      t_matrix[j][i] = matrix[i][j];
    }
  }
  return t_matrix;
}

void free_matrix(int **matrix, int n) {
  for (int i = 0; i < n; i++) {
    free(matrix[i]);
  }
  free(matrix);
}
