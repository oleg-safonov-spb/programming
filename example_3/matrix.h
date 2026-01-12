// Copyright 2026 Oleg Safonov

#ifndef MATRIX_H
#define MATRIX_H

int **allocate_matrix(int n, int m);
void fill_matrix(int **matrix, int n, int m);
void print_matrix(int **matrix, int n, int m);
int **transpose_matrix(int **matrix, int n, int m);
void free_matrix(int **matrix, int n);

#endif
