#include <stdio.h>
#include <math.h>
//№5.33 Натуральное число из n знаков является числом Армстронга, если сумма его цифр, возведенная в n-ю степень равна самому числу.
int arms(int num) {
    int num1, ost, cnt = 0, result = 0;
    num1 = num;
    while (num1 != 0) {
        num1 /= 10;
        cnt++;}
    num1 = num;
    while (num1 != 0) {
        ost = num1 % 10;
        result += pow(ost, cnt);
        num1 /= 10;}
    if (result == num) {return 1;} 
    else {return 0;}}

int main() {
    printf("Четырехзначные числа Армстронга:\n");
    for (int i = 1000; i <= 9999; i++) {
        if (arms(i)) {
            printf("%d\n", i);}}
    return 0;
}
