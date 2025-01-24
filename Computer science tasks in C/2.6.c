#include <stdio.h>
/*№2.6Ввести матрицу и выдать на печать
а) число элементов >, <, == нулю. Определить максимум и минимум.
б) S элементов <0, > 0, S элементов всей матрицы
в) S элементов диагонали, S элементов по строкам, S элементов по столбцам
г) Определить номер столбца на пересечении которых находится минимальный, максимальный элементы.*/

int a(int r, int c, int m[r][c]) {
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, max=0;
    //cnt1 - больше нуля, cnt2 - меньше нуля, cnt3 - равно нулю.
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(m[i][j] > 0) {cnt1++;} 
            else if(m[i][j] < 0) {cnt2++;} 
            else {cnt3++;}
            if(m[i][j] > max) {
                max = m[i][j];}}}
    int min = max;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(m[i][j] < min) {
                min = m[i][j];}}}
    printf("Количество элементов больше нуля: %d\n", cnt1);
    printf("  Количество элементов меньше нуля: %d\n", cnt2);
    printf("  Количество элементов, равное нулю: %d\n", cnt3);
    printf("  Максимальный элемент: %d\n", max);
    printf("  Минимальный элемент: %d\n", min);
    return 0;}

int b(int r, int c, int m[r][c]) {
    int sump = 0, sumn = 0, sum=0;
    //sump - положительные, sumn - отрицательные, sum - всей матрицы.
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(m[i][j] > 0) {sump+=m[i][j];} 
            else if(m[i][j] < 0) {sumn+=m[i][j];}
            sum+=m[i][j];}}
    printf("Сумма элементов больше 0: %d\n", sump);
    printf("  Сумма элементов меньше 0: %d\n", sumn);
    printf("  Сумма элементов в матрице: %d\n", sum);
    return 0;}

int v(int r, int c, int m[r][c]) {
    int sumdiag=0, sumstr=0, sumstolb=0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if (i==j){sumdiag+=m[i][j];}
            sumstr+=m[i][j];}}
    for(int j = 0; j < c; ++j){
        for(int i = 0; i < r; ++i){
            sumstolb += m[i][j];}}
    printf("Сумма элементов по диагонали: %d\n", sumdiag);
    printf("  Сумма элементов по строкам: %d\n", sumstr);
    printf("  Сумма элементов по столбцам: %d\n", sumstolb);
    return 0;}

int g(int r, int c, int m[r][c]) {
    int minColumn = 0, maxColumn = 0;
    int max = 0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(m[i][j] > max) {
                max = m[i][j];
                maxColumn = j;}}}
    int min = max;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(m[i][j] < min) {
                min = m[i][j];
                minColumn = j;}}}
    printf("Столбец с минимальным элементом равен: %d\n", minColumn+1);
    printf("  Столбец с максимальным элементом равен: %d\n", maxColumn+1);
    return 0;}

int main() {
    int rows, cols;
    printf("Введите количество строк: "); scanf("%d", &rows);
    printf("Введите количество столбцов: "); scanf("%d", &cols);
    int matrix[rows][cols];
    printf("Введите элементы матрицы по одному:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            scanf("%d", &matrix[i][j]);}}
    printf("\na)"); a(rows, cols, matrix);
    printf("\nб)"); b(rows, cols, matrix);
    printf("\nв)"); v(rows, cols, matrix);
    printf("\nг)"); g(rows, cols, matrix);
}