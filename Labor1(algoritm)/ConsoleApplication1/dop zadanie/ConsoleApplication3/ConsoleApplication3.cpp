#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    srand((unsigned int)time(NULL));
    int n;
    printf("Введите размер квадратной матрицы: ");
    // Используем scanf_s тк просто scanf у меня не работает(Не безопастно C4996)
    if (scanf_s("%d", &n) != 1 || n <= 0) {
        printf("Ошибка ввода. Пожалуйста, введите положительное целое число.\n");
        return 1; // Завершение программы в случае ошибки ввода
    }
    // Создание динамического двумерного массива
    int** v = (int**)malloc(n * sizeof(int*));
    if (v == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1; // Завершение программы в случае ошибки
    }
    for (int i = 0; i < n; i++) {
        v[i] = (int*)malloc(n * sizeof(int));
        if (v[i] == NULL) {
            printf("Ошибка выделения памяти.\n");
            for (int j = 0; j < i; j++) {
                free(v[j]); // Освобождение выделенной памяти
            }
            free(v);
            return 1; // Завершение программы в случае ошибки
        }
    }
    // Заполнение массива случайными значениями 
    printf("Сгенерированная матрица:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v[i][j] = rand() % 100;  // Генерация числа от 0 до 99
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }

    // Вычисление суммы элементов выше главной диагонали и на ней
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) { // Работа главной диагонали
            sum += v[i][j];
        }
    }
    // Вывод результата и освобожд памяти
    printf("Сумма элементов выше главной диагонали и на ней: %d\n", sum);
    for (int i = 0; i < n; i++) {
        free(v[i]);
    }
    free(v);

    return 0;
}