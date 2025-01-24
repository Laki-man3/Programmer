#include <stdio.h>
//№5.18 Определить количество трехзначных цифр сумма цифр которых равна n.
int schet(int n) {
    int cnt = 0;
    for (int i = 100; i < 1000; i++) {
        int num = i, sum=0;
        while (num > 0) {
            sum += (num % 10);
            num /= 10;}
        if (sum == n) {cnt++;}}
    return cnt;}
int main() {
    int n;
    printf("n = "); scanf("%d", &n);
    int result = schet(n);
    printf("cnt = %d\n", result);
    return 0;
}