#include "matrix.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_matrix_allocation() {
  int rows = 3, cols = 5;
  int **matrix = allocate_matrix(rows, cols);

  assert(matrix != NULL);
  for (int i = 0; i < rows; i++) {
    assert(matrix[i] != NULL);
  }

  free_matrix(matrix, rows);
  printf("[  PASSED  ] Matrix allocation test\n");
}

void test_matrix_transpose() {
  int rows = 2, cols = 3;
  int **matrix = allocate_matrix(rows, cols);

  // Заполняем: matrix[i][j] = какое-то значение
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = i * cols + j;
    }
  }

  int **transposed = transpose_matrix(matrix, rows, cols);
  assert(transposed != NULL);

  // Проверяем: в транспонированной матрице элемент [j][i]
  // должен быть равен элементу [i][j] исходной
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      assert(transposed[j][i] == matrix[i][j]);
    }
  }

  free_matrix(matrix, rows);
  free_matrix(transposed, cols);
  printf("[  PASSED  ] Matrix transpose test (dynamic loop)\n");
}

int main() {
  printf("[==========] Running tests from example_3\n");

  test_matrix_allocation();
  test_matrix_transpose();

  printf("[  PASSED  ] All tests from example_3\n");
  return 0;
}
