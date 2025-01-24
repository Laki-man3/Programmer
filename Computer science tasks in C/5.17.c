#include <stdio.h>
//№5.17 Записать целое число в обратной последовательности
int main() {
    int num;
    printf("num = ");scanf("%d", &num);
    int obr = 0;
    while (num != 0) {
        obr = obr * 10 + num % 10;
        num /= 10;}
    printf("%d\n", obr);
    return 0;
}
