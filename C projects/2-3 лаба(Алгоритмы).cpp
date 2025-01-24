#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

// Генерация случайной строки
void GenerateDataset(char* filename, int num) {
    srand(time(NULL)); // Инициализация генератора случайных чисел

    FILE* file = fopen(filename, "w"); // Открытие файла для записи
    if (file == NULL) {
        printf("Open error\n");
        return;
    }

    // Генерация и запись случайных строк в файл
    for (int i = 0; i < num; ++i) {
        fprintf(file, "%c%c%c\n", 'A' + rand() % 26, 'A' + rand() % 26, 'A' + rand() % 26);
    }

    fclose(file); // Закрытие файла
}

// Функция для обмена значений двух строк
void swap(char** x, char** y) {
    char* temp = *x;
    *x = *y;
    *y = temp;
}

// Просеивание элемента вниз пирамиды
void heapify(char** arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && strcmp(arr[l], arr[largest]) < 0) // Изменение условия для сортировки в порядке убывания
        largest = l;

    if (r < n && strcmp(arr[r], arr[largest]) < 0) // Изменение условия для сортировки в порядке убывания
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Пирамидальная сортировка
int heapSort(char** arr, int n) {
    int comparisons = 0;

    // Построение max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Извлечение элементов из кучи один за другим
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
        comparisons += i; // Количество сравнений
    }

    return comparisons;
}

// Функция для сортировки и записи в файл
int SortDataset(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Open error\n");
        return -1;
    }

    // Считывание строк из файла
    char** lines = NULL;
    char line[4]; // Так как каждая строка содержит три буквы и символ конца строки '\0'
    int numLines = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        char* temp = _strdup(line); // Копируем строку, чтобы избежать ее перезаписи
        lines = (char**)realloc(lines, (numLines + 1) * sizeof(char*));
        lines[numLines++] = temp;
    }

    fclose(file);

    // Сортировка строк
    int comparisons = heapSort(lines, numLines);

    // Запись отсортированных строк в новый файл
    char* sortedFilename = (char*)malloc(strlen(filename) + 6);
    strcpy(sortedFilename, filename);
    strcat(sortedFilename,".txt");

    file = fopen(sortedFilename, "w");
    if (file == NULL) {
        printf("Create file for record - Error\n");
        return -1;
    }

    for (int i = 0; i < numLines; ++i) {
        fprintf(file, "%s", lines[i]);
        free(lines[i]); // Освобождение памяти для каждой строки
    }

    fclose(file);
    free(lines);
    free(sortedFilename);

    return comparisons;
}

// Основная функция
int main() {
    int nums[] = { 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096 };
    int numTests = sizeof(nums) / sizeof(nums[0]);

    FILE* resultsFile = fopen("sorting_results.txt", "w");
    if (resultsFile == NULL) {
        printf("Create file for results - Error\n");
        return -1;
    }

    fprintf(resultsFile, "num\tT1\t\tT2\t\tcomparisons\t\tTexp\t\tTexp2\n");

    for (int i = 0; i < numTests; ++i) {
        int num = nums[i];
        char filename[20];
        sprintf(filename, "data_%d.txt", num);

        // Генерация файла данных
        GenerateDataset(filename, num);

        // Сортировка файла и получение количества сравнений
        int comparisons = SortDataset(filename);

        // Теоретические оценки
        double T1 = pow(num, 2);
        double T2 = num * log2(num);
        double Texp = comparisons / T1;
        double Texp2 = comparisons / T2;
        // Запись результатов в файл
        fprintf(resultsFile, "%d\t%.2f\t\t%.2f\t\t%d\t\t%.2f\t\t%.2f\n", num, T1, T2, comparisons, Texp, Texp2);
    }

    fclose(resultsFile);

    return 0;
}