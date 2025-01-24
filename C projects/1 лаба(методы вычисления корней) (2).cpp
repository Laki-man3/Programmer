#include <stdio.h>
#include <math.h>

#define EPS 0.001

double f(double x) {
    return exp(-x) - (0.5 + sqrt(fabs(x)));
}
double bisection(double a, double b) { //метод половинного деления
    int it = 0;
    double x;

    while ((b - a) >= EPS) {
        x = (a + b) / 2.0; //делим отрезок на 2
        if (f(x) == 0.0) // если есть корень - прерываем цикл
            break;
        //если нету, сужаем интервал поиска
        else if (f(x) * f(a) < 0)
            b = x;
        else
            a = x;

        it++;
    }

    printf("M1:cout iterations = %d, X = %lf\n", it, x);
    return x;
}
double hords(double a, double b) { //метод хорд
    int it = 0;
    double x;

    do {
        x = (a * f(b) - b * f(a)) / (f(b) - f(a)); //уравнение прямой хорды, проходящей через крайние точки отрезка [a, f(a)] и  [b, f(b)]

        if (f(x) == 0.0) //опять же, если нашли корень - прерываем
            break;
        else if (f(x) * f(a) < 0)// нет - уточняем до того момента, пока не дойдём до условия eps
            b = x;
        else
            a = x;

        it++;
    } while (fabs(f(x)) < EPS);

    printf("M2:cout iterations = %d, X = %lf\n", it, x);
    return x;
}
/*double kasat(double x0) { //метод касательных
    int it = 0;
    double x = x0;

    do {
        x0 = x; // елси abs(f(x))>=eps
        x = x0 - f(x0) / (exp(-x0) + 0.5 / (2 * sqrt(fabs(x0)))); //пересечение первой касательной с осью Ox в теле цикла

        it++;
    } while (fabs(x) < EPS);

    printf("M3:cout iterations = %d, X = %lf\n", it, x);
    return x;
}
double iterative(double x0) { // Метод итераций
    int it = 0;
    double x = x0;

    printf("iter: x0 = %f\n", x0);


    do {
        x0 = x;
        x = exp(-x0) + 0.5 / (2 * sqrt(fabs(x0)));

        it++;
    } while (fabs(x-x0) > EPS); // ?????

    printf("M4:cout iterations = %d, X = %lf\n", it, x);
    return x;
}*/
int main() {
    double a = -1.0, b = 1.0, h = 0.05;
    double x = a, fx_prev = f(a);
    printf("Tablica znachenii:\n");

    for (double xx = a; xx <= b; xx += h) {
        double result = f(xx);
        printf("x = %.2f, y = %.6f\n", xx, result);

        // Проверка на корень уравнения
        if (fabs(result) < 0.09) {
            
            printf("X-border = %.2f\n", xx);

            //return 0;
        }
    }
    while (x < b) {
        x += h;
        double fx = f(x);

        if (fx * fx_prev < 0) {
            printf("[%lf, %lf]:\n", x - h, x);
            bisection(x - h, x);
            hords(x - h, x);
            /**kasat((x - h + x) / 2.0);
            iterative((x - h + x) / 2.0);*/
        }

        fx_prev = fx;
    }

}
