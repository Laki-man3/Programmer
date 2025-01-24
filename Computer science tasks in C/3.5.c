#include <stdio.h>
/* №3.5 Получение N-го числа Фибоначи, т.е. числа из последовательности
0 1 1 2 3 5 8 13 21 34
ci= ci-1 + ci-2 (c1 = 0 c2 = 1 ) n=10 c=34*/
int fibonacci(int n) {
    if (n <= 0) {return 0;} 
    else if (n == 1) {
        return 0;} 
    else {
        int a = 0, b = 1, c;
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;}
        return c;}}

int main() {
    int N;
    printf("Введите N: "); scanf("%d", &N);
    int result = fibonacci(N);
    printf("Число Фибоначчи: %d\n", result);
    return 0;
}
