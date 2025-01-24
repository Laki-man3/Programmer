#include <stdio.h>
#include <math.h>

/* №1.6 Нахождение корней квадратного уравнения через коэффициенты.*/

int main() {
    float a, b, c, d, x1, x2;
    printf("a= "); scanf("%f", &a);
    printf("b= "); scanf("%f", &b);
    printf("c= "); scanf("%f", &c);
    d = b * b - 4 * a * c;
    if (d > 0) {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        printf("x1 = %f, x2 = %f\n", x1, x2);} 
    else if (d == 0) {
        x1 = x2 = -b / (2 * a);
        printf("x1 = x2 = %f\n", x1);}
    else {printf("Корней нет\n");}
    return 0;
}