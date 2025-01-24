#include <stdio.h>
//№5.29 Найти к-ую цифру последовательности n.
int main() {
    int n, k;
    printf("n = "); scanf("%d", &n);
    printf("k = "); scanf("%d", &k);
    for (int i = 0; i <= n; i++) {
        printf("%d ", i);}
    int cnt = 1;
    for (int i = 0; i <= n; i++) {
        int num = i;
        while (num > 0) {
            cnt++;
            if (cnt == k) {
                printf("\nК-ая цифра последовательности: %d\n", num % 10);}
            num /= 10;}}
    return 0;
}
