// Copyright 2026 Oleg Safonov
// 1. Управляющие конструкции

#include <stdio.h>

int main() {
  // Счетчики оценок
  int count5 = 0, count4 = 0, count3 = 0, count2 = 0, count1 = 0, countNA = 0;
  int total = 0;
  int input;

  printf("Анализ успеваемости студентов. Введите 0 для выхода.\n");
  printf("\nВведите оценки 1-5 (или -1 для не аттестации):\n");

  while (1) {
    printf("Оценка %d: ", total + 1);
    // Проверка на корректность ввода числа
    if (scanf("%d", &input) != 1) {
      printf("Ошибка: введите число.\n");
      while ((input = getchar()) != '\n' && input != EOF) {
        // Очистка буфера
      }
      continue;
    }

    if (input == 0)
      break;

    switch (input) {
    case 5:
      count5++;
      total++;
      break;
    case 4:
      count4++;
      total++;
      break;
    case 3:
      count3++;
      total++;
      break;
    case 2:
      count2++;
      total++;
      break;
    case 1:
      count1++;
      total++;
      break;
    case -1:
      countNA++;
      total++;
      break;
    default:
      printf("Неверный ввод. Введите 1-5 или -1.\n");
      break;
    }
  }

  if (total > 0) {
    printf("\nИтоговая статистика\n");
    printf("Количество '5': %d\n", count5);
    printf("Количество '4': %d\n", count4);
    printf("Количество '3': %d\n", count3);
    printf("Количество '2': %d\n", count2);
    printf("Количество '1': %d\n", count1);
    printf("Не аттестовано: %d\n", countNA);
    printf("Всего оценок: %d\n", total);

    // Расчет процентов с использованием явного приведения к float
    double percent54 = (double)(count5 + count4) / total * 100;
    double percent543 = (double)(count5 + count4 + count3) / total * 100;

    printf("Процент '5' и '4': %.2f%%\n", percent54);
    printf("Процент '5', '4' и '3': %.2f%%\n", percent543);
  } else {
    printf("\nНет данных.\n");
  }

  return 0;
}
