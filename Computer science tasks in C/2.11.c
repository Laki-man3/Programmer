#include <stdio.h>
#include <stdlib.h>
/* №2.11 Заполнить матрицу n*n числами по спирали*/
void matr(int n) {
    int** arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(n * sizeof(int));}
    int value = 1;
    int right = 0, left = n - 1;
    int niz = 0, verh = n - 1;
    while (right <= left && niz <= verh) {
        // Вправо
        for (int i = niz; i <= verh; i++) {
            arr[right][i] = value++;}
        right++;
        // Вниз
        for (int i = right; i <= left; i++) {
            arr[i][verh] = value++;}
        verh--;
        // Влево
        if (right <= left) {
            for (int i = verh; i >= niz; i--) {
                arr[left][i] = value++;}
            left--;}
        // Вверх
        if (niz <= verh) {
            for (int i = left; i >= right; i--) {
                arr[i][niz] = value++;}
            niz++;}}
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", arr[i][j]);}
        printf("\n");}
    for (int i = 0; i < n; i++) {
        free(arr[i]);}
    free(arr);}

int main() {
    int n;
    printf("n= "); scanf("%d", &n);
    matr(n);
    return 0;
}